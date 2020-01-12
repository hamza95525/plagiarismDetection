//
// Created by khamza on 22.12.2019.
//
#pragma once

#include <fstream>
#include <vector>
#include "../includes/Includes.h"


class Compare{


public:
    int numOfLines(std::ifstream& file);
    float percentage(int equalLines, int allLines);
    static void readFile(const std::string &FilePath, std::ifstream &file);
    void deleteEmptyLines(const std::string &FilePath);
    std::vector<std::string> split(std::string str);
    bool isKeyword(std::string word);
    bool isOperator(std::string word);

    float simpleCompare(const std::string &FilePath1, const std::string &FilePath2); //compare strings line by line
    float removeDuplicates(const std::string &FilePath1, const std::string &FilePath2); //compare unique strings
    float basicLexicalAnalyzer(const std::string &FilePath1, const std::string &FilePath2); //compare number of keywords and operators
    float lexicalAnalyzer(const std::string &FilePath1, const std::string &FilePath2); //compare keywords and operators
};
