//
// Created by victor on 27.03.17.
//

#ifndef ROOMBACONTROLLER_ROOMBACONTROLLER_H
#define ROOMBACONTROLLER_ROOMBACONTROLLER_H

namespace io {
    class roombacontroller {
    public:
        void setWheels(short, short);

        void setWheels(short speed);

        void setRotation(short speed, enum direction);

        void setLed(enum color);

        void readSensors();


    private:


    };
}




#endif //ROOMBACONTROLLER_ROOMBACONTROLLER_H
