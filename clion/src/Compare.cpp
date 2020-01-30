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
