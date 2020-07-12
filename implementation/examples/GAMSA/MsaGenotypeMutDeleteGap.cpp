#include "MsaGenotypeMutDeleteGap.h"
#include "ECF/ECF_base.h"
#include "MsaGenotype.h"
#include <iostream>

namespace MsaGenotype
{

    void MsaGenotypeMutDeleteGap::registerParameters(StateP state)
    {
        myGenotype_->registerParameter(state, "mut.delete", (voidP) new double(0), ECF::DOUBLE);
    }

    bool MsaGenotypeMutDeleteGap::initialize(StateP state)
    {
        voidP sptr = myGenotype_->getParameterValue(state, "mut.delete");

        probability_ = *((double*)sptr.get());

        return true;
    }

    // Deletes a random gap from sequence, if gap cannot be found the operation is aborted
    bool MsaGenotypeMutDeleteGap::mutate(GenotypeP gene)
    {
        MsaGenotype* msa_alignment = (MsaGenotype*) (gene.get());
        //std::vector<std::string> &alignment = msa_alignment->getAlignment();

        // check whether each sequence has a gap
        bool no_gap = false;
        for (int i = 0; i < msa_alignment->alignment.size(); i++)
        {
            if (msa_alignment->alignment[i].find('-') == std::string::npos)
            {
                no_gap = true;
                break;
            }
        }

        if (no_gap) return true;
        for (int i = 0; i < msa_alignment->alignment.size(); i++)
        {
            std::vector<int> indexes;
            int br = 0;
            for(auto& c : msa_alignment->alignment[i])
            {
                if(c == '-')
                {
                    indexes.push_back(br);
                }
                br++;
            }
            int pos = state_->getRandomizer()->getRandomInteger(indexes.size());
            msa_alignment->alignment[i].erase(msa_alignment->alignment[i].begin() + indexes[pos]);
            indexes.clear();
        }

        return true;
    }
}