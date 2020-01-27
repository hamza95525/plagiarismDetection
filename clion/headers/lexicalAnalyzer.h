#include "../includes/Includes.h"

class lexicalAnalyzer : Compare
{
public:
    float compare(const std::string &FilePath1, const std::string &FilePath2) override ;
    static float compareValues(std::map<std::string, int> &mapOfKeywords1, std::map<std::string, int> &mapOfKeywords2);
};