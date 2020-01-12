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

    bool flag = 0;

    for(int i = 0; i< 59; i++)
        if(word == keywords[i]){
            flag = 1;
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

    bool flag = 0;

    for(int i = 0; i<47; i++)
        if(word == operators[i]){
            flag = 1;
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

float Compare::simpleCompare(const std::string &FilePath1, const std::string &FilePath2) {
    std::ifstream file1;
    readFile(FilePath1, file1);
    std::ifstream file2;
    readFile(FilePath2, file2);

    deleteEmptyLines(FilePath1); deleteEmptyLines(FilePath2);

    int numOfLinesFile1 = numOfLines(file1);
    std::string tab1[numOfLinesFile1]; // creating array of string to store lines
    int numOfLinesFile2 = numOfLines(file2);
    std::string tab2[numOfLinesFile2];

    int counter = 0; //how many lines was matching

    std::string temp; //temporary string to use in getline function
    for(int i = 0; i< numOfLinesFile1; i++){
        getline(file1,temp);
        tab1[i] = temp;
    }

    for(int i = 0; i< numOfLinesFile2; i++){
        getline(file2,temp);
        tab2[i] = temp;
    }

    file1.close();
    file2.close();

    for(int i = 0; i<=numOfLinesFile2; i++){
        if ( tab1[i] == tab2[i] )
            counter++;
    }

    float P = percentage(counter, numOfLinesFile2);
    return P;
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

    int counter = 0; //how many lines was matching

    std::string temp; //temporary string to use in getline function
    for(int i = 0; i< numOfLinesFile1; i++){
        getline(file1,temp);
        tab1[i] = temp;
    }

    for(int i = 0; i< numOfLinesFile2; i++){
        getline(file2,temp);
        tab2[i] = temp;
    }

    int keywords1 = 0; int keywords2 = 0;
    int operators1 = 0; int operators2 = 0;
    for(int i=0; i<numOfLinesFile2; i++){
        std::vector<std::string> words1 = split(tab1[i]);
        std::vector<std::string> words2 = split(tab2[i]);

        for(int j=0; j<words1.size(); j++) {
            if(isKeyword(words1[j]))
                keywords1++;
            if(isOperator(words1[j]))
                operators1++;
        }

        for(int k=0; k<words2.size(); k++){
            if(isKeyword(words2[k]))
                keywords2++;
            if(isOperator(words2[k]))
                operators2++;
        }
    }

    file1.close();
    file2.close();
    int all1 = keywords1 + operators1;
    int all2 = keywords2 + operators2;

    float P = percentage(all1, all2);
    return P;
}