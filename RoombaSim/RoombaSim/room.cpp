#include "room.h"
#include <iostream>
#include <random>

using namespace std;

Room::Room() {
   // Add roomba to the room
   _roomba = make_shared<Roomba>(165, 265, SCALE(0.4), SCALE(0.4));
   addItem(_roomba.get());

   // Create vector of walls
   _walls.push_back(make_shared<Line>(SCALE(2), SCALE(5), SCALE(12), SCALE(5)));
   _walls.push_back(make_shared<Line>(SCALE(2), SCALE(5), SCALE(2), SCALE(15)));
   _walls.push_back(make_shared<Line>(SCALE(2), SCALE(15), SCALE(18), SCALE(15)));
   _walls.push_back(make_shared<Line>(SCALE(18), SCALE(15), SCALE(18), SCALE(11)));
   _walls.push_back(make_shared<Line>(SCALE(18), SCALE(11), SCALE(12), SCALE(11)));
   _walls.push_back(make_shared<Line>(SCALE(12), SCALE(11), SCALE(12), SCALE(5)));

   // Add all walls to the room
   for(auto wall : _walls) {
      wall->setPen(QPen(Qt::green));
      addItem(wall.get());
   }

   // set initial path coordinates
   _lastRouteX = _roomba->rect().x() + _roomba->pos().x() + (_roomba->rect().height() / 2);
   _lastRouteY = _roomba->rect().y() + _roomba->pos().y() + (_roomba->rect().width() / 2);
}

void Room::update() {
   random_device rd;
   mt19937 rng(rd());
   uniform_int_distribution<int> uni(0, 2);
   auto rndAngle = uni(rng);
   static double rotAngle = 0.01;

   // Move roomba and pass the walls vector to the function to check if it collides with a wall
   auto roombaStatus = _roomba->move(_walls);
   switch (roombaStatus) {
      case COLLISSION:
         cout << "Collision" << endl;
         _roomba->setAngle(_roomba->getAngle() + rndAngle + 0.14);
         break;

      case MOVING:
         _roomba->setAngle(_roomba->getAngle() + rotAngle);

         if(rotAngle < 0) rotAngle = 0.01;
         rotAngle -= 0.000001;
         break;

      default:
         break;
   }

   // draw path so we can see where it drove
   if(!(_roomba->getDistance() % 20)) {
      auto posx{_roomba->rect().x() + _roomba->pos().x() + (_roomba->rect().height() / 2)};
      auto posy{_roomba->rect().y() + _roomba->pos().y() + (_roomba->rect().width() / 2)};

      // make sure the path isn't drawn at the same place as the prev one
      if(_lastRouteX == static_cast<int>(posx)) {
         return;
      }
      if(_lastRouteY == static_cast<int>(posy)) {
         return;
      }

      _route.push_back(make_shared<Line>(_lastRouteX, _lastRouteY, posx, posy));

      QPen pen;
      pen.setColor(Qt::yellow);
      pen.setWidth(10);

      _route.back()->setPen(pen);
      _route.back()->setOpacity(0.04);
      addItem(_route.back().get());

      _lastRouteX = posx;
      _lastRouteY = posy;
   }

   emit updated();
}
