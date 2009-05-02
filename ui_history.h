/********************************************************************************
** Form generated from reading ui file 'history.ui'
**
** Created: Sat May 2 23:10:46 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_HISTORY_H
#define UI_HISTORY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_HistoryDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *historyButtonBox;

    void setupUi(QDialog *HistoryDialog)
    {
        if (HistoryDialog->objectName().isEmpty())
            HistoryDialog->setObjectName(QString::fromUtf8("HistoryDialog"));
        HistoryDialog->resize(400, 98);
        gridLayout = new QGridLayout(HistoryDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(HistoryDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(HistoryDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        historyButtonBox = new QDialogButtonBox(HistoryDialog);
        historyButtonBox->setObjectName(QString::fromUtf8("historyButtonBox"));
        historyButtonBox->setOrientation(Qt::Horizontal);
        historyButtonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel);

        gridLayout->addWidget(historyButtonBox, 1, 1, 1, 1);


        retranslateUi(HistoryDialog);
        QObject::connect(historyButtonBox, SIGNAL(accepted()), HistoryDialog, SLOT(accept()));
        QObject::connect(historyButtonBox, SIGNAL(rejected()), HistoryDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(HistoryDialog);
    } // setupUi

    void retranslateUi(QDialog *HistoryDialog)
    {
        HistoryDialog->setWindowTitle(QApplication::translate("HistoryDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HistoryDialog", "Title", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(HistoryDialog);
    } // retranslateUi

};

namespace Ui {
    class HistoryDialog: public Ui_HistoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORY_H
