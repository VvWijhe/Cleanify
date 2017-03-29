#include <iostream>
#include "Server/server.h"
#include "io/roombacontroller.h"

using namespace std;

int main() {
    io::RoombaSCI sci("port", 109200);
    io::roombacontroller control(sci);
    //server::RoombaServer roombaServer(8080);
    //roombaServer.run();
    //cin.ignore();
    //roombaServer.stop();

    control.readSensors();

    return 0;
}
