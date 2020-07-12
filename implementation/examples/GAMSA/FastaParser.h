#ifndef FUNCTIONMIN_FASTAPARSER_H
#define FUNCTIONMIN_FASTAPARSER_H

#include <vector>
#include <string>
#include <map>
#include <fstream>

class FastaParser
{
public:
    static bool initialized_fasta;
    static std::vector<std::string> dna;
    static int n;

    static void initialize(std::string file_name);

    static std::map<std::string, std::string> parse_fasta_file(std::string file_name);
};

#endif //FUNCTIONMIN_FASTAPARSER_H
