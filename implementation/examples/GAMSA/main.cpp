#include "ECF/ECF.h"
#include "MsaEvalOp.h"
#include "MsaGenotype.h"
#include <string>
#include <map>
#include <vector>


int main(int argc, char **argv)
{
    StateP state(new State);

    // set the evaluation operator
    state->setEvalOp(new MsaEvalOp);

    MsaGenotypeP gen = (MsaGenotypeP) new MsaGenotype::MsaGenotype;
    state->addGenotype(gen);
    state->initialize(argc, argv);
    state->run();

    return 0;
}
