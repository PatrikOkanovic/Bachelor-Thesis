#ifndef MsaGenotypeCrsOnePoint_h
#define MsaGenotypeCrsOnePoint_h


namespace MsaGenotype
{

    class MsaGenotypeCrsOnePoint : public CrossoverOp
    {
    public:
        bool mate(GenotypeP gen1, GenotypeP gen2, GenotypeP child);
        bool initialize(StateP);
        void registerParameters(StateP);
    };
    typedef boost::shared_ptr<MsaGenotypeCrsOnePoint> MsaGenotypeCrsP;
}

#endif // MsaGenotypeCrsOnePoint_h