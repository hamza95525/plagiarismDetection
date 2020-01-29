#include "lexicalAnalyzer.h"

float lexicalAnalyzer::compare(const std::string &FilePath1, const std::string &FilePath2) {
    std::ifstream file1;
    readFile(FilePath1, file1);

    std::ifstream file2;
    readFile(FilePath2, file2);

    deleteEmptyLines(FilePath1); deleteEmptyLines(FilePath2);
    int numOfLinesFile1 = numOfLines(file1);
    std::string tab1[numOfLinesFile1]; // creating array of string to store lines
    int numOfLinesFile2 = numOfLines(file2);
    std::string tab2[numOfLinesFile2];

    std::string temp; //temporary string to use in getline function
    for(int i = 0; i< numOfLinesFile1; i++){
        getline(file1,temp);
        tab1[i] = temp;
    }

    for(int i = 0; i< numOfLinesFile2; i++){
        getline(file2,temp);
        tab2[i] = temp;
    }

    std::vector<std::string> keywords1;
    std::vector<std::string> keywords2;
    for(int i=0; i<numOfLinesFile2; i++) {
        std::vector<std::string> words1 = split(tab1[i]); //split line i into words
        std::vector<std::string> words2 = split(tab2[i]);

        for(const auto & j : words1) {
            if(isKeyword(j))
                keywords1.push_back(j);
            if(isOperator(j))
                keywords1.push_back(j);
        }

        for(const auto & k : words2){
            if(isKeyword(k))
                keywords2.push_back(k);
            if(isOperator(k))
                keywords2.push_back(k);
        }
    }
    std::sort(keywords1.begin(), keywords1.end());
    std::sort(keywords2.begin(), keywords2.end());

    int pos = 0;    //position where the keyword would be in a map
    int count = 1; //number of keywords
    std::map<std::string, int> mapOfKeywords1; // keyword -> number of that keyword
    auto it = mapOfKeywords1.begin();

    for(unsigned long i = 0; i<keywords1.size(); i++){
        if( keywords1[pos] == keywords1[i])
            count++;
        else{
            mapOfKeywords1.insert(it, {keywords1[pos], count});
            it++;
            pos = i;
            count = 1;
        }
    }

    pos = 0; count = 1;
    std::map<std::string, int> mapOfKeywords2; // keyword -> number of that keyword
    auto itr = mapOfKeywords2.begin();

    for(unsigned long i = 0; i<keywords2.size(); i++){
        if( keywords2[pos] == keywords2[i])
            count++;
        else{
            mapOfKeywords2.insert(it, {keywords2[pos], count});
            itr++;
            pos = i;
            count = 1;
        }
    }

    float counter = compareValues(mapOfKeywords1, mapOfKeywords2);

    return percentage(counter, mapOfKeywords2.size());
}

//======================================================================================

float lexicalAnalyzer::compareValues(std::map<std::string, int> &mapOfKeywords1, std::map<std::string, int> &mapOfKeywords2) {

    float value = 0;
    for(auto & iter : mapOfKeywords1){
        for(auto & itr : mapOfKeywords2)
        {
            if( iter.first == itr.first ){
                if(iter.second > itr.second)
                    value += 1;
                else
                    value += ((float)iter.second/(float)itr.second);
            }
        }
    }

    return value;

}
