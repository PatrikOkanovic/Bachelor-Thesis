#include "ECF/ECF_base.h"
#include "MsaGenotype.h"
#include "MsaGenotypeMut.h"

namespace MsaGenotype
{

    void MsaGenotypeMut::registerParameters(StateP state)
    {
        myGenotype_->registerParameter(state, "mut.simple", (voidP) new double(0), ECF::DOUBLE);
    }

    bool MsaGenotypeMut::initialize(StateP state)
    {
        voidP sptr = myGenotype_->getParameterValue(state, "mut.simple");

        probability_ = *((double*)sptr.get());

        return true;
    }

    bool MsaGenotypeMut::mutate(GenotypeP gene)
    {
        MsaGenotype* msa_alignment = (MsaGenotype*) (gene.get());
        int first_position = state_->getRandomizer()->getRandomInteger(msa_alignment->getAlignment().size());
        int second_position = state_->getRandomizer()->getRandomInteger(msa_alignment->getAlignment().size());

        std::vector<std::string> &alignment = msa_alignment->getAlignment();
        for (int i = 0; i < alignment.size(); i++)
        {
            if(state_->getRandomizer()->getRandomInteger(2))
                std::swap(alignment[i][first_position], alignment[i][second_position]);
        }

        return true;
    }
}