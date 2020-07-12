#ifndef MsaEvalOp_h
#define MsaEvalOp_h

class MsaEvalOp : public EvaluateOp
{
public:
    FitnessP evaluate(IndividualP individual);

};
typedef boost::shared_ptr<MsaEvalOp> MsaEvalOpP;

#endif // MsaEvalOp_h