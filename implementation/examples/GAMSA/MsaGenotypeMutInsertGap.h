#ifndef MsaGenotypeMutInsertGap_h
#define MsaGenotypeMutInsertGap_h


#include <ECF/ECF_base.h>

namespace MsaGenotype
{

    class MsaGenotypeMutInsertGap : public MutationOp
    {

    public:
        bool mutate(GenotypeP gene);
        bool initialize(StateP);
        void registerParameters(StateP);

    };
    typedef boost::shared_ptr<MsaGenotypeMutInsertGap> MsaGenotypeMutInsertGapP;
}
#endif //MsaGenotypeMutInsertGap_h
