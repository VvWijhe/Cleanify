//
// Created by raymon on 2-5-17.
//

#include "roomba_algorithm.h"
#include <bitset>

using namespace algorithm;

systemcontrol::RoombaControl::parameters
Clean::calculate(systemcontrol::RoombaControl::parameters p, double dt, Sensors &sensorData) {
    int x;
    std::bitset<8> bitset1(sensorData.getvalue<unsigned char>(Light_bumper));
    /* Light bumper: 8 bits
     * 5 to 0 are from right to left; 6 and 7 are reserved
     */
    switch (currentState_) {
        case S_START:
            currentState_ = S_SPIRAL;
            break;
        case S_SPIRAL:
            if(bitset1 != 0b00000000) {                     //hit object
                currentState_ = S_DRIVE_BACKWARDS;
                eventOut_ = E_HIT_OBJECT;
            }
            else {                                          //set roomba parameters
                p.Drive_speed = 50;
                p.Brushes_speed = 100;
                p.Drive_rotation = x;  /*@TODO add functionality to the rotation*/
            }
            break;

        case S_DRIVE_BACKWARDS:
            p.Drive_speed = -50;
            p.Brushes_speed = 100;
            p.Drive_rotation = 0;  /*@TODO add functionality to the rotation*/
            if(dt >= 1) { //drove backwards for 1 sec
                currentState_ = S_ROTATE_LEFT;
                eventOut_ = E_BACKWARDS_DONE;
            }
            break;

        case S_ROTATE_LEFT:
            p.Drive_speed = 50;
            p.Brushes_speed = 100;
            p.Drive_rotation = 0;  /*@TODO add functionality to the rotation*/
            currentState_ = S_DRIVE_STRAIGT;
            eventOut_ = E_ROTATE_DONE;
            break;

        case S_FOLLOW_WALL:
            if(bitset1 != 0b00000000) {                     //hit object
                currentState_ = S_DRIVE_BACKWARDS;
                eventOut_ = E_HIT_OBJECT;
            }
            else if(dt >= 5) {                              //time exceeded 5 sec
                currentState_ = S_BIG_ROTATE_LEFT;
                eventOut_ = E_TIME_EXCEEDED;
            }
            else {                                          //set roomba parameters
                p.Drive_speed = 50;
                p.Brushes_speed = 100;
                p.Drive_rotation = x;  /*@TODO add functionality to the rotation*/
            }
            break;

        case S_BIG_ROTATE_LEFT:
            p.Drive_speed = 50;
            p.Brushes_speed = 100;
            p.Drive_rotation = 0;  /*@TODO add functionality to the rotation*/
            currentState_ = S_DRIVE_STRAIGT;
            eventOut_ = E_ROTATE_DONE;
            break;

        case S_DRIVE_STRAIGT:
            if(bitset1 != 0b00000000) {                     //hit object
                currentState_ = S_DRIVE_BACKWARDS;
                eventOut_ = E_HIT_OBJECT;
            }
            else if(dt >= 5) {                              //time exceeded 5 sec
                currentState_ = S_SPIRAL;
                eventOut_ = E_TIME_EXCEEDED;
            }
            else {                                          //set roomba parameters
                p.Drive_speed = 50;
                p.Brushes_speed = 100;
                p.Drive_rotation = 0;  /*@TODO add functionality to the rotation*/
            }
            break;

        default:
            //return eventOut;
            break;
        case S_NO:break;
    }
}
