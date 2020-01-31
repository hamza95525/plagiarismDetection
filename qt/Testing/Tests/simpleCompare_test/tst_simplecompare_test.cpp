#include <QtTest>
#include "../../utils/Includes.h"
#include "../../utils/simpleCompare.h"

// add necessary includes here

class simpleCompare_test : public QObject
{
    Q_OBJECT
private slots:
    void deleteEmptyLines_test();
    void numOfLines_test();
    void readFile_test();
    void compare_test();
    void is_Keyword_test();
    void is_Operator_test();
    void percentage_test();
};

void simpleCompare_test::deleteEmptyLines_test()
{
    simpleCompare comp{};
    std::ifstream file;
    std::string path="/home/student/oop_2019_aplikacja_do_wykrywania_plagiatow_w_kodzie_zrodlowym/qt/Testing/Tests/simpleCompare_test/test";
    comp.readFile(path, file);
    auto num = comp.numOfLines(file);
    comp.deleteEmptyLines(path);
    QCOMPARE(comp.numOfLines(file), num);
}

void simpleCompare_test::numOfLines_test()
{
    simpleCompare comp{};
    std::ifstream file;
    std::string path="/home/student/oop_2019_aplikacja_do_wykrywania_plagiatow_w_kodzie_zrodlowym/qt/Testing/Tests/simpleCompare_test/test2";
    comp.readFile(path, file);
    auto num = comp.numOfLines(file);
    QCOMPARE(num, 19);
}

void simpleCompare_test::readFile_test()
{
    simpleCompare comp{};
    std::ifstream file;
    std::string path="/home/student/oop_2019_aplikacja_do_wykrywania_plagiatow_w_kodzie_zrodlowym/qt/Testing/Tests/simpleCompare_test/test2";
    bool success=0;
    comp.readFile(path, file);
    if(file.is_open())
        success=1;
    QCOMPARE(success,1);
}

void simpleCompare_test::compare_test()
{
    simpleCompare comp{};
    std::string path1="/home/student/oop_2019_aplikacja_do_wykrywania_plagiatow_w_kodzie_zrodlowym/qt/Testing/Tests/simpleCompare_test/test3";
    std::string path2="/home/student/oop_2019_aplikacja_do_wykrywania_plagiatow_w_kodzie_zrodlowym/qt/Testing/Tests/simpleCompare_test/test4";
    auto percentage=comp.compare(path1,path2);
    QCOMPARE(percentage,0);
}

void simpleCompare_test::is_Keyword_test()
{
    simpleCompare comp{};
    auto keyword="struct";
    QCOMPARE(comp.isKeyword(keyword),1);
}

void simpleCompare_test::is_Operator_test()
{
    simpleCompare comp{};
    auto oper="::";
    QCOMPARE(comp.isOperator(oper),1);
}

void simpleCompare_test::percentage_test()
{
    simpleCompare comp {};
    QCOMPARE(comp.percentage(1,20),5);
}

QTEST_APPLESS_MAIN(simpleCompare_test)

#include "tst_simplecompare_test.moc"
