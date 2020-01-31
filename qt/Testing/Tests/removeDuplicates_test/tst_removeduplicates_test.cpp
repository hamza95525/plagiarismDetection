#include <QtTest>
#include "../../utils/Includes.h"
#include "../../utils/removeDuplicates.h"

// add necessary includes here

class removeDuplicates_test : public QObject
{
    Q_OBJECT
private slots:
    void compare_test();

};

void removeDuplicates_test::compare_test()
{
    removeDuplicates comp{};
    std::string path1="/home/student/oop_2019_aplikacja_do_wykrywania_plagiatow_w_kodzie_zrodlowym/qt/Testing/Tests/removeDuplicates_test/test1";
    std::string path2="/home/student/oop_2019_aplikacja_do_wykrywania_plagiatow_w_kodzie_zrodlowym/qt/Testing/Tests/removeDuplicates_test/test2";
    auto percentage=comp.compare(path1,path2);
    QCOMPARE(percentage,25);
}

QTEST_APPLESS_MAIN(removeDuplicates_test)

#include "tst_removeduplicates_test.moc"
