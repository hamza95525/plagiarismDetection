//
// Created by khamza on 22.12.2019.
//
#pragma once

#include <fstream>
#include "../includes/Includes.h"


class Compare{

public:
    int linesToCompare(std::ifstream& file);
    int numOfLines(std::ifstream& file);
    float percentage(int equalLines, int allLines);
    bool passLines(std::string S);
    float comparePassingLines(std::ifstream& file1, std::ifstream& file2);
    float simpleCompare(std::ifstream& file1, std::ifstream& file2);
};
