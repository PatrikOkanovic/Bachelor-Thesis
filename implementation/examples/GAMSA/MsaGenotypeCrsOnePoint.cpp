#include "ECF/ECF_base.h"
#include "MsaGenotype.h"
#include "FastaParser.h"

namespace MsaGenotype
{

    void MsaGenotypeCrsOnePoint::registerParameters(StateP state)
    {
        myGenotype_->registerParameter(state, "crx.onepoint", (voidP) new double(0), ECF::DOUBLE);
    }

    bool MsaGenotypeCrsOnePoint::initialize(StateP state)
    {
        voidP sptr = myGenotype_->getParameterValue(state, "crx.onepoint");
        probability_ = *((double*)sptr.get());

        return true;
    }


    bool MsaGenotypeCrsOnePoint::mate(GenotypeP gen1, GenotypeP gen2, GenotypeP child)
    {
        MsaGenotype *p1 = (MsaGenotype *) (gen1.get());
        MsaGenotype *p2 = (MsaGenotype *) (gen2.get());
        MsaGenotype *ch = (MsaGenotype *) (child.get());

        int cross_point;
        int first_parent = 0;

        while(true) {
            cross_point = state_->getRandomizer()->getRandomInteger(std::min(p1->alignment[0].size(), p2->alignment[0].size()));
            first_parent = state_->getRandomizer()->getRandomInteger(0, 1);
            if (p2->alignment[0].size() >= FastaParser::n)
                break;

            if(p1->alignment[0].size() >= FastaParser::n)
                break;

        }


        switch (first_parent) {
            case 0:

                for(int i = 0; i < p1->alignment.size(); i++)
                {
                    ch->alignment[i] = p1->alignment[i].substr(0, cross_point) + p2->alignment[i].substr(cross_point);
                }
                break;
            case 1:
                for (int i = 0; i < p1->alignment.size(); i++)
                {
                    ch->alignment[i] = p2->alignment[i].substr(0, cross_point) + p1->alignment[i].substr(cross_point);
                }
        }

        std::vector<int> indexes;

        for(int i = 0; i < ch->alignment[0].size(); i++)
        {
            if (ch->alignment[0][i] == '-')
            {
                bool all_gaps = true;
                for (int j = 1; j < ch->alignment.size(); j++)
                {
                    if (ch->alignment[j][i] != '-')
                    {
                        all_gaps = false;
                        break;
                    }
                }

                if (all_gaps) indexes.push_back(i);

            }
        }

        int index_counter = 0;
        for(auto index : indexes)
        {
            for(int i = 0; i < ch->alignment.size(); i++)
            {
                ch->alignment[i].erase(ch->alignment[i].begin() + index - index_counter);
            }
            index_counter++;
        }

        return true;
    }
}