/********************************************************************************
** Form generated from reading ui file 'confirm_create_database.ui'
**
** Created: Sun Mar 22 10:29:06 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CONFIRM_CREATE_DATABASE_H
#define UI_CONFIRM_CREATE_DATABASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ConfirmCreateDatabase
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConfirmCreateDatabase)
    {
        if (ConfirmCreateDatabase->objectName().isEmpty())
            ConfirmCreateDatabase->setObjectName(QString::fromUtf8("ConfirmCreateDatabase"));
        ConfirmCreateDatabase->resize(400, 87);
        gridLayout = new QGridLayout(ConfirmCreateDatabase);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ConfirmCreateDatabase);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(ConfirmCreateDatabase);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(ConfirmCreateDatabase);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfirmCreateDatabase, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfirmCreateDatabase, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConfirmCreateDatabase);
    } // setupUi

    void retranslateUi(QDialog *ConfirmCreateDatabase)
    {
        ConfirmCreateDatabase->setWindowTitle(QApplication::translate("ConfirmCreateDatabase", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConfirmCreateDatabase", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Creating the database file will take time.  Please wait.</p></body></html>", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(ConfirmCreateDatabase);
    } // retranslateUi

};

namespace Ui {
    class ConfirmCreateDatabase: public Ui_ConfirmCreateDatabase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRM_CREATE_DATABASE_H
