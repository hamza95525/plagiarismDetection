//
// Created by khamza on 22.12.2019.
//
#include "../includes/Includes.h"

int Compare::numOfLines(std::ifstream& file){
    int num = 0;
    std::string temp;
    while(std::getline(file, temp)) //counting number of lines
        num++;

    file.clear();
    file.seekg(0, std::ios::beg);          //after counting number of lines, we have to set position to start of the file

    return num;
}
//==============================================================================================


void Compare::simpleCompare(std::ifstream& file1, std::ifstream& file2){
    int numOfLinesFile1 = numOfLines(file1);
    std::string tab1[numOfLinesFile1]; // creating array of string to store lines

    int numOfLinesFile2 = numOfLines(file2);
    std::string tab2[numOfLinesFile2];

    std::string temp1; //temporary string to use in getline function - first file
    std::string temp2; //second file

    for(int i = 0; i<numOfLinesFile1; i++){
        getline(file1,temp1);
        getline(file2,temp2);
        tab1[i] = temp1;
        tab2[i] = temp2;
    }

    for(int i =0; i<numOfLinesFile1; i++){
        for(int j=0; j<numOfLinesFile1;j++){
            if( tab1[i] == tab2[j] )
                std::cout<<"Lines number: "<< i+1 << " and "<< j+1 << "  are equal!\n"<<tab1[i] << "  |  " << tab2[j] << std::endl;
        }
    }
}