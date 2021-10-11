QT += core
QT += gui
QT += widgets

CONFIG += c++11
CONFIG += utf8_source
#ICON = log.icns
RC_ICONS = $$PWD/img/logo.ico

DESTDIR = $$PWD/bin

SOURCES += \
    PageBasic.cpp \
    PageOther.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    MainWindow.h \
    PageBasic.h \
    PageOther.h

FORMS += \
    MainWindow.ui \
    PageBasic.ui \
    PageOther.ui

RESOURCES += \
    img.qrc

