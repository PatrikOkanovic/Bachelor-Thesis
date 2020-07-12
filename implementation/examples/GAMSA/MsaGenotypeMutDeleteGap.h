#ifndef MsaGenotypeMutDeleteGap_h
#define MsaGenotypeMutDeleteGap_h

#include <ECF/ECF_base.h>

namespace MsaGenotype
{

    class MsaGenotypeMutDeleteGap : public MutationOp
    {

    public:
        bool mutate(GenotypeP gene);
        bool initialize(StateP);
        void registerParameters(StateP);

    };
    typedef boost::shared_ptr<MsaGenotypeMutDeleteGap> MsaGenotypeMutDeleteGapP;
}

#endif //MsaGenotypeMutDeleteGap_h
