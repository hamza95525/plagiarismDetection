#include <QtTest>
#include "../../utils/Includes.h"
#include "../../utils/basicLexicalAnalyzer.h"

// add necessary includes here

class basicLexicalAnalyzer_test : public QObject
{
    Q_OBJECT
private slots:
    void compare_test();
};

void basicLexicalAnalyzer_test::compare_test()
{
    basicLexicalAnalyzer comp{};
    std::string path1="/home/student/oop_2019_aplikacja_do_wykrywania_plagiatow_w_kodzie_zrodlowym/qt/Testing/Tests/basicLexicalAnalyzer/test1";
    std::string path2="/home/student/oop_2019_aplikacja_do_wykrywania_plagiatow_w_kodzie_zrodlowym/qt/Testing/Tests/basicLexicalAnalyzer/test2";
    auto percentage=comp.compare(path1,path2);
    QCOMPARE(percentage,100);
}

QTEST_APPLESS_MAIN(basicLexicalAnalyzer_test)

#include "tst_basiclexicalanalyzer_test.moc"
