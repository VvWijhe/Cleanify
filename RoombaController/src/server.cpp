//
// Created by jamie on 3/15/17.
//

#include <iostream>
#include "server.h"

using namespace server;
using namespace std;
using namespace restbed;

RoombaServer::RoombaServer(unsigned short port) {
    settings_ = make_shared<Settings>();
    settings_->set_port(port);
    settings_->set_default_header("Connection", "close");

    // main page reponse
    auto resource = make_shared<Resource>();
    resource->set_path("/");
    resource->set_method_handler("GET", responses::index);
    service_.publish(resource);

    // post instruction
    auto resource1 = make_shared<Resource>();
    resource1->set_path("/control");
    resource1->set_method_handler("POST", responses::handle_post);
    service_.publish(resource1);

    auto resource2 = make_shared<Resource>();
    resource2->set_path("/status");
    resource2->set_method_handler("GET", responses::status);
    service_.publish(resource2);

    // 404 page not found
    service_.set_not_found_handler(responses::error404);
}

RoombaServer::~RoombaServer() {
    stop();
}

void RoombaServer::run() {
    thread_ = thread([this]() {
        this->service_.start(settings_);
    });

    this_thread::sleep_for(chrono::milliseconds(300));

    isStarted = true;
}

void RoombaServer::stop() {
    if(!isStarted) return;
    service_.stop();
    thread_.join();
    isStarted = false;
    cout << "server stopped" << endl;
}

bool RoombaServer::started() const {
    return isStarted;
}
