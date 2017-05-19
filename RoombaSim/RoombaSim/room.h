#ifndef ROOM_H
#define ROOM_H

#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <vector>
#include <memory>

#include "serial.h"
#include "roomba.h"
#include "helper.h"

using namespace std;
using Line = QGraphicsLineItem;

class Room : public QGraphicsScene {
   Q_OBJECT
public:
   Room();

   ~Room() {
   }

   Roomba* getRoomba() const { return _roomba.get(); }

public slots:
   void update();

signals:
   void updated();

private:
   vector<std::shared_ptr<Line>> _walls;
   std::shared_ptr<Roomba> _roomba;
   int _lastRouteX, _lastRouteY;
   vector<std::shared_ptr<Line>> _route;
};

#endif // ROOM_H
