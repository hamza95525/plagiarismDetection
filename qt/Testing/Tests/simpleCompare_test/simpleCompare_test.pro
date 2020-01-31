QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_simplecompare_test.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../utils/release/ -lUtils
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../utils/debug/ -lUtils
else:unix: LIBS += -L$$OUT_PWD/../../utils/ -lUtils

INCLUDEPATH += $$PWD/../../utils
DEPENDPATH += $$PWD/../../utils
