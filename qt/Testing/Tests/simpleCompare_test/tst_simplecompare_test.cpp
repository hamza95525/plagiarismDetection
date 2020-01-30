#include <QtTest>
#include "../../Utils/Includes.h"
#include "../../Utils/simpleCompare.h"

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
    std::string path="test";
    comp.readFile("test", file);
    auto num = comp.numOfLines(file);
    comp.deleteEmptyLines("test");
    QCOMPARE(comp.numOfLines(file), num-3);
}

QTEST_APPLESS_MAIN(simpleCompare_test)

#include "tst_simplecompare_test.moc"
