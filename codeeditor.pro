QT += widgets

HEADERS     = codeeditor.h \
    myhightlighter.h \
    matchwordsthrea.h \
    casewordlistwidget.h
SOURCES     = main.cpp \
              codeeditor.cpp \
    myhightlighter.cpp \
    matchwordsthrea.cpp \
    casewordlistwidget.cpp
# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/codeeditor
INSTALLS += target

FORMS +=
