//
// Created by khamza on 22.12.2019.
//
#pragma once

#include <fstream>
#include "../includes/Includes.h"


class Compare{

public:
    int numOfLines(std::ifstream& file);
    float percentage(int equalLines, int allLines);
    float simpleCompare(const std::string &FilePath1, const std::string &FilePath2);
    void deleteEmptyLines(const std::string &FilePath);
};
