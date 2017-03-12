#include "serial/SerialPort.h"

using namespace std;

int main() {
    SerialPort serial("/dev/tty0", B19200);
    serial.connect();
    serial.swrite({100, 200, 20, 255});
}
