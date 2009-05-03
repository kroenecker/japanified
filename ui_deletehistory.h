/********************************************************************************
** Form generated from reading ui file 'deletehistory.ui'
**
** Created: Sun May 3 15:39:09 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DELETEHISTORY_H
#define UI_DELETEHISTORY_H

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

class Ui_DeleteHistory
{
public:
    QGridLayout *gridLayout;
    QLabel *historyTitleLabel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DeleteHistory)
    {
        if (DeleteHistory->objectName().isEmpty())
            DeleteHistory->setObjectName(QString::fromUtf8("DeleteHistory"));
        DeleteHistory->resize(400, 96);
        gridLayout = new QGridLayout(DeleteHistory);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        historyTitleLabel = new QLabel(DeleteHistory);
        historyTitleLabel->setObjectName(QString::fromUtf8("historyTitleLabel"));

        gridLayout->addWidget(historyTitleLabel, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(DeleteHistory);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(DeleteHistory);
        QObject::connect(buttonBox, SIGNAL(accepted()), DeleteHistory, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DeleteHistory, SLOT(reject()));

        QMetaObject::connectSlotsByName(DeleteHistory);
    } // setupUi

    void retranslateUi(QDialog *DeleteHistory)
    {
        DeleteHistory->setWindowTitle(QApplication::translate("DeleteHistory", "Dialog", 0, QApplication::UnicodeUTF8));
        historyTitleLabel->setText(QApplication::translate("DeleteHistory", "TextLabel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(DeleteHistory);
    } // retranslateUi

};

namespace Ui {
    class DeleteHistory: public Ui_DeleteHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEHISTORY_H
