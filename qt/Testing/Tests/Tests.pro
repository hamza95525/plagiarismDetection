TEMPLATE = subdirs

SUBDIRS += \
    simpleCompare_test \
    removeDuplicates_test

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../utils/release/ -lUtils
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../utils/debug/ -lUtils
else:unix: LIBS += -L$$OUT_PWD/../utils/ -lUtils

INCLUDEPATH += $$PWD/../utils
DEPENDPATH += $$PWD/../utils
