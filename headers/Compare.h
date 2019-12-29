//
// Created by khamza on 22.12.2019.
//
#pragma once

#include <fstream>
#include "../includes/Includes.h"


class Compare{

public:
    int numOfLines(std::ifstream& file);
    bool passLines(std::string S);
    void simpleCompare(std::ifstream& file1, std::ifstream& file2);

};
