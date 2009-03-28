#include <QtGui/QApplication>
#include <QList>
#include "mainwindow.h"

#include "database.h"
#include "databasethread.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
