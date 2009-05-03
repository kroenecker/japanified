#include "deletehistory.h"
#include "ui_deletehistory.h"

DeleteHistory::DeleteHistory(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::DeleteHistory)
{
    m_ui->setupUi(this);
}

DeleteHistory::~DeleteHistory()
{
    delete m_ui;
}

void DeleteHistory::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
