#ifndef ROOMBASIM_H
#define ROOMBASIM_H

#include <QMainWindow>

#include "room.h"

namespace Ui {
class RoombaSim;
}

class RoombaSim : public QMainWindow {
   Q_OBJECT

public:
   explicit RoombaSim(QWidget *parent = 0);
   ~RoombaSim();

private slots:
   void on_startButton_clicked();

   void on_pushButton_clicked();

   void on_speedSlider_valueChanged(int value);

   void on_exitButton_clicked();

private:
   Ui::RoombaSim *ui;
   Room *_room;
   QTimer *_updater;
   vector<Line *> _grid;
};

#endif // ROOMBASIM_H
