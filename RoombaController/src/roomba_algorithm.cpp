
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

    auto isWall = static_cast<int>(sensorData.getvalue<unsigned char>(Wall));

    elapsedTime_ += dt; //timesteps = last timestep + new timestep (there are 30 timesteps per second)

    switch (currentState_) {

        case S_START:
            currentState_ = S_SPIRAL;
            control->setBrushes(100);
            control->setRotation(full_speed, spiral_);
            cout << "START" << endl;
            break;

        case S_SPIRAL:
            static double spiralTime;
            spiralTime += dt;

            cout << "SPIRAL: "<< endl;

            if (bumper[1] == 1 || bumper[0] == 1) {
                currentState_ = S_DRIVE_BACKWARDS;
                control->setRotation(-200, 0x8000);
                break;
            }

            if (spiralTime > 0.3) {
                spiral_ += 4;
                control->setRotation(full_speed, static_cast<int>(spiral_));
                spiralTime = 0.0;
            }

            if (spiral_ > 300.0) {
                spiral_ = 100.0;
                currentState_ = S_DRIVE_STRAIGHT;
                control->setRotation(200, 0x8000);
            }

            break;

        case S_DRIVE_BACKWARDS: {
            cout << "back" << endl;

            static double driveBackTime;
            driveBackTime += dt;

            double maxTime = 0.0;

            if (event_ == E_WALL_TURN) {
                maxTime = 0.1;
            } else {
                maxTime = 0.3;
            }

            if (driveBackTime >= maxTime) {
                driveBackTime = 0.0;
                currentState_ = S_ROTATE_LEFT;

                control->setRotation(200, 0x0001);
                break;
            }

            break;
        }

        case S_ROTATE_LEFT:
        {
            cout << "left" << endl;

            double maxTime = 0;

            if(event_ == E_WALL_TURN) {
                maxTime = 0.2;
            } else if (event_ == E_RIGHT_BUMPER) {
                maxTime = 1.5;
            } else {
                maxTime = 1.8;
            }

            if (elapsedTime_ > maxTime) { //for 1 sec
                elapsedTime_ = 0.0;

                if(event_ == E_WALL_TURN) {
                    currentState_ = S_FOLLOW_WALL;
                    control->setRotation(200, 0x8000); // to follow wall
                } else {
                    currentState_ = S_FOLLOW_OBJECT;
                    control->setRotation(160, -250); // to follow wall
                }

                break;
            }

            break;
        }

        case S_FOLLOW_OBJECT:
        {
            cout << "FO" << endl;

            static double notObjectTime;

            notObjectTime += dt;
            followTime_ += dt;

            if(notObjectTime > 4.0) {
                currentState_ = S_DRIVE_STRAIGHT;
                notObjectTime = 0.0;
                control->setRotation(200, 0x8000);
                break;
            }

            if(isWall) {
                currentState_ = S_FOLLOW_WALL;
                control->setRotation(200, -1900);
                break;
            }

            if(bumper[1] == 1) {
                event_ = E_NO;
                currentState_ = S_DRIVE_BACKWARDS;
                followAngle_ = -190;
                control->setRotation(-200, 0x8000);
                notObjectTime = 0.0;
                break;
            }

            if(bumper[0] == 1 || bumper[1] == 1) {
                event_ = E_RIGHT_BUMPER;
                currentState_ = S_DRIVE_BACKWARDS;
                followAngle_ = -190;
                notObjectTime = 0.0;
                control->setRotation(-200, 0x8000);
                break;
            }

            if (followTime_ >= 20) {
                followTime_ = 0;
                followAngle_ = -280;
                currentState_ = S_BIG_ROTATE_LEFT;
                control->setRotation(300, 0x0001);
            }
            break;
        }

        case S_FOLLOW_WALL:
            cout << "FW" << endl;

            followTime_ += dt;

            static double notWallTime;

            if(!isWall) notWallTime += dt;

            if(!isWall && notWallTime > 1.4){
                notWallTime = 0.0;
                currentState_ = S_FOLLOW_OBJECT;
                control->setRotation(150, -500);
                break;
            }

            if(bumper[0] == 1) {
                event_ = E_WALL_TURN;
                currentState_ = S_DRIVE_BACKWARDS;
                control->setRotation(-200, 0x8000);
                break;
            }

            if (bumper[1] == 1) {
                event_ = E_NO;
                currentState_ = S_DRIVE_BACKWARDS;
                control->setRotation(-200, 0x8000);
                followAngle_ = -500;
                break;
            }

            if (followTime_ >= 20) {
                followTime_ = 0;
                followAngle_ = 0x8000;
                currentState_ = S_BIG_ROTATE_LEFT;
                control->setRotation(200, 0x0001);
            }

            break;

        case S_BIG_ROTATE_LEFT:
            cout << "big left" << endl;

//            control->setRotation(full_speed, 0x0001); //Turn in place counter-clockwise
            if (elapsedTime_ >= 0.5) { //for 1.5 sec
                elapsedTime_ = 0;
                currentState_ = S_DRIVE_STRAIGHT;
                control->setRotation(200, 0x8000);
            }
            break;

        case S_DRIVE_STRAIGHT:
            cout << "straight" << endl;

            driveStraightTime_ += dt;
            if (bumper[1] == 1 || bumper[0] == 1) { //hit object
                driveStraightTime_ = 0.0;
                currentState_ = S_DRIVE_BACKWARDS;
                control->setRotation(-200, 0x8000);
                break;
            }

            if (driveStraightTime_ >= 7) { //time exceeded 10 sec
                driveStraightTime_ = 0.0;
                currentState_ = S_SPIRAL;
                control->setRotation(200, static_cast<int>(spiral_));
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
    std::bitset<8> bitset(sensorData.getvalue < unsigned
    char > (Bumps_wheeldrops));

    elapsedTime_ += dt;

    switch (currentState_) {
        case S_START:
            direction_ = !direction_;
            control->setBrushes(100);
            currentState_ = S_SPIRAL_BIGGER;
            break;

        case S_SPIRAL_BIGGER:
            if (bitset[1] != 1) {
                currentState_ = S_START;
            } else {
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
            if (bitset[1] != 1) {
                currentState_ = S_START;
            } else {
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
            control->setRotation(0, 0);
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
    std::bitset<8> bitset(sensorData.getvalue < unsigned
    char > (Bumps_wheeldrops));

}
