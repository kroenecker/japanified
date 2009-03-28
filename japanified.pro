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
    databasethread.cpp \
    progressbardialog.cpp \
    convert.cpp
HEADERS += mainwindow.h \
    database.h \
    edict.h \
    databasethread.h \
    progressbardialog.h \
    convert.h
FORMS += mainwindow.ui \
    confirm_create_database.ui \
    progressbar.ui
OTHER_FILES += fill_edict.rb
