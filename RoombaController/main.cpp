#include <iostream>

#include "Server/server.h"
#include "SystemControl/roomba_statemachine.h"

using namespace std;
using namespace systemcontrol;

int main() {

//    systemcontrol::RoombaControl control("/dev/ttyUSB0",systemcontrol::RoombaControl::b115200);
//
//    control.init();
//    control.setMotors(control.all, true);
//


    try {
        shared_ptr<RoombaStateContext> process = make_shared<RoombaStateContext>(make_shared<states::Initialise>());

        process->runAll();
    } catch (exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}
