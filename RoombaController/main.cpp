#include <iostream>
#include "serial/roombasci.h"

using namespace std;

int main() {
    roombaSCI::RoombaSCI sci("/dev/tty0", B19200);
    sci.sendCommand("Start", {12, 255});
    return 0;
}
