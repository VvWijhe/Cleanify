#ifndef ROOM_H
#define ROOM_H

#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <vector>

#include "roomba.h"

using namespace std;
using Wall = QGraphicsLineItem;
using route = QGraphicsLineItem;

class Room : public QGraphicsScene {
   Q_OBJECT
public:
   Room();

public slots:
   void update();

private:
   vector<Wall *> _walls;
   Roomba *_roomba;
   int _lastRouteX, _lastRouteY;
   vector<route *> _route;
};

#endif // ROOM_H
