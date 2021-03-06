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
    DifferenceWindow d;

    QObject::connect(&w,SIGNAL(projectLabels(std::string , std::string )),&d,SLOT(setProjectLabels(std::string , std::string)));
    QObject::connect(&w,SIGNAL(filesPath(std::string , std::string )),&d,SLOT(setFileContentAndLabels(std::string , std::string)));

    d.hide();
    w.show();
    return a.exec();
}
