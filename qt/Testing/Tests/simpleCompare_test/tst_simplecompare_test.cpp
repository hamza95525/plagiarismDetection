#include <QtTest>
#include "../../utils/Includes.h"
#include "../../utils/simpleCompare.h"

// add necessary includes here

class simpleCompare_test : public QObject
{
    Q_OBJECT
private slots:
    void test_case1();

};

void simpleCompare_test::test_case1()
{
    simpleCompare comp{};
    std::ifstream file;
    std::string path="/home/student/oop_2019_aplikacja_do_wykrywania_plagiatow_w_kodzie_zrodlowym/qt/Testing/Tests/simpleCompare_test/test";
    comp.readFile(path, file);
    auto num = comp.numOfLines(file);
    comp.deleteEmptyLines(path);
    QCOMPARE(comp.numOfLines(file), num-3);
}

QTEST_APPLESS_MAIN(simpleCompare_test)

#include "tst_simplecompare_test.moc"
