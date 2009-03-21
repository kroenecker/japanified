# -------------------------------------------------
# Project created by QtCreator 2009-03-08T22:00:52
# -------------------------------------------------
QT += sql
TARGET = japanified
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    database.cpp \
    edict.cpp \
    databasethread.cpp
HEADERS += mainwindow.h \
    database.h \
    edict.h \
    databasethread.h
FORMS += mainwindow.ui
OTHER_FILES += fill_edict.rb
