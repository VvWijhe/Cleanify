#include "roombasim.h"
#include "ui_roombasim.h"

#include <QTimer>
#include <iostream>

using namespace std;

RoombaSim::RoombaSim(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::RoombaSim) {
   ui->setupUi(this);

   setWindowTitle("RoombaSim");

   // Create room
   _room = new Room;
   _room->setBackgroundBrush(QBrush(Qt::black));
   _room->setSceneRect(0, 0, 698, 698);

   ui->view->setScene(_room);
//   ui->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//   ui->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   ui->view->scale(1, -1);
   ui->view->setRenderHint(QPainter::Antialiasing);
   ui->view->setFixedSize(700, 700);
   ui->view->show();

   // draw grid
   for(int i = 0; i < ui->view->height(); i++) {
      _grid.push_back(new Line(0, SCALE(i), ui->view->height(), SCALE(i)));
   }

   for(int i = 0; i < ui->view->width(); i++) {
      _grid.push_back(new Line(SCALE(i), 0, SCALE(i), ui->view->width()));
   }

   for(auto grid : _grid) {
      QPen pen;
      pen.setColor(QColor("#cccdce"));
      grid->setPen(pen);
      grid->setOpacity(0.1);
      _room->addItem(grid);
   }

   // Update all objects in the room
   _updater = new QTimer;
   QObject::connect(_updater, SIGNAL(timeout()), _room, SLOT(update()));
   _updater->setInterval(ui->speedSlider->value());
}

RoombaSim::~RoombaSim() {
   delete ui;
}

void RoombaSim::on_startButton_clicked() {
    _updater->start();
}

void RoombaSim::on_pushButton_clicked() {
    _updater->stop();
}

void RoombaSim::on_speedSlider_valueChanged(int value) {
    _updater->setInterval(1000 / value);
}

void RoombaSim::on_exitButton_clicked() {
    exit(EXIT_SUCCESS);
}
