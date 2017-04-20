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

enum sensor{
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

class sensors{
private:
    using sensorvariant = boost::variant<unsigned char, char, unsigned short, short>;
    map<sensor, sensorvariant> sensors_;
    vector<unsigned char> send_vector_ = {0, 0};
    Poco::Logger &logger_;
public:
    sensors();
    ~sensors() = default;
    template<typename T>
    T GetValue(sensor sens){
        if(typeid(T) == sensorvariant(sensors_.find(sens)->second).type() ){
            return boost::get<T>(sensors_.find(sens)->second);
        }
        logger_.error("BOOST ERROR sensors::GetValue: Boost has failed");
        return 0;
    }
    vector<unsigned char> CreateVector(vector<sensor> sens);
    vector<unsigned char> CreateVector(sensor sens);
    vector<unsigned char> CreateVectorStream(vector<sensor> sens);
    int ParseData(vector<unsigned char> input);
    int ChecksumCheck(vector<unsigned char> data);
};

#endif //ROOMBACONTROLLER_SENSORDATA_H
