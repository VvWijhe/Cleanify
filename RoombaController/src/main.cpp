#include <iostream>
#include <thread>

#include "server.h"
#include "roomba_statemachine.h"

using namespace std;
using namespace systemcontrol;

int main() {
    thread t([]{
        system("rfcomm connect /dev/rfcomm1 00:06:66:60:07:81");
    });

    this_thread::sleep_for(chrono::seconds(6));

    systemcontrol::RoombaControl control("/dev/rfcomm1", systemcontrol::RoombaControl::b115200);

    control.init();
    control.setMotors(control.all, false);

    t.join();

/*
    try {
        shared_ptr<RoombaStateContext> process = make_shared<RoombaStateContext>(make_shared<states::Initialise>());

        process->runAll();
    } catch (exception &e) {
        cerr << e.what() << endl;
    }*/

    return 0;
}
