#include "MsaGenotypeMutInsertGap.h"
#include "ECF/ECF_base.h"
#include "MsaGenotype.h"

namespace MsaGenotype
{

    void MsaGenotypeMutInsertGap::registerParameters(StateP state)
    {
        myGenotype_->registerParameter(state, "mut.insert", (voidP) new double(0), ECF::DOUBLE);
    }

    bool MsaGenotypeMutInsertGap::initialize(StateP state)
    {
        voidP sptr = myGenotype_->getParameterValue(state, "mut.insert");

        probability_ = *((double*)sptr.get());

        return true;
    }

    // Inserts a gap in every sequence at random position
    bool MsaGenotypeMutInsertGap::mutate(GenotypeP gene)
    {
        MsaGenotype* msa_alignment = (MsaGenotype*) (gene.get());
        std::vector<std::string> &alignment = msa_alignment->getAlignment();
        for (int i = 0; i < alignment.size(); i++)
        {
            int pos = state_->getRandomizer()->getRandomInteger(alignment[i].size() + 1);
            alignment[i].insert(pos, "-");
        }

        return true;
    }
}