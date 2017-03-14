#include <iostream>
#include "sci/roombasci.h"

using namespace std;

int main() {
    sci::RoombaSCI sci("/dev/ttyUSB0", B19200);
    sci.connect();

    int d = 0x1ff;
    sci.sendCommand("Baud", {static_cast<unsigned char>(d >> 8), static_cast<unsigned char>(d), 1, 1, 1, 12, 255, 1,
                             1, 1, 12, 255, 1, 1, 1});

    return 0;
}
