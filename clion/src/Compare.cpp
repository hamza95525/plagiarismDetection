//
// Created by khamza on 22.12.2019.
//
#include "../includes/Includes.h"
#include "../headers/Compare.h"


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

float Compare::percentage(float equalLines, int allLines) {
    float P = ( equalLines / float(allLines) ) * 100;
    if(P > 100) P = 100;
    return P;
}
//==============================================================================================
bool Compare::isKeyword(std::string word) {
    std::string keywords[58] = {
            "asm", "auto", "bool", "break", "case", "catch", "char", "const", "continue",
            "default", "delete", "do", "double", "else", "enum", "explicit", "export", "extern",
            "false", "float", "for", "friend", "goto", "if", "inline", "int", "long", "mutable",
            "namespace", "new", "operator", "private", "protected", "public", "register", "return",
            "short", "signed", "sizeof", "static", "struct", "switch", "template", "this", "throw",
            "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using", "virtual",
            "void", "volatile", "wchar_t", "while"
    };

    bool flag = false;

    for(const auto & i : keywords)
        if(word == i){
            flag = true;
            break;
        }

    return flag;
}
//==============================================================================================
bool Compare::isOperator(std::string word) {
    std::string operators[47] = {
            "::", "std::cout<<", "std::cout", "std::endl", "()", "[]", "->", ".", "-", "+", "*", "&", "!", "~", "++", "--", ".*", "->*",
            "/", "*", "%", "<<", ">>", "<", ">", "<=", ">=", "==", "!=", "&", "^", "|", "&&",
            "||", "?:", "=", "+=", "-=", "/=", "*=", "%=", "&=", "|=", "^=", "<<=", ">>=", ","
    };

    bool flag = false;

    for(const auto & i : operators)
        if(word == i){
            flag = true;
            break;
        }

    return flag;
}
//==============================================================================================
std::vector<std::string> Compare::split(std::string str) {
    std::vector<std::string> internal;
    std::stringstream ss(str);
    std::string temp;

    while(getline(ss, temp)){
        std::size_t prev = 0, pos;
        while((pos = temp.find_first_of( " ';(,*\")", prev)) != std::string::npos)
        {
            if(pos>prev)
                internal.push_back(temp.substr(prev, pos-prev));
            prev = pos + 1;
        }
        if(prev < temp.length())
            internal.push_back(temp.substr(prev, std::string::npos));
    }

    return internal;
}

//==============================================================================================
void Compare::readFile(const std::string &FilePath, std::ifstream &file) {
    file.open(FilePath);
    if( !file.is_open() ){
        std::cout<<"Error opening: "<<FilePath<<std::endl;
        return;
    }
}
//==============================================================================================

float Compare::removeDuplicates(const std::string &FilePath1, const std::string &FilePath2) {
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
//===============================================================================================

float Compare::basicLexicalAnalyzer(const std::string &FilePath1, const std::string &FilePath2) {
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
//========================================================================================


float Compare::lexicalAnalyzer(const std::string &FilePath1, const std::string &FilePath2) {
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

    for(int i = 0; i<keywords1.size(); i++){
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

    for(int i = 0; i<keywords2.size(); i++){
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

float Compare::compareValues(std::map<std::string, int> &mapOfKeywords1, std::map<std::string, int> &mapOfKeywords2) {

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
