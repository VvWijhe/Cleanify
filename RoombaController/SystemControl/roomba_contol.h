//
// Created by victor on 27.03.17.
//

#ifndef ROOMBACONTROLLER_ROOMBACONTROLLER_H
#define ROOMBACONTROLLER_ROOMBACONTROLLER_H

namespace systemControl {
    class RoombaControl {

    public:
        roombacontroller(const RoombaSCI &Sci);

        void setWheels(short ls, short rs);

        void setWheels(short speed);

        void setRotation(short speed, enum direction);

        void setLed(enum color);

        void readSensors();

    private:
        RoombaSCI Sci;

    };
}




#endif //ROOMBACONTROLLER_ROOMBACONTROLLER_H
