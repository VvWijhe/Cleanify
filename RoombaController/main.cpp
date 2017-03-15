#include <iostream>
#include "Sci/roombasci.h"
#include "Server/server.h"

using namespace std;

int main() {
//    sci::RoombaSCI sci("/dev/ttyUSB0", B115200);
//    sci.connect();
//
//    int d = 0x1ff;
//    sci.sendCommand("Baud", {static_cast<unsigned char>(d >> 8), static_cast<unsigned char>(d), 1, 1, 1, 12, 255, 1,
//                             1, 1, 12, 255, 1, 1, '\r'});
//
//    sci.readSensors();
//    sci.close();

    server::RoombaServer server1(8080);
    server1.run();
    return 0;
}
