//
// Created by bas on 20-4-17.
//

#include "sensorparser.hpp"

using namespace std;

Sensors::Sensors() : logger_(Poco::Logger::get("logger")){
    sensors_[Bumps_wheeldrops]          = static_cast<unsigned char>(0);
    sensors_[Wall]                      = static_cast<unsigned char>(0);
    sensors_[Cliff_left]                = static_cast<unsigned char>(0);
    sensors_[Cliff_front_left]          = static_cast<unsigned char>(0);
    sensors_[Cliff_front_right]         = static_cast<unsigned char>(0);
    sensors_[Cliff_right]               = static_cast<unsigned char>(0);
    sensors_[Virtual_wall]              = static_cast<unsigned char>(0);
    sensors_[Overcurrents]              = static_cast<unsigned char>(0);
    sensors_[Dirt_detect]               = static_cast<char>(0);
    sensors_[Unused_1]                  = static_cast<char>(0);
    sensors_[Ir_opcode]                 = static_cast<unsigned char>(0);
    sensors_[Ir_opcode_left]            = static_cast<unsigned char>(0);
    sensors_[Ir_opcode_right]           = static_cast<unsigned char>(0);
    sensors_[Buttons]                   = static_cast<unsigned char>(0);
    sensors_[Distance]                  = static_cast<short>(0);
    sensors_[Angle]                     = static_cast<short>(0);
    sensors_[Charging_state]            = static_cast<unsigned char>(0);
    sensors_[Voltage]                   = static_cast<unsigned short>(0);
    sensors_[Current]                   = static_cast<short>(0);
    sensors_[Temperature]               = static_cast<char>(0);
    sensors_[Battery_charge]            = static_cast<unsigned short>(0);
    sensors_[Battery_capacity]          = static_cast<unsigned short>(0);
    sensors_[Wall_signal]               = static_cast<unsigned short>(0);
    sensors_[Cliff_left_signal]         = static_cast<unsigned short>(0);
    sensors_[Cliff_front_left_signal]   = static_cast<unsigned short>(0);
    sensors_[Cliff_front_right_signal]  = static_cast<unsigned short>(0);
    sensors_[Cliff_right_signal]        = static_cast<unsigned short>(0);
    sensors_[Unused_2]                  = static_cast<unsigned char>(0);
    sensors_[Unused_3]                  = static_cast<unsigned short>(0);
    sensors_[Charger_available]         = static_cast<unsigned char>(0);
    sensors_[Open_interface_mode]       = static_cast<unsigned char>(0);
    sensors_[Song_number]               = static_cast<unsigned char>(0);
    sensors_[Song_playing]              = static_cast<unsigned char>(0);
    sensors_[stream_num_packets]        = static_cast<unsigned char>(0);
    sensors_[Velocity]                  = static_cast<short>(0);
    sensors_[Radius]                    = static_cast<short>(0);
    sensors_[Velocity_right]            = static_cast<short>(0);
    sensors_[Velocity_left]             = static_cast<short>(0);
    sensors_[Encoder_counts_left]       = static_cast<unsigned short>(0);
    sensors_[Encoder_counts_right]      = static_cast<unsigned short>(0);
    sensors_[Light_bumper]              = static_cast<unsigned char>(0);
    sensors_[Light_bump_left]           = static_cast<unsigned short>(0);
    sensors_[Light_bump_front_left]     = static_cast<unsigned short>(0);
    sensors_[Light_bump_center_left]    = static_cast<unsigned short>(0);
    sensors_[Light_bump_center_right]   = static_cast<unsigned short>(0);
    sensors_[Light_bump_front_right]    = static_cast<unsigned short>(0);
    sensors_[Light_bump_right]          = static_cast<unsigned short>(0);
    sensors_[Left_motor_current]        = static_cast<short>(0);
    sensors_[Right_Motor_current]       = static_cast<short>(0);
    sensors_[Main_brush_current]        = static_cast<short>(0);
    sensors_[Side_brush_current]        = static_cast<short>(0);
    sensors_[Statis]                    = static_cast<char>(0);
}


vector<unsigned char> Sensors::createvector(vector<sensorID> sensors){
    vector<unsigned char> send_vector_ = {149, 0};
    send_vector_.at(1) = sensors.size();
    for(auto s: sensors){
        send_vector_.push_back(s);
    }
    return send_vector_;
}

vector<unsigned char> Sensors::createvector(sensorID sensor){
    return {142, sensor};
}

vector<unsigned char> Sensors::createvectorstream(vector<sensorID> sensors){
    vector<unsigned char> send_vector_ = {148, 0};
    send_vector_.at(1) = sensors.size();
    for(auto s: sensors){
        send_vector_.push_back(s);
    }
    return send_vector_;
}

int Sensors::parsedata(vector<unsigned char> input){
    if(input.at(0) != 19){
        logger_.error("FORMAT ERROR Sensors::ParseData: first byte isn't equal to 19");
        return -1;
    }
    else if(checksumcheck(input) !=1){
        logger_.error("CHECKSUM ERROR Sensors::ParseData: cant complete ChecksumCheck");
        return -2;
    }
    for(int i = 2; i < (2+input.at(1)); i++){
        sensorvariant Sensor_boost = (sensors_.find(static_cast<sensorID>( input.at(i) ))->second);
        if (Sensor_boost.type() == typeid(unsigned char)){
            sensors_.find(static_cast<sensorID>( input.at(i) ))->second = static_cast<unsigned char>(input.at(i+1));
            i++;
        }
        else if (Sensor_boost.type() == typeid(unsigned short)){
            sensors_.find(static_cast<sensorID>( input.at(i) ))->second = static_cast<unsigned short>((input.at(i+1) << 8) | input.at(i+2));
            i += 2;
        }
        else if (Sensor_boost.type() == typeid(short)){
            sensors_.find(static_cast<sensorID>( input.at(i) ))->second = static_cast<short>((input.at(i+1) << 8) | input.at(i+2));
            i += 2;
        }
        else if (Sensor_boost.type() == typeid(char)){
            sensors_.find(static_cast<sensorID>( input.at(i) ))->second = static_cast<char>(input.at(i+1));
            i++;
        }
    }
    return 1;
}

int Sensors::checksumcheck(vector<unsigned char> data){
    unsigned char som = 0;
    for(int i = 0; i <= (2+data.at(1)); i++){
        som += data.at(i);
    }
    if (0 == som){
        return 1;
    }
    logger_.error(string("CHECKSUM ERROR Sensors::ChecksumCheck: Calculated checksum is '") +=
                          to_string(+som) + "' and should be '" + to_string(+data.at(2+data.at(1))) + "' ");
    return -1;
}
