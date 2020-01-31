#pragma once
#include "Includes.h"
class basicLexicalAnalyzer : Compare
{
    friend class basicLexicalAnalyzer_test;
public:
    float compare(const std::string &FilePath1, const std::string &FilePath2) override;
};
