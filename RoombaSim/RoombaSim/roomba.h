#ifndef ROOMBA_H
#define ROOMBA_H

#include <QGraphicsItem>
#include <vector>

#define M_PI 3.14159265358979323846
#define M_2PI M_PI * 2

using namespace std;

enum status_t {STANDBY, MOVING, COLLISSION, ROTATING};

class Roomba : public QGraphicsEllipseItem {
public:
   Roomba();

   Roomba(int posx, int posy, int width, int height);

   void setAngle(double angle);

   double getAngle() const { return _angle; }

   long getDistance() const { return _distance; }

   void setDistance(long distance) { _distance = distance; }

   status_t move(vector<QGraphicsLineItem *> walls);

private:
   double _angle{};
   long _distance{};
};

#endif // ROOMBA_H
