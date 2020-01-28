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
    MainWindow w;
    w.show();
    return a.exec();

}
