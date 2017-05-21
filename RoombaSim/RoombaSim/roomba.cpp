#include "roomba.h"

#include <QPainter>
#include <QStyleOption>
#include <QRectF>
#include <cmath>
#include <QDebug>
#include <iostream>

Roomba::Roomba() {
   setSpanAngle((360 * 16) - 1);
   setBrush(QBrush(Qt::NoBrush));
   setPen(QPen(Qt::green));

   QRectF br = boundingRect();
   setTransformOriginPoint(br.center());

   setRect(0, 0, 1, 1);
}

Roomba::Roomba(int posx, int posy, int width, int height) {
   setSpanAngle((360 * 16) - 1);
   setBrush(QBrush(Qt::NoBrush));
   setPen(QPen(Qt::green));

   setRect(posx, posy, width, height);

   if(_serial.openPort() < 0) qDebug() << "Error opening port";
}

void Roomba::setAngle(short angle) {
   _angle = angle;
}

status_t Roomba::updatePos(vector<shared_ptr<QGraphicsLineItem>> walls) {
   // set center point
   QRectF br = boundingRect();
   setTransformOriginPoint(br.center());

//   // begin rotation
//   if(rotation() > 360) {
//      setRotation(0);
//   }
//   if(rotation() < 0) {
//      setRotation(360);
//   }

//   // rotate to the shortest angle algorithm
//   double setPoint {((_angle * 180.0) / PI)};
//   double diff {setPoint - rotation()};
//   diff = fabs((static_cast<int>(diff) + 180) % 360 - 180);

//   if(diff < 0 && !compare(setPoint, rotation(), 1.0)) {
//      setRotation(rotation() - angular_velocity * DELTA_t_sec);
//      return ROTATING_LEFT;
//   } else if(diff > 0 && !compare(setPoint, rotation(), 1.0)) {
//      setRotation(rotation() + angular_velocity * DELTA_t_sec);
//      return ROTATING_RIGHT;
//   } // end rotation

   setRotation(rotation() + _angle);

   // if the roomba is colliding, the move function returns and the roomba will not move
   for(auto wall : walls) {
      bool isColliding{};
      int maxSteps{};

      // if a collision occurs, move maxSteps backwards
      while(collidesWithItem(wall.get()) && maxSteps++ < 2) {
         setPen(QPen(Qt::red));
         setPos(pos().x() - cos((rotation() * PI) / 180.0), pos().y() - sin(((rotation() * PI) / 180.0)));
         isColliding = true;
      }

      if(isColliding) {
         return COLLISSION;
      }
   }

   setPen(QPen(Qt::green));

   // move roomba
   setPos(pos().x() + cos((rotation() * PI) / 180.0) * DELTA_t_sec * _speed,
          pos().y() + sin((rotation() * PI) / 180.0) * DELTA_t_sec * _speed);
   _distance++;

   return MOVING;
}

void Roomba::readSerial() {
    auto sequence = _serial.getBuffer();

    if(sequence.size() == 0) {
        return;
    }

    switch(static_cast<unsigned char>(sequence.at(0))) {
    case 128:
        break;

    case 137:
    {
        if(sequence.size() < 5) return;

        short speed = (unsigned char)sequence.at(1);
        speed <<= 8;
        speed |= (unsigned char)sequence.at(2);
        setSpeed(speed);

        short radius = (unsigned char)sequence.at(3);
        radius <<= 8;
        radius |= (unsigned char)sequence.at(4);

        if(radius == -1) { _angle = -7; setSpeed(0); }
        else if(radius == 1) { _angle = 7; setSpeed(0); }
        else if(radius == -32768) _angle = 0;
        else if(radius > 0) _angle = (57.2957 * DELTA_t_sec * speed) / radius;
        else if(radius < 0) _angle = (57.2957 * DELTA_t_sec * speed) / radius;

        break;
    }

    default:
        break;
    }
}
