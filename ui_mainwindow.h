/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Wed Apr 29 12:07:31 2009
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
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionGenerate_Databaase;
    QAction *actionGenerage_Database;
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
    QListView *historyListView;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(611, 344);
        actionGenerate_Databaase = new QAction(MainWindowClass);
        actionGenerate_Databaase->setObjectName(QString::fromUtf8("actionGenerate_Databaase"));
        actionGenerage_Database = new QAction(MainWindowClass);
        actionGenerage_Database->setObjectName(QString::fromUtf8("actionGenerage_Database"));
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
        menuBar->setGeometry(QRect(0, 0, 611, 26));
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

        historyListView = new QListView(dockWidgetContents);
        historyListView->setObjectName(QString::fromUtf8("historyListView"));
        historyListView->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(historyListView, 1, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents);
        MainWindowClass->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget);

        menuBar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionGenerage_Database);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionGenerate_Databaase->setText(QApplication::translate("MainWindowClass", "Generate Databaase", 0, QApplication::UnicodeUTF8));
        actionGenerage_Database->setText(QApplication::translate("MainWindowClass", "Generage Database", 0, QApplication::UnicodeUTF8));
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
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
