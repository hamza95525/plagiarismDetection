#pragma once
#include <fstream>
#include <vector>
#include <map>
#include "Includes.h"
class Compare{
public:
    friend class simpleCompare_test;
    friend class basicLexicalAnalyzer_test;
    virtual float compare(const std::string &FilePath1, const std::string &FilePath2) = 0; //method that gets overrided
    int numOfLines(std::ifstream& file);
    float percentage(float equalLines, int allLines);
    static void readFile(const std::string &FilePath, std::ifstream &file);
    void deleteEmptyLines(const std::string &FilePath);
    std::vector<std::string> split(std::string str);
    bool isKeyword(std::string word);
    bool isOperator(std::string word);
};
