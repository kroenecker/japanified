/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Sun May 3 01:19:16 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionGenerateDatabase;
    QAction *actionQuit;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QLineEdit *lookupLineEdit;
    QPushButton *lookupPushButton;
    QHBoxLayout *horizontalLayout;
    QRadioButton *exactRadioButton;
    QRadioButton *beginningRadioButton;
    QRadioButton *middleRadioButton;
    QRadioButton *endRadioButton;
    QPushButton *historyPushButton;
    QTableWidget *lookupTableWidget;
    QMenuBar *menuBar;
    QMenu *menuOptions;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QComboBox *historyComboBox;
    QListView *historyListView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveHistoryPushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(611, 344);
        actionGenerateDatabase = new QAction(MainWindowClass);
        actionGenerateDatabase->setObjectName(QString::fromUtf8("actionGenerateDatabase"));
        actionQuit = new QAction(MainWindowClass);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setMargin(11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lookupLineEdit = new QLineEdit(centralWidget);
        lookupLineEdit->setObjectName(QString::fromUtf8("lookupLineEdit"));

        gridLayout_2->addWidget(lookupLineEdit, 0, 0, 1, 1);

        lookupPushButton = new QPushButton(centralWidget);
        lookupPushButton->setObjectName(QString::fromUtf8("lookupPushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lookupPushButton->sizePolicy().hasHeightForWidth());
        lookupPushButton->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(lookupPushButton, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        exactRadioButton = new QRadioButton(centralWidget);
        exactRadioButton->setObjectName(QString::fromUtf8("exactRadioButton"));
        exactRadioButton->setChecked(true);

        horizontalLayout->addWidget(exactRadioButton);

        beginningRadioButton = new QRadioButton(centralWidget);
        beginningRadioButton->setObjectName(QString::fromUtf8("beginningRadioButton"));

        horizontalLayout->addWidget(beginningRadioButton);

        middleRadioButton = new QRadioButton(centralWidget);
        middleRadioButton->setObjectName(QString::fromUtf8("middleRadioButton"));

        horizontalLayout->addWidget(middleRadioButton);

        endRadioButton = new QRadioButton(centralWidget);
        endRadioButton->setObjectName(QString::fromUtf8("endRadioButton"));

        horizontalLayout->addWidget(endRadioButton);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        historyPushButton = new QPushButton(centralWidget);
        historyPushButton->setObjectName(QString::fromUtf8("historyPushButton"));

        gridLayout_2->addWidget(historyPushButton, 1, 1, 1, 1);

        lookupTableWidget = new QTableWidget(centralWidget);
        lookupTableWidget->setObjectName(QString::fromUtf8("lookupTableWidget"));

        gridLayout_2->addWidget(lookupTableWidget, 2, 0, 1, 2);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 611, 25));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        MainWindowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindowClass);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        historyComboBox = new QComboBox(dockWidgetContents);
        historyComboBox->setObjectName(QString::fromUtf8("historyComboBox"));

        gridLayout->addWidget(historyComboBox, 1, 0, 1, 1);

        historyListView = new QListView(dockWidgetContents);
        historyListView->setObjectName(QString::fromUtf8("historyListView"));
        historyListView->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(historyListView, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        saveHistoryPushButton = new QPushButton(dockWidgetContents);
        saveHistoryPushButton->setObjectName(QString::fromUtf8("saveHistoryPushButton"));

        horizontalLayout_2->addWidget(saveHistoryPushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents);
        MainWindowClass->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget);

        menuBar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionGenerateDatabase);
        menuOptions->addAction(actionQuit);

        retranslateUi(MainWindowClass);
        QObject::connect(actionQuit, SIGNAL(activated()), MainWindowClass, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionGenerateDatabase->setText(QApplication::translate("MainWindowClass", "Generate Database", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindowClass", "Quit", 0, QApplication::UnicodeUTF8));
        lookupPushButton->setText(QApplication::translate("MainWindowClass", "Lookup", 0, QApplication::UnicodeUTF8));
        exactRadioButton->setText(QApplication::translate("MainWindowClass", "Exact", 0, QApplication::UnicodeUTF8));
        beginningRadioButton->setText(QApplication::translate("MainWindowClass", "Beginning", 0, QApplication::UnicodeUTF8));
        middleRadioButton->setText(QApplication::translate("MainWindowClass", "Middle", 0, QApplication::UnicodeUTF8));
        endRadioButton->setText(QApplication::translate("MainWindowClass", "End", 0, QApplication::UnicodeUTF8));
        historyPushButton->setText(QApplication::translate("MainWindowClass", "History", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("MainWindowClass", "Options", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindowClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">History</p></body></html>", 0, QApplication::UnicodeUTF8));
        saveHistoryPushButton->setText(QApplication::translate("MainWindowClass", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
