#ifndef ROOMBA_H
#define ROOMBA_H

#include <QGraphicsItem>
#include <vector>
#include <memory>
#include <QTimer>
#include <QObject>

#include "helper.h"
#include "serial.h"

using namespace std;

enum status_t {STANDBY, MOVING, COLLISSION, ROTATING_LEFT, ROTATING_RIGHT};

class Roomba : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
   Roomba();

   Roomba(int posx, int posy, int width, int height);

   ~Roomba() {}

   void setSpeed(short speed) {
       if(speed > 500) speed = 500;
       _speed = SCALE((double)speed / 1000.0);
   }

   double getSpeed() const { return _speed; }

   void setAngle(short angle);

   double getAngle() const { return _angle; }

   long getDistance() const { return _distance; }

   void setDistance(long distance) { _distance = distance; }

   status_t updatePos(vector<std::shared_ptr<QGraphicsLineItem>> walls);

   void readSerial();

public slots:
   void sendStream();

private:
   status_t _status;
   double _angle{};
   long _distance{};
   double _speed{};
   Serial _serial;
   QTimer timer_;
};

#endif // ROOMBA_H
