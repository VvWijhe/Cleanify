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

/*
 * Clean a whole room
 */
void
Clean::calculate(shared_ptr<systemcontrol::RoombaControl> control, Sensors sensorData, double dt) {
    std::bitset<8> bumper(sensorData.getvalue < unsigned char > (Bumps_wheeldrops));

    elapsedTime_ += dt; //timesteps = last timestep + new timestep (there are 30 timesteps per second)
//    std::cout << spiral_ << std::endl;
    switch (currentState_) {

        case S_START:
            currentState_ = S_SPIRAL;
            control->setBrushes(100);
            cout << "START" << endl;
            break;

        case S_SPIRAL:
            cout << "SPIRAL" << endl;
            spiral_ += 0.7;

            if(spiral_ > 200.0){
                spiral_ = 100.0;
                currentState_ = S_DRIVE_STRAIGT;
            }
            if (bumper[1] == 1 || bumper[0] == 1) {                     //hit object
                currentState_ = S_DRIVE_BACKWARDS;
            }

            control->setRotation(full_speed, static_cast<int>(spiral_)); //drive in full speed in a spiral, getting 1mm bigger every timestep (30 mm bigger radius/s)
            break;

        case S_DRIVE_BACKWARDS:
            cout << "back" << endl;

            if (elapsedTime_ >= 3) {
                elapsedTime_ = 0;
                currentState_ = S_ROTATE_LEFT;
            }

            control->setRotation(-full_speed, 0x8000); //drive in full speed straight backwards (300 mm/s)
            break;

        case S_ROTATE_LEFT:
            cout << "left" << endl;
            control->setRotation(0, 0x0001); //Turn in place counter-clockwise
            if (elapsedTime_ >= 1) { //for 1 sec
                elapsedTime_ = 0;
                currentState_ = S_FOLLOW_WALL;
            }
            break;

        case S_FOLLOW_WALL:
            cout << "FW" << endl;
            if (bumper[1] == 1 || bumper[0] == 1) { //If hit object
                currentState_ = S_DRIVE_BACKWARDS;
            } else if (elapsedTime_ >= 8) { //If time exceeded 30 sec
                elapsedTime_ = 0;
                currentState_ = S_BIG_ROTATE_LEFT;
            }

            control->setRotation(full_speed, -1500); //Drive at full speed in a circle with a radius of 100 mm

            break;

        case S_BIG_ROTATE_LEFT:
            cout << "big left" << endl;
            control->setRotation(full_speed, 0x0001); //Turn in place counter-clockwise
            if (elapsedTime_ >= 0.5) { //for 1.5 sec
                elapsedTime_ = 0;
                currentState_ = S_DRIVE_STRAIGT;
            }
            break;

        case S_DRIVE_STRAIGT:
            cout << "straight" << endl;
            driveStraightTime_ += dt;
            if (bumper[1] == 1 || bumper[0] == 1) { //hit object
                currentState_ = S_DRIVE_BACKWARDS;
            } else if (driveStraightTime_ >= 7) { //time exceeded 10 sec
                driveStraightTime_ = 0.0;
                currentState_ = S_SPIRAL;
            } else {
                control->setRotation(full_speed, 0x8000); //Drive straight at full speed
            }
            break;

        default:
            cout << "default" << endl;
            control->setBrushes(0);
            control->setRotation(0, 0);
            break;
    }
}

/*
 * Drive in circles that increase by size. Cleans an area of 1m2.
 */
void Spot::calculate(shared_ptr<systemcontrol::RoombaControl> control, Sensors sensorData, double dt) {
    std::bitset<8> bitset(sensorData.getvalue < unsigned char > (Bumps_wheeldrops));

    elapsedTime_ += dt;

    switch(currentState_) {
        case S_START:
            direction_ = !direction_;
            control->setBrushes(100);
            currentState_ = S_SPIRAL_BIGGER;
            break;

        case S_SPIRAL_BIGGER:
            if(bitset[1] != 1){
                currentState_ = S_START;
            }
            else {
                spiral_ += 0.4;

                if (spiral_ > 500.0) {
                    spiral_ = 100.0;
                    currentState_ = S_SPIRAL_SMALLER;
                }
                control->setRotation(full_speed,
                                     static_cast<int>(spiral_)); //drive in full speed in a spiral, getting 1mm bigger every timestep (30 mm bigger radius/s)
            }
            break;

        case S_SPIRAL_SMALLER:
            if(bitset[1] != 1){
                currentState_ = S_START;
            }
            else {
                spiral_ -= 0.4;
                if (spiral_ <= 0.0) {
                    spiral_ = 100.0;
                    currentState_ = S_STOP;
                }
                control->setRotation(full_speed,
                                     static_cast<int>(spiral_)); //drive in full speed in a spiral, getting 1mm bigger every timestep (30 mm bigger radius/s)
            }
            break;

        case S_STOP:
            control->setRotation(0,0);
            control->setBrushes(0);
            break;
    }

//    if (bitset != 0 || spiral_ >= 500) { //If hit object or spiral radius > 500 mm
//        control->setRotation(0, 0);
//    } else {
//        control->setRotation(full_speed, spiral_ -= dt); //drive in full speed in a spiral, getting 1mm bigger every timestep (30 mm bigger radius/s)
//    }
}

/*
 * Drive to Dock
 */
void Dock::calculate(shared_ptr<systemcontrol::RoombaControl> control, Sensors sensorData, double dt) {
    std::bitset<8> bitset(sensorData.getvalue < unsigned char > (Bumps_wheeldrops));

}