QT += widgets

HEADERS     = codeeditor.h \
    myhightlighter.h \
    casewordhintwidget.h \
    matchwordsthrea.h
SOURCES     = main.cpp \
              codeeditor.cpp \
    myhightlighter.cpp \
    casewordhintwidget.cpp \
    matchwordsthrea.cpp
# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/codeeditor
INSTALLS += target

FORMS += \
    casewordhintwidget.ui
