#include "../headers/removeDuplicates.h"
float removeDuplicates::compare(const std::string &FilePath1, const std::string &FilePath2) {
    std::ifstream file1;
    readFile(FilePath1, file1);
    std::ifstream file2;
    readFile(FilePath2, file2);
    deleteEmptyLines(FilePath1); deleteEmptyLines(FilePath2);
    int numOfLinesFile1 = numOfLines(file1);
    std::vector<std::string> linesFile1;
    int numOfLinesFile2 = numOfLines(file2);
    std::vector<std::string> linesFile2;
    std::string temp; //temporary string to use in getline function
    for(int i = 0; i< numOfLinesFile1; i++){
        getline(file1,temp);
        linesFile1.push_back(temp);
    }
    for(int i = 0; i< numOfLinesFile2; i++){
        getline(file2,temp);
        linesFile2.push_back(temp);
    }
    std::sort(linesFile1.begin(), linesFile1.end());
    std::sort(linesFile2.begin(), linesFile2.end());
    linesFile1.erase( unique( linesFile1.begin(), linesFile1.end() ), linesFile1.end() ); //removing duplicate lines
    linesFile2.erase( unique( linesFile2.begin(), linesFile2.end() ), linesFile2.end() );
    float counter = 0;
    for(const auto & i : linesFile1){
        for(const auto & j : linesFile2){
            if(i == j)
                counter++;
        }
    }
    return percentage(counter, linesFile2.size());
}
