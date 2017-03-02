#ifndef ROOM_H
#define ROOM_H

#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <vector>

#include "roomba.h"

#define SCALE(meters) (meters * 35.0)

using namespace std;
using Line = QGraphicsLineItem;

class Room : public QGraphicsScene {
   Q_OBJECT
public:
   Room();

public slots:
   void update();

private:
   vector<Line *> _walls;
   Roomba *_roomba;
   int _lastRouteX, _lastRouteY;
   vector<Line *> _route;
};

#endif // ROOM_H
