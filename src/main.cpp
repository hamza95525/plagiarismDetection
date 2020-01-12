//
// Created by khamza on 22.12.2019.
//
#include "../includes/Includes.h"

int main(int argc, char* argv[]) {

    if( argc < 2 ) {
        perror("Wrong number of parameters!\n");
        return -1;
    }

    Compare s{};

    float res = s.simpleCompare(argv[1], argv[2]);
    float resRL = s.removeDuplicates(argv[1], argv[2]);
    float resAn = s.basicLexicalAnalyzer(argv[1], argv[2]);
    float resLA = s.lexicalAnalyzer(argv[1], argv[2]);
    std::cout<<"Percentage of repetition(without passing commonly used words): " << res << "%\n";
    std::cout<<"Percentage of repetition(removing duplicates): " << resRL << "%\n";
    std::cout<<"Percentage of repetition(basic lexical analyzer): " << resAn << "%\n";
    std::cout<<"Percentage of repetition(lexical analyzer): " << resLA << "%\n";

    return 0;
}
