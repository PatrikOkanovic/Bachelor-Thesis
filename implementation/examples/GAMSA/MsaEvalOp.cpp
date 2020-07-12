#include "ECF/ECF.h"
#include "MsaEvalOp.h"
#include <vector>
#include <string>
#include "MsaGenotype.h"
#include "FastaParser.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int match = 1;
int mis_match = -1;
int gaps = -2;

// evaluate() receives a smart pointer to the individual to evaluate
FitnessP MsaEvalOp::evaluate(IndividualP individual)
{
    srand( (unsigned)time(NULL) );
    // evaluation creates a new fitness object using a smart pointer
    // strategy called "Sum-Of-Pair" is used
    FitnessP fitness(new FitnessMax);

    // Each individual is a vector of genotypes (defined in the configuration file).
    // MsaGenotype will only be used
    MsaGenotype::MsaGenotype* msagen = (MsaGenotype::MsaGenotype*) individual->getGenotype().get();

    std::vector<std::string> alignment = msagen->getAlignment();

    int sum = 0;
    int num_of_columns = alignment[0].size();
    int num_of_sequences = alignment.size();
    for (int column = 0; column < num_of_columns; column++)
    {
        for (int i = 0; i < alignment.size() - 1; i++)
        {
            std::string current_sequence = alignment[i];
            if (current_sequence[column] == '-')
            {
                sum += (num_of_sequences - i - 1) * gaps;
                continue;
            }
            for (int j = i+1; j < alignment.size(); j++)
            {
                if (current_sequence[column] == alignment[j][column])
                    sum += match;
                else if (alignment[j][column] == '-')
                    sum += gaps;
                else
                    sum += mis_match;
            }
        }
    }
    int br = 0;
    std::vector<std::string> initial_alignment;
    for(auto& seq : FastaParser::dna) {
        initial_alignment.push_back(seq);
        int size = seq.size();
        for(int i = 0; i < FastaParser::n - size; i++) {
            int pos = rand() % initial_alignment[br].size() ;
            initial_alignment[br].insert(pos, "-");
        }
        br++;
    }

    int len = std::min(alignment[0].size(), initial_alignment[0].size());
    int sum2 = 0;
    for(int i = 0; i < alignment.size(); i++)
    {
        for(int j = 0; j < len; j++)
        {
            if (alignment[i][j] == initial_alignment[i][j])
                sum2++;
        }
    }


    fitness->setValue(sum);

    // return the smart pointer to new fitness
    return fitness;
}