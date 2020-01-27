#include "../headers/basicLexicalAnalyzer.h"

float basicLexicalAnalyzer::compare(const std::string &FilePath1, const std::string &FilePath2) {
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

    int keywordsAndOperators1 = 0; int keywordsAndOperators2 = 0;
    for(int i=0; i<numOfLinesFile2; i++){
        std::vector<std::string> words1 = split(tab1[i]); //vector of words after spliting the line
        std::vector<std::string> words2 = split(tab2[i]);

        for(const auto & j : words1) {
            if(isKeyword(j)) //tak wiem ze warunki tego rodzaju mozna polaczyc w jeden, ale std::bad_alloc mi na to nie pozwala
                keywordsAndOperators1++;
            if(isOperator(j))
                keywordsAndOperators1++;
        }

        for(const auto & k : words2){
            if(isKeyword(k))
                keywordsAndOperators2++;
            if(isOperator(k))
                keywordsAndOperators2++;
        }
    }

    file1.close();
    file2.close();

    return percentage(keywordsAndOperators1 , keywordsAndOperators2 );
}