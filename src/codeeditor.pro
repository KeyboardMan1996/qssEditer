QT += widgets
QT += sql
QT += core gui
QT += network

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/codeeditor
INSTALLS += target



RESOURCES += \
    qui/qr.qrc

RC_ICONS = logo.ico

DISTFILES += \
    qui/images/titile.png \
    qui/images/titile.png

FORMS += \
    mainwindow.ui \
    qui/codeEditUI.ui \
    qui/contentui.ui \
    qui/docmentui.ui \
    qui/insertui.ui \
    qui/listwidgetui.ui \
    qui/mainui.ui \
    qui/primaryfaceui.ui \
    qui/setconstui.ui

HEADERS += \
    mainwindow.h \
    config/setting.h \
    config/versionsmanager.h \
    dataBase/database.h \
    codeEdit/casewordlistwidget.h \
    codeEdit/codeeditor.h \
    codeEdit/matchwordsthrea.h \
    codeEdit/myhightlighter.h \
    qui/codeEditUI.h \
    qui/contentui.h \
    qui/docmentui.h \
    qui/insertui.h \
    qui/listwidgetui.h \
    qui/mainui.h \
    qui/primaryfaceui.h \
    qui/setconstui.h \
    qui/updataui.h

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    config/setting.cpp \
    config/versionsmanager.cpp \
    dataBase/database.cpp \
    codeEdit/casewordlistwidget.cpp \
    codeEdit/codeeditor.cpp \
    codeEdit/matchwordsthrea.cpp \
    codeEdit/myhightlighter.cpp \
    qui/codeEditUI.cpp \
    qui/contentui.cpp \
    qui/docmentui.cpp \
    qui/insertui.cpp \
    qui/listwidgetui.cpp \
    qui/mainui.cpp \
    qui/primaryfaceui.cpp \
    qui/setconstui.cpp \
    qui/updataui.cpp
