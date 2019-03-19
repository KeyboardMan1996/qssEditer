QT += widgets
QT += sql
QT += core gui
HEADERS     = codeeditor.h \
    myhightlighter.h \
    matchwordsthrea.h \
    casewordlistwidget.h \
    qui/contentui.h \
    qui/mainui.h \
    qui/setconstui.h \
    setting.h \
    listwidgetui.h \
    database.h \
    qui/codeeditui.h \
    docmentui.h \
    insertui.h \
    updataui.h
SOURCES     = main.cpp \
              codeeditor.cpp \
    myhightlighter.cpp \
    matchwordsthrea.cpp \
    casewordlistwidget.cpp \
    qui/contentui.cpp \
    qui/mainui.cpp \
    qui/setconstui.cpp \
    setting.cpp \
    listwidgetui.cpp \
    database.cpp \
    qui/codeeditui.cpp \
    docmentui.cpp \
    insertui.cpp \
    updataui.cpp
# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/codeeditor
INSTALLS += target

FORMS += \
    qui/contentui.ui \
    qui/mainui.ui \
    qui/setconstui.ui \
    listwidgetui.ui \
    qui/codeeditui.ui \
    docmentui.ui \
    insertui.ui

RESOURCES += \
    qui/qr.qrc

RC_ICONS = logo.ico

DISTFILES += \
    qui/images/titile.png \
    qui/images/titile.png
