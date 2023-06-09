QT       += core gui
QT += multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Character.cpp \
    Command.cpp \
    CommandWords.cpp \
    Escape.cpp \
    Parser.cpp \
    Room.cpp \
    ZorkUL.cpp \
    item.cpp \
    key.cpp \
    main.cpp \
    mainwindow.cpp \
    toEscape.cpp

HEADERS += \
    Character.h \
    Command.h \
    CommandWords.h \
    Escape.h \
    Parser.h \
    Room.h \
    ZorkUL.h \
    item.h \
    key.h \
    mainwindow.h \
    toEscape.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
