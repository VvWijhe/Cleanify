#include "mainwindow.h"
#include "ui_roombasim.h"
#include "version.h"

#include <QTimer>
#include <iostream>

using namespace std;

RoombaSim::RoombaSim(QWidget *parent) :
   QMainWindow(parent),
   ui(make_shared<Ui::RoombaSim>()) {
   ui->setupUi(this);

   setWindowTitle(WINDOW_TITLE);

   // Create room
   _room = make_shared<Room>();
   _room->setBackgroundBrush(QBrush(Qt::black));
   _room->setSceneRect(0, 0, 500, 500);

   ui->view->setScene(_room.get());
   ui->view->scale(1.2, -1.2);
   ui->view->setRenderHint(QPainter::Antialiasing);
   ui->view->setFixedSize(602, 602);
   ui->view->show();

   // draw grid
   for(int i = 0; i < ui->view->height(); i++) {
      _grid.push_back(make_shared<Line>(0, SCALE(i), ui->view->height(), SCALE(i)));
   }

   for(int i = 0; i < ui->view->width(); i++) {
      _grid.push_back(make_shared<Line>(SCALE(i), 0, SCALE(i), ui->view->width()));
   }

   for(auto grid : _grid) {
      QPen pen;
      pen.setColor(QColor("#cccdce"));
      grid->setPen(pen);
      grid->setOpacity(0.1);
      _room->addItem(grid.get());
   }

   // Update all objects in the room
   _updater = make_shared<QTimer>();
   QObject::connect(_updater.get(), SIGNAL(timeout()), _room.get(), SLOT(update()));
   _updater->setInterval(ui->speedSlider->value());
   _updater->start();

   QObject::connect(_room.get(), SIGNAL(updated()), this, SLOT(roomUpdated()));

   ui->dt->setText(QString::number(DELTA_t_sec));
   ui->statusbar->showMessage("Scale 1:100 cm");
}

RoombaSim::~RoombaSim() {
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

void RoombaSim::on_resetButton_clicked() {
    auto roomba = _room->getRoomba();
    roomba->setPos(0, 0);
    roomba->setRotation(0);
    roomba->setAngle(0);
    roomba->setSpeed(0);

    auto route = _room->getRoute();
    route->clear();
}

void RoombaSim::roomUpdated() {
   auto roomba = _room->getRoomba();
   auto posx{roomba->rect().x() + roomba->pos().x() + (roomba->rect().height() / 2)};
   auto posy{roomba->rect().y() + roomba->pos().y() + (roomba->rect().width() / 2)};

   ui->x->setText(QString::number(posx));
   ui->y->setText(QString::number(posy));
}
