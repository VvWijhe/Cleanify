//
// Created by jamie on 3/15/17.
//

#include <iostream>
#include "server.h"

using namespace server;
using namespace std;
using namespace restbed;

RoombaServer::RoombaServer(unsigned short port) {
    auto resource = make_shared<Resource>();
    resource->set_path("/");
    resource->set_method_handler("GET", responses::info);

    settings_ = make_shared<Settings>();
    settings_->set_port(port);
    settings_->set_default_header("Connection", "close");

    service_.publish(resource);
}

RoombaServer::~RoombaServer() {

}

void RoombaServer::run() {
    thread_ = thread([this]() {
        this->service_.start(settings_);
    });

    this_thread::sleep_for(chrono::seconds(1));

    cout << "server started" << endl;
}

void RoombaServer::stop() {
    service_.stop();
    thread_.join();
    cout << "server stopped" << endl;
}
