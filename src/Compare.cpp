//
// Created by khamza on 22.12.2019.
//
#include "../includes/Includes.h"

int Compare::numOfLines(std::ifstream& file){
    int num = 0;
    std::string temp;
    while(std::getline(file, temp)) { //counting number of all lines
        if ( temp.length() != 0)
            num++;
    }
    file.clear();
    file.seekg(0, std::ios::beg);          //after counting number of lines, we have to set position to start of the file

    return num;
}
//==============================================================================================

int Compare::linesToCompare(std::ifstream &file) {
    int num = 0;
    std::string temp;
    while (std::getline(file, temp)) {
        if (!passLines(temp) && temp.length() != 0)
            num++;
    }

    file.clear();
    file.seekg(0, std::ios::beg);

    return num;
}
//==============================================================================================

float Compare::percentage(int equalLines, int allLines) {
    float P = ( float(equalLines) / float(allLines) ) * 100;
    return P;
}
//==============================================================================================

float Compare::comparePassingLines(std::ifstream& file1, std::ifstream& file2){
    int numOfLinesFile1 = linesToCompare(file1);
    std::string tab1[numOfLinesFile1]; // creating array of string to store lines

    int numOfLinesFile2 = linesToCompare(file2);
    std::string tab2[numOfLinesFile2];

    int counter = 0; //how many lines was matching

    std::string temp1; //temporary string to use in getline function - first file
    std::string temp2; //second file

    for(int i = 0; i<numOfLinesFile1; i++){
        getline(file1,temp1);
        getline(file2,temp2);
        if( temp1.length() != 0)
            tab1[i] = temp1;

        if( temp2.length() !=0 )
            tab2[i] = temp2;
    }

    file1.clear();
    file1.seekg(0, std::ios::beg);

    file2.clear();
    file2.seekg(0, std::ios::beg);

    for(int i =0; i<numOfLinesFile1; i++){
        for(int j=0; j<numOfLinesFile2;j++){
            if( tab1[i] == tab2[j] ) {
                counter++;
            }
        }
    }

    float P = percentage(counter, numOfLinesFile2);
    return counter;
}
//===============================================================================================
float Compare::simpleCompare(std::ifstream &file1, std::ifstream &file2) {
    int numOfLinesFile1 = numOfLines(file1);
    std::string tab1[numOfLinesFile1]; // creating array of string to store lines

    int numOfLinesFile2 = numOfLines(file2);
    std::string tab2[numOfLinesFile2];

    int counter = 0; //how many lines was matching

    std::string temp1; //temporary string to use in getline function - first file
    std::string temp2; //second file

    for(int i = 0; i<numOfLinesFile1; i++){
        getline(file1,temp1);
        getline(file2,temp2);

        if( temp1.length() != 0)
            tab1[i] = temp1;

        if( temp2.length() != 0)
            tab2[i] = temp2;
    }

    file1.clear();
    file1.seekg(0, std::ios::beg);

    file2.clear();
    file2.seekg(0, std::ios::beg);

    for(int i =0; i<numOfLinesFile1; i++){
        for(int j=0; j<numOfLinesFile2;j++){
            if( tab1[i] == tab2[j] ) {
                counter++;
            }
        }
    }

    float P = percentage(counter, numOfLinesFile2);
    return P;
}

//===============================================================================================
bool Compare::passLines(std::string S) {
    std::string words[] = { "#include", "switch", "main", "return", "using namespace"}; //words that almost every cplusplus code has

    for( const auto & word : words ){
        if( S.find(word) != std::string::npos || S == "{" || S == "}" )       //if word is found in string or string is empty then true is returned
            return true;
    }

    return false;
}