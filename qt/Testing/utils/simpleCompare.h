#pragma once
#include "Includes.h"
class UTILSSHARED_EXPORT simpleCompare : Compare
{
    friend class simpleCompare_test;
private:
    int Size = 0;
public:
    float compare(const std::string &FilePath1, const std::string &FilePath2) override; //compare strings line by line
};
