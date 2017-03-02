#include "roomba.h"

#include <QPainter>
#include <QStyleOption>
#include <QRectF>
#include <cmath>
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
}

void Roomba::setAngle(double angle) {
   while(angle > M_2PI) {
      angle -= M_2PI;
   }
   while(angle < -M_2PI) {
      angle += M_2PI;
   }
   _angle = angle;
}

status_t Roomba::move(vector<QGraphicsLineItem *> walls) {
   // set center point
   QRectF br = boundingRect();
   setTransformOriginPoint(br.center());

   // begin rotation
   if(rotation() > 360) {
      setRotation(0);
   }
   if(rotation() < 0) {
      setRotation(360);
   }

   auto setPoint{((_angle * 180) / M_PI)};
   auto diff{setPoint - rotation()};
   diff = fabs((static_cast<int>(diff) + 180) % 360 - 180);

   if(diff < 0 && rotation() != static_cast<int>(setPoint)) {
      setRotation(rotation() - 1);
      return ROTATING;
   } else if(diff > 0 && rotation() != static_cast<int>(setPoint)) {
      setRotation(rotation() + 1);
      return ROTATING;
   } // end rotation

   // if the roomba is colliding, the move function returns and the roomba will not move
   for(auto wall : walls) {
      bool isColliding{};
      int maxSteps{};

      // if a collision occurs, move maxSteps backwards
      while(collidesWithItem(wall) && maxSteps++ < 2) {
         setPen(QPen(Qt::red));
         setPos(pos().x() - cos(_angle), pos().y() - sin(_angle));
         isColliding = true;
      }

      if(isColliding) {
         return COLLISSION;
      }
   }

   setPen(QPen(Qt::green));

   // move roomba
   setPos(pos().x() + cos(_angle), pos().y() + sin(_angle));
   _distance++;

   return MOVING;
}
