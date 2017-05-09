//
// Created by raymon on 2-5-17.
//

#include "roomba_algorithm.h"
#include <bitset>

using namespace algorithm;

void
Clean::calculate(shared_ptr<systemcontrol::RoombaControl> control, Sensors sensorData, double dt) {
    int x;
    std::bitset<8> bitset1(sensorData.getvalue < unsigned char > (Light_bumper));
    /* Light bumper: 8 bits
     * 5 to 0 are from right to left; 6 and 7 are reserved
     */
    dt_ += dt;
    switch (currentState_) {

        case S_START:
            currentState_ = S_SPIRAL;
            break;

        case S_SPIRAL:
            if (bitset1 != 0b00000000) {                     //hit object
                currentState_ = S_DRIVE_BACKWARDS;
            } else {
                control->setRotation(full_speed, 100); //set roomba parameters
                control->setBrushes(100); /*@TODO add functionality to the rotation*/
            }
            break;

        case S_DRIVE_BACKWARDS:
            control->setRotation(-full_speed, 0x8000); //set roomba parameters
            control->setBrushes(100); /*@TODO add functionality to the rotation*/
            if (dt_ >= 1) { //drove backwards for 1 sec
                dt_ = 0;
                currentState_ = S_ROTATE_LEFT;
            }
            break;

        case S_ROTATE_LEFT:
            control->setRotation(full_speed, 0x0001); //set roomba parameters
            control->setBrushes(100); /*@TODO add functionality to the rotation*/
            currentState_ = S_FOLLOW_WALL;
            break;

        case S_FOLLOW_WALL:
            if (bitset1 != 0b00000000) {                     //hit object
                currentState_ = S_DRIVE_BACKWARDS;
            } else if (dt_ >= 5) {                              //time exceeded 5 sec
                dt_ = 0;
                currentState_ = S_BIG_ROTATE_LEFT;
            } else {                                          //set roomba parameters
                control->setRotation(full_speed, 100); //set roomba parameters
                control->setBrushes(100); /*@TODO add functionality to the rotation*/
            }
            break;

        case S_BIG_ROTATE_LEFT:
            control->setRotation(full_speed, 0x0001); //set roomba parameters
            control->setBrushes(100);  /*@TODO add functionality to the rotation*/
            currentState_ = S_DRIVE_STRAIGT;
            break;

        case S_DRIVE_STRAIGT:
            if (bitset1 != 0b00000000) {                     //hit object
                currentState_ = S_DRIVE_BACKWARDS;
            } else if (dt_ >= 5) {                              //time exceeded 5 sec
                dt_ = 0;
                currentState_ = S_SPIRAL;
            } else {                                          //set roomba parameters
                control->setRotation(full_speed, 0x8000); //set roomba parameters
                control->setBrushes(100); /*@TODO add functionality to the rotation*/
            }
            break;

        default:
            break;
    }
}

void Spot::calculate(shared_ptr<systemcontrol::RoombaControl> control, Sensors sensorData, double dt) {

}

void Dock::calculate(shared_ptr<systemcontrol::RoombaControl> control, Sensors sensorData, double dt) {
 //test
}
