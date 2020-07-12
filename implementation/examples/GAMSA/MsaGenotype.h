#ifndef MsaGenotype_h
#define MsaGenotype_h

#include "./ECF/Genotype.h"
#include "MsaGenotypeMut.h"
#include "MsaGenotypeCrsOnePoint.h"
#include "MsaGenotypeMutDeleteGap.h"
#include "MsaGenotypeMutInsertGap.h"
#include "FastaParser.h"
#include <vector>
#include <string>
#include <map>

namespace MsaGenotype
{

    class MsaGenotype : public Genotype
    {

    public:
        // contains an alignment of sequences
        std::vector<std::string> alignment;


        MsaGenotype()
        {
            name_ = "MsaGenotype";
        }

        void registerParameters(StateP state)
        {
            state->getRegistry()->registerEntry("input", (voidP) (new std::string), ECF::STRING);

        }

        bool initialize(StateP state)
        {

            if(!FastaParser::initialized_fasta)
            {
                std::string file_name = *((std::string*)state->getRegistry()->getEntry("input").get());
                std::cout << file_name << "\n";
                FastaParser::initialize(file_name);
            }

            int br = 0;

            for(auto& seq : FastaParser::dna) {
                alignment.push_back(seq);
                int size = seq.size();
                for(int i = 0; i < 1.1*FastaParser::n - size + 1; i++) {
                    int pos = state->getRandomizer()->getRandomInteger(alignment[br].size() + 1) ;
                    alignment[br].insert(pos, "-");
                }
                br++;
            }
            return true;

        }

        MsaGenotype* copy()
        {
            MsaGenotype* newObject = new MsaGenotype(*this);
            return newObject;
        }

        std::vector<CrossoverOpP> getCrossoverOp()
        {
            std::vector<CrossoverOpP> crx;
            crx.push_back(static_cast<CrossoverOpP> (new MsaGenotypeCrsOnePoint));
            return crx;
        }

        std::vector<MutationOpP> getMutationOp()
        {
            std::vector<MutationOpP> mut;
            mut.push_back(static_cast<MutationOpP> (new MsaGenotypeMut));
            mut.push_back(static_cast<MutationOpP>(new MsaGenotypeMutDeleteGap));
            mut.push_back(static_cast<MutationOpP>(new MsaGenotypeMutInsertGap));
            return mut;
        }

        void write(XMLNode &xMsaGenotype)
        {
            xMsaGenotype = XMLNode::createXMLTopNode("MsaGenotype");
            std::stringstream sValue;
            sValue << alignment.size();
            xMsaGenotype.addAttribute("size", sValue.str().c_str());

            sValue.str("");
            sValue << "\n";
            for (int i = 0; i < alignment.size(); i++) {
                sValue << alignment[i];
                sValue << "\n";
            }
            xMsaGenotype.addText(sValue.str().c_str());
        }

        void read(XMLNode &xMsaGenotype)
        {
            XMLCSTR values = xMsaGenotype.getText();
            std::stringstream sValues;
            sValues << values;
            for (int i = 0; i < alignment.size(); i++)
            {
                sValues >> alignment[i];
            }


        }

        std::vector<std::string> &getAlignment()
        {
            return alignment;
        }


    };

}
typedef boost::shared_ptr<MsaGenotype::MsaGenotype> MsaGenotypeP;
#endif // MsaGenotype_h