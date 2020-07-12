#ifndef MsaGenotypeMut_h
#define MsaGenotypeMut_h


namespace MsaGenotype
{

    class MsaGenotypeMut : public MutationOp
    {

    public:
        bool mutate(GenotypeP gene);
        bool initialize(StateP);
        void registerParameters(StateP);

    };
    typedef boost::shared_ptr<MsaGenotypeMut> MsaGenotypeMutP;
}

#endif // MsaGenotypeMut_h