#include <QApplication>
#include <QDesktopWidget>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
   QApplication a(argc, argv);

   RoombaSim sim;
   sim.show();

   return a.exec();
}
