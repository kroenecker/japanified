/********************************************************************************
** Form generated from reading ui file 'progressbar.ui'
**
** Created: Sun Mar 22 10:29:06 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PROGRESSBAR_H
#define UI_PROGRESSBAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_DatabaseProgressBar
{
public:
    QGridLayout *gridLayout;
    QProgressBar *progressBar;
    QLabel *label;

    void setupUi(QDialog *DatabaseProgressBar)
    {
        if (DatabaseProgressBar->objectName().isEmpty())
            DatabaseProgressBar->setObjectName(QString::fromUtf8("DatabaseProgressBar"));
        DatabaseProgressBar->setWindowModality(Qt::ApplicationModal);
        DatabaseProgressBar->resize(301, 66);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DatabaseProgressBar->sizePolicy().hasHeightForWidth());
        DatabaseProgressBar->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(DatabaseProgressBar);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        progressBar = new QProgressBar(DatabaseProgressBar);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 0, 0, 1, 1);

        label = new QLabel(DatabaseProgressBar);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);


        retranslateUi(DatabaseProgressBar);

        QMetaObject::connectSlotsByName(DatabaseProgressBar);
    } // setupUi

    void retranslateUi(QDialog *DatabaseProgressBar)
    {
        DatabaseProgressBar->setWindowTitle(QApplication::translate("DatabaseProgressBar", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DatabaseProgressBar", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans'; font-size:10pt;\">Please wait while the database is generated.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(DatabaseProgressBar);
    } // retranslateUi

};

namespace Ui {
    class DatabaseProgressBar: public Ui_DatabaseProgressBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSBAR_H
