QT += widgets

HEADERS     = codeeditor.h \
    myhightlighter.h \
    matchwordsthrea.h \
    casewordlistwidget.h \
    qui/contentui.h \
    qui/mainui.h \
    qui/mainwindow.h \
    qui/setconstui.h \
    setting.h \
    buttonui.h
SOURCES     = main.cpp \
              codeeditor.cpp \
    myhightlighter.cpp \
    matchwordsthrea.cpp \
    casewordlistwidget.cpp \
    qui/contentui.cpp \
    qui/mainui.cpp \
    qui/mainwindow.cpp \
    qui/setconstui.cpp \
    setting.cpp \
    buttonui.cpp
# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/codeeditor
INSTALLS += target

FORMS += \
    qui/contentui.ui \
    qui/mainui.ui \
    qui/mainwindow.ui \
    qui/setconstui.ui \
    buttonui.ui

RESOURCES += \
    qui/qr.qrc
