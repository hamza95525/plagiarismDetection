#pragma once

#include <fstream>
#include <vector>
#include <map>
#include "../includes/Includes.h"


class Compare{

public:

    virtual float compare(const std::string &FilePath1, const std::string &FilePath2) = 0;

    int numOfLines(std::ifstream& file);
    float percentage(float equalLines, int allLines);
    static void readFile(const std::string &FilePath, std::ifstream &file);
    void deleteEmptyLines(const std::string &FilePath);
    std::vector<std::string> split(std::string str);
    bool isKeyword(std::string word);
    bool isOperator(std::string word);

    float removeDuplicates(const std::string &FilePath1, const std::string &FilePath2); //compare unique strings
    float basicLexicalAnalyzer(const std::string &FilePath1, const std::string &FilePath2); //compare number of keywords and operators
    float lexicalAnalyzer(const std::string &FilePath1, const std::string &FilePath2); //compare keywords and operators

    float compareValues(std::map<std::string, int> &mapOfKeywords1, std::map<std::string, int> &mapOfKeywords2);

};
