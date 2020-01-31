#include "../headers/simpleCompare.h"
float simpleCompare::compare(const std::string &FilePath1, const std::string &FilePath2) //compare strings line by line
{
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
    file1.close();
    file2.close();
    float counter = 0;
    for(int i = 0; i<=linesFile2.size(); i++){
        if ( linesFile1[i] == linesFile2[i] )
            counter++;
    }
    return percentage(counter, linesFile2.size());
}
