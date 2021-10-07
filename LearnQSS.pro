QT += core
QT += gui
QT += widgets

CONFIG += c++11
CONFIG += utf8_source
#ICON = log.icns
RC_ICONS = $$PWD/img/logo.ico

DESTDIR = $$PWD/bin

SOURCES += \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    MainWindow.h

FORMS += \
    MainWindow.ui

RESOURCES += \
    img.qrc

