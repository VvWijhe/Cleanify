//
// Created by raymon on 2-5-17.
//

#include "roomba_algorithm.h"

using namespace algorithm;

systemcontrol::RoombaControl::parameters Clean::calculate(systemcontrol::RoombaControl::parameters p, double dt) {
    switch (currentState) {
        case S_START:
            currentState = S_SPIRAL;
            break;
        case S_SPIRAL:
            if(/*bumped*/ 1) {
                currentState = S_DRIVE_BACKWARDS;
                eventOut = E_HIT_OBJECT;
            }
            else {
                //set roomba parameters
            }
            break;

        case S_DRIVE_BACKWARDS:
            currentState = S_ROTATE_LEFT;
            //eventOut = E_BACKWARDS_DONE;
            break;

        case S_ROTATE_LEFT:
            currentState = S_DRIVE_STRAIGT;
            //eventOut = E_ROTATE_DONE;
            break;

        case S_FOLLOW_WALL:
            if(/*bumped*/ ) {
                currentState = S_DRIVE_BACKWARDS;
                eventOut = E_HIT_OBJECT;
            }
            else if( /*time exceeded*/ ){

            }
            else{
                //set roomba parameters
            }
            break;

        case S_BIG_ROTATE_LEFT:

        case S_DRIVE_STRAIGT:
            // if hit wall
            currentState = S_FOLLOW_WALL;
            //if time exceeded
            currentState = S_SPIRAL;
            break;

        default:
            //return eventOut;
            break;
        case S_NO:break;
    }
}
