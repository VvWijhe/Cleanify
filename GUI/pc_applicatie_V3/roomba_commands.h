#ifndef ROOMBA_COMMANDS_H
#define ROOMBA_COMMANDS_H

// Roomba Opcodes
#define R_Op_Start 128
#define R_Op_Baud 129
#define R_Op_Control 130
#define R_Op_Safe 131
#define R_Op_Full 132
#define R_Op_Power 133
#define R_Op_Spot 134
#define R_Op_Clean 135
#define R_Op_Max 136
#define R_Op_Drive 137
#define R_Op_Motors 138
#define R_Op_Leds 139
#define R_Op_Song 140
#define R_Op_Play 141
#define R_Op_Sensors 142
#define R_Op_FSD 143 // Force-Seeking-Dock

// Roomba Baudrates(must be send after R_Op_Baud)
#define R_Baud_300 0
#define R_Baud_600 1
#define R_Baud_1200 2
#define R_Baud_2400 3
#define R_Baud_4800 4
#define R_Baud_9600 5
#define R_Baud_14400 6
#define R_Baud_19200 7
#define R_Baud_28800 8
#define R_Baud_38400 9
#define R_Baud_57600 10
#define R_Baud_115200 11

// Roomba Velocity between -500-500 mm/s(must be conferted to hex)
// Example: -200 = hex FF38 = [hex FF][hex 38] = [255][56]
#define R_Velo_ -500 0xFE0C //[254][12]
#define R_Velo_ -400 0xFE70 //[254][112]
#define R_Velo_ -300 0xFED4 //[254][212]
#define R_Velo_ -200 0xFF38 //[255][56]
#define R_Velo_ -100 0xFF9C //[255][156]
#define R_Velo_0 0x0000     //[00][00]
#define R_Velo_100 0x0064   //[00][100]
#define R_Velo_200 0x00C8   //[00][200]
#define R_Velo_300 0x012C   //[01][44]
#define R_Velo_400 0x0190   //[01][144]
#define R_Velo_500 0x01F4   //[01][244]

// Roomba Radius between -2000-2000 mm(must be conferted to hex)
// Example: 500 = hex 01F4 = [hex 01][hex F4] = [1][244]
#define R_Rad_ -2000 0xF830 //[248][48]
#define R_Rad_ -1750 0xF92A //[249][42]
#define R_Rad_ -1500 0xFA24 //[250][36]
#define R_Rad_ -1250 0xFB1E //[251][30]
#define R_Rad_ -1000 0xFC18 //[252][24]
#define R_Rad_ -750 0xFD12  //[253][18]
#define R_Rad_ -500 0xFE0C  //[254][12]
#define R_Rad_ -250 0xFF06  //[255][06]
#define R_Rad_0 0x0000      //[00][00]
#define R_Rad_250 0x00FA    //[00][250]
#define R_Rad_500 0x01F4    //[01][244]
#define R_Rad_750 0x02EE    //[02][238]
#define R_Rad_1000 0x03E8   //[03][232]
#define R_Rad_1250 0x04E2   //[04][226]
#define R_Rad_1500 0x05DC   //[05][220]
#define R_Rad_1750 0x06D6   //[06][214]
#define R_Rad_2000 0x07D0   //[07][208]

// Roomba Motors(Must be send after R_Op_Motors)
#define R_Mot_Side 1
#define R_Mot_Vacuum 2
#define R_Mot_Main 4
#define R_Mot_All 7

// Rooma Sensor packets(Must be send after R_Op_Sensors)
#define R_Sen_Pack_All 0 // Packet Size 26 bytes
#define R_Sen_Pack_1                                                           \
  1 // Packet Size 10 bytes(Wheeldrops, Wall, Cliff, Motor, Dirt)
#define R_Sen_Pack_2                                                           \
  2 // Packet Size 6 bytes(Remote Control, Buttons, Distance, Angle)
#define R_Sen_Pack_3                                                           \
  3 // Packet Size 10 bytes(Charging state, Voltage, Current, Temperature,
    // Charge, Capacity)

#endif // ROOMBA_COMMANDS_H
