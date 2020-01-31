#include <QtTest>
#include "../../utils/Includes.h"
#include "../../utils/lexicalAnalyzer.h"

// add necessary includes here

class lexicalAnalyzer_test : public QObject
{
    Q_OBJECT
private slots:
    void compare_test();
};

void lexicalAnalyzer_test::compare_test()
{
    lexicalAnalyzer comp{};
    std::string path1="/home/student/oop_2019_aplikacja_do_wykrywania_plagiatow_w_kodzie_zrodlowym/qt/Testing/Tests/basicLexicalAnalyzer/test1";
    std::string path2="/home/student/oop_2019_aplikacja_do_wykrywania_plagiatow_w_kodzie_zrodlowym/qt/Testing/Tests/basicLexicalAnalyzer/test2";
    auto percentage=comp.compare(path1,path2);
    QCOMPARE(percentage,75);
}

QTEST_APPLESS_MAIN(lexicalAnalyzer_test)

#include "tst_lexicalanalyzer_test.moc"
