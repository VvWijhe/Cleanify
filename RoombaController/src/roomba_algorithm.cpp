//
// Created by raymon on 2-5-17.
//

/*
 * Light bumper: 8 bits
 * 5 to 0 are from right to left; 6 and 7 are reserved
 *
 * setRotation(velocity, radius)
 * velocity (-500 - 500 mm/s)
 * radius(-2000 - 2000 mm)
 *
 */

#include "roomba_algorithm.h"

using namespace algorithm;

void
Clean::calculate(shared_ptr<systemcontrol::RoombaControl> control, Sensors sensorData, double dt) {
    bitset_(sensorData.getvalue(Light_bumper));
    for(int i = 0; i < 6; i++){ bitset1_[i] = bitset_[i]; }

    dt_ += dt; //timesteps = last timestep + new timestep (there are 30 timesteps per second)

    switch (currentState_) {

        case S_START:
            currentState_ = S_SPIRAL;
            control->setBrushes(100);
            break;

        case S_SPIRAL:
            if (bitset1_ != 0) {                     //hit object
                currentState_ = S_DRIVE_BACKWARDS;
            } else {
                control->setRotation(full_speed, spiral_ += dt); //drive in full speed in a spiral, getting 1mm bigger every timestep (30 mm bigger radius/s)
            }
            break;

        case S_DRIVE_BACKWARDS:
            control->setRotation(-full_speed, 32768); //drive in full speed straight backwards (300 mm/s)
            if (dt_ >= 30*1) { //for 1 sec
                dt_ = 0;
                currentState_ = S_ROTATE_LEFT;
            }
            break;

        case S_ROTATE_LEFT:
            control->setRotation(full_speed, 0x0001); //Turn in place counter-clockwise
            if (dt_ >= 30*1) { //for 1 sec
                dt_ = 0;
                currentState_ = S_FOLLOW_WALL;
            }
            break;

        case S_FOLLOW_WALL:
            if (bitset1_ != 0) { //hit object
                currentState_ = S_DRIVE_BACKWARDS;
            } else if (dt_ >= 30*30) { //time exceeded 30 sec
                dt_ = 0;
                currentState_ = S_BIG_ROTATE_LEFT;
            } else {
                control->setRotation(full_speed, 100); //Drive at full speed in a circle with a radius of 100 mm
            }
            break;

        case S_BIG_ROTATE_LEFT:
            control->setRotation(full_speed, 0x0001); //set roomba parameters
            if (dt_ >= 30*1.5) { //for 1.5 sec
                dt_ = 0;
                currentState_ = S_DRIVE_STRAIGT;
            }
            break;

        case S_DRIVE_STRAIGT:
            if (bitset1_ != 0) { //hit object
                currentState_ = S_DRIVE_BACKWARDS;
            } else if (dt_ >= 30*5) { //time exceeded 10 sec
                dt_ = 0;
                currentState_ = S_SPIRAL;
            } else {
                control->setRotation(full_speed, 0x8000); //Drive straight at full speed
            }
            break;

        default:
            break;
    }
}

/*
 * Drive in circles that increase by size. Cleans an area of 1m2.
 */
void Spot::calculate(shared_ptr<systemcontrol::RoombaControl> control, Sensors sensorData, double dt) {
    bitset1_(sensorData.getvalue(Light_bumper));
    for(int i = 0; i < 6; i++){ bitset1_[i] = bitset_[i]; }

    dt_ += dt;

    if (bitset1_ != 0 || spiral_ >= 500) { //If hit object or spiral radius > 500 mm
        control->setRotation(0, 0);
    } else {
        control->setRotation(full_speed, spiral_ += dt); //drive in full speed in a spiral, getting 1mm bigger every timestep (30 mm bigger radius/s)
    }
}

/*
 * Drive to Dock
 */
void Dock::calculate(shared_ptr<systemcontrol::RoombaControl> control, Sensors sensorData, double dt) {
    bitset1_(sensorData.getvalue(Light_bumper));
    for(int i = 0; i < 6; i++){ bitset1_[i] = bitset_[i]; }
}
