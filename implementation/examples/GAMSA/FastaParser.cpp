#include "FastaParser.h"
#include<iostream>

int FastaParser::n;
bool FastaParser::initialized_fasta = false;
std::vector<std::string> FastaParser::dna;

void FastaParser::initialize(std::string file_name) {
    std::map<std::string, std::string> input = parse_fasta_file(file_name);
    for(auto x : input) {
        dna.push_back(x.second);
        n = n > x.second.size() ? n : x.second.size();
    }
    initialized_fasta = true;
}

std::map<std::string, std::string> FastaParser::parse_fasta_file(std::string file_name)
{
    std::map<std::string, std::string> data;
    std::ifstream file;
    file.open(file_name);
    std::string line;
    if (file.is_open())
    {
        std::string sequence_name;
        std::string current_sequence;
        bool first = true;
        while (getline(file, line))
        {
            if (line[0] == '>')
            {
                if(!first) {
                    data[sequence_name] = current_sequence;
                    current_sequence = "";
                }
                sequence_name = line.substr(1, line.size());
            }
            else if (line[0] == ',')
            {
                continue;
            }
            else
            {
                if(first) first = false;
                current_sequence += line;
            }
        }
        data[sequence_name] = current_sequence;
        file.close();
    }
    else
    {
        throw ("Unable to read FASTA file");
    }

    return data;
}