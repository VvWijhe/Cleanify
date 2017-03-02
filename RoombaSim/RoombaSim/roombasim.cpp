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
   _room->setSceneRect(0, 0, 1278, 718);

   ui->view->setScene(_room);
   ui->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   ui->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   ui->view->scale(1, -1);
   ui->view->setRenderHint(QPainter::Antialiasing);
   ui->view->setFixedSize(1280, 720);
   ui->view->show();

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
