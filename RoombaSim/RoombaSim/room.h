#ifndef ROOM_H
#define ROOM_H

#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <vector>

#include "roomba.h"
#include "helper.h"

using namespace std;
using Line = QGraphicsLineItem;

class Room : public QGraphicsScene {
   Q_OBJECT
public:
   Room();

   ~Room() {
      // delete wall
      for(auto &wall : _walls) {
         delete wall;
      }

      // delete routes
      for(auto &route : _route) {
         delete route;
      }
   }

   Roomba* getRoomba() const { return _roomba; }

public slots:
   void update();

signals:
   void updated();

private:
   vector<Line *> _walls;
   Roomba *_roomba;
   int _lastRouteX, _lastRouteY;
   vector<Line *> _route;
};

#endif // ROOM_H
