#ifndef ROOMBASIM_H
#define ROOMBASIM_H

#include <QMainWindow>
#include <memory>

#include "room.h"

namespace Ui {
class RoombaSim;
}

class MainWindow : public QMainWindow {
   Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = 0);
   ~MainWindow();

private slots:
   void on_startButton_clicked();

   void on_pushButton_clicked();

   void on_speedSlider_valueChanged(int value);

   void on_exitButton_clicked();

   void roomUpdated();

private:
   std::shared_ptr<Ui::RoombaSim> ui;
   std::shared_ptr<Room> _room;
   std::shared_ptr<QTimer> _updater;
   vector<std::shared_ptr<Line>> _grid;
};

#endif // ROOMBASIM_H
