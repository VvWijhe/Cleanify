#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <restbed/source/restbed>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.move(QApplication::desktop()->screen()->rect().center() -
         w.rect().center());
  w.show();
  w.setWindowTitle("PC-Applicatie");
  restbed::Byte k;

  return a.exec();
}
