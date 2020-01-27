//
// Created by khamza on 22.12.2019.
//
#include "Includes.h"
#include "simpleCompare.h"
#include "removeDuplicates.h"
#include "basicLexicalAnalyzer.h"
#include "lexicalAnalyzer.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    std::cout<< "Przykladowy cout z maina\n:";
    if( argc < 2 ) {
        perror("Wrong number of parameters!\n");
        return -1;
    }

    simpleCompare s{};
    removeDuplicates r{};
    basicLexicalAnalyzer b{};
    lexicalAnalyzer l{};

    float res = s.compare(argv[1], argv[2]);
    float resRem = r.compare(argv[1], argv[2]);
    float resBasic = b.compare(argv[1], argv[2]);
    float resAnalyzer = l.compare(argv[1], argv[2]);

    std::cout<<"Percentage of repetition(without passing commonly used words): " << res << "%\n";
    std::cout<<"Percentage of repetition(removing Duplicates): " << resRem << "%\n";
    std::cout<<"Percentage of repetition(basic Lexical Analyzer): " << resBasic << "%\n";
    std::cout<<"Percentage of repetition(Lexical Analyzer): " << resAnalyzer << "%\n";

    MainWindow w;
    w.show();
    return a.exec();

}
