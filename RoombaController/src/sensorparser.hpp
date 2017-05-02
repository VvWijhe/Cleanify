//
// Created by jamie on 3/28/17.
//

#ifndef ROOMBACONTROLLER_SENSORDATA_H
#define ROOMBACONTROLLER_SENSORDATA_H


#include <iostream>
#include <vector>
#include <boost/variant.hpp>
#include <map>
#include <Poco/Logger.h>

using namespace std;

enum sensorID{
    Bumps_wheeldrops        = 7,
    Wall                    = 8,
    Cliff_left              = 9,
    Cliff_front_left        = 10,
    Cliff_front_right       = 11,
    Cliff_right             = 12,
    Virtual_wall            = 13,
    Overcurrents            = 14,
    Dirt_detect             = 15,
    Unused_1                = 16,
    Ir_opcode               = 17,
    Buttons                 = 18,
    Distance                = 19,
    Angle                   = 20,
    Charging_state          = 21,
    Voltage                 = 22,
    Current                 = 23,
    Temperature             = 24,
    Battery_charge          = 25,
    Battery_capacity        = 26,
    Wall_signal             = 27,
    Cliff_left_signal       = 28,
    Cliff_front_left_signal = 29,
    Cliff_front_right_signal= 30,
    Cliff_right_signal      = 31,
    Unused_2                = 32,
    Unused_3                = 33,
    Charger_available       = 34,
    Open_interface_mode     = 35,
    Song_number             = 36,
    Song_playing            = 37,
    stream_num_packets      = 38,
    Velocity                = 39,
    Radius                  = 40,
    Velocity_right          = 41,
    Velocity_left           = 42,
    Encoder_counts_left     = 43,
    Encoder_counts_right    = 44,
    Light_bumper            = 45,
    Light_bump_left         = 46,
    Light_bump_front_left   = 47,
    Light_bump_center_left  = 48,
    Light_bump_center_right = 49,
    Light_bump_front_right  = 50,
    Light_bump_right        = 51,
    Ir_opcode_left          = 52,
    Ir_opcode_right         = 53,
    Left_motor_current      = 54,
    Right_Motor_current     = 55,
    Main_brush_current      = 56,
    Side_brush_current      = 57,
    Statis                  = 58
};

class Sensors{
public:

    /**
     * @brief all sensors are added to the vector "sensors_"
     */
    Sensors();

    ~Sensors(){};

    /**
     * @brief Search and returns value of sensor in sensor vector.
     * @tparam T represents the datatype of the requested data
     * @param Sensor is the sensorID of the data you requested
     * @return 0 if failed, value of sensor on succes.
     */
    template<typename T>
    T getvalue(sensorID sensor){
        if(typeid(T) == sensorvariant(sensors_.find(sensor)->second).type() ){
            return boost::get<T>(sensors_.find(sensor)->second);
        }
        logger_.error("BOOST ERROR sensors::GetValue: Boost has failed");
        return 0;
    }

    /**
     * @brief Create a vector to request sensordata of multiple sensors from the roomba.
     * @param sensors is a vector of sensors where you want to know the value.
     * @return A vector to request data of multiple sensors, with usage of opcode 149
     */
    vector<unsigned char> createvector(vector<sensorID> sensors);

    /**
     * @brief Create a vector to request sensordata of one sensor from the roomba.
     * @param sensor is the sensor where you want to know the value.
     * @return A vector to request data of one sensor, with usage of opcode 142
     */
    vector<unsigned char> createvector(sensorID sensor);

    /**
     * @brief Create a vector to request sensordata of multiple sensors from the roomba.
     *        the data requested will be returned every 15ms.
     * @param sensors is a vector of sensors where you want to know the value.
     * @return A vector to request data of multiple sensors, with usage of opcode 148
     */
    vector<unsigned char> createvectorstream(vector<sensorID> sensors);

    /**
     * @brief this function will parse the incomming data and update the sensor value's.
     * @param input is a char vector of the received data from the roomba.
     * @return 1 if succesfull, -1 when first byte isn't equal to 19, -2 when checksum error.
     */
    int parsedata(vector<unsigned char> input);

    /**
     * @brief will check if the som of al bytes is equal to 0.
     * @param data is the vector of data you want to check
     * @return 1 when succes, -1 when failed.
     */
    int checksumcheck(vector<unsigned char> data);

private:
    using sensorvariant = boost::variant<unsigned char, char, unsigned short, short>;

    map<sensorID, sensorvariant> sensors_;

    Poco::Logger &logger_;
};

#endif //ROOMBACONTROLLER_SENSORDATA_H
