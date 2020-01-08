//
// Created by khamza on 22.12.2019.
//
#include "../includes/Includes.h"

void Compare::deleteEmptyLines(const std::string &FilePath)
{
    std::ifstream in(FilePath);
    std::string line, text;

    while (std::getline(in, line))
        if ( !(line.empty() || line.find_first_not_of(' ') == std::string::npos) )
            text += line + "\n";
    in.close();
    
    std::ofstream out(FilePath);
    out << text;
}
//=======================================

int Compare::numOfLines(std::ifstream& file){
    int num = 0;
    std::string temp;
    while(std::getline(file, temp)) { //counting number of all lines
            num++;
    }

    file.clear();
    file.seekg(0, std::ios::beg);          //after counting number of lines, we have to set position to start of the file

    return num;
}
//==============================================================================================

float Compare::percentage(int equalLines, int allLines) {
    float P = ( float(equalLines) / float(allLines) ) * 100;
    return P;
}
//==============================================================================================

float Compare::simpleCompare(const std::string &FilePath1, const std::string &FilePath2) {
    std::ifstream file1;
    file1.open(FilePath1);
    if( !file1.is_open() ){
        std::cout<<"Error opening: "<<FilePath1<<std::endl;
        return -1;
    }

    std::ifstream file2;
    file2.open(FilePath2);
    if( !file1.is_open() ){
        std::cout<<"Error opening: "<<FilePath2<<std::endl;
        return -1;
    }

    deleteEmptyLines(FilePath1); deleteEmptyLines(FilePath2);

    int numOfLinesFile1 = numOfLines(file1);
    std::string tab1[numOfLinesFile1]; // creating array of string to store lines

    int numOfLinesFile2 = numOfLines(file2);
    std::string tab2[numOfLinesFile2];

    int counter = 0; //how many lines was matching
    int lengthTab1 = 0; //all of the lines in the lines tab
    int lengthTab2 = 0;

    std::string temp; //temporary string to use in getline function

    for(int i = 0; i< numOfLinesFile1; i++){
        getline(file1,temp);
        tab1[i] = temp;
        lengthTab1++;
    }

    for(int i = 0; i< numOfLinesFile2; i++){
        getline(file2,temp);
        tab2[i] = temp;
        lengthTab2++;
    }

    file1.close();
    file2.close();

    for(int i = 0; i<=numOfLinesFile1; i++){
        if ( tab1[i] == tab2[i] )
            counter++;
    }

    float P = percentage(counter, lengthTab2);
    return P;
}

//===============================================================================================
