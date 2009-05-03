#ifndef DELETEHISTORY_H
#define DELETEHISTORY_H

#include <QtGui/QDialog>

namespace Ui {
    class DeleteHistory;
}

class DeleteHistory : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(DeleteHistory)
public:
    explicit DeleteHistory(QWidget *parent = 0);
    virtual ~DeleteHistory();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::DeleteHistory *m_ui;
};

#endif // DELETEHISTORY_H
