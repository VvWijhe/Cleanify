//
// Created by jamie on 3/17/17.
//

#ifndef ROOMBACONTROLLER_RESPONSES_H
#define ROOMBACONTROLLER_RESPONSES_H

#include "http_server.hpp"

namespace responses {
    using shrpResponse = std::shared_ptr<SimpleWeb::Server<SimpleWeb::HTTP>::Response>;
    using shrpRequest = std::shared_ptr<SimpleWeb::Server<SimpleWeb::HTTP>::Request>;
    using responseHandler = std::function<void(std::shared_ptr<SimpleWeb::Server<SimpleWeb::HTTP>::Response>,
                                               std::shared_ptr<SimpleWeb::Server<SimpleWeb::HTTP>::Request>)>;

    const std::string endh("\r\n\r\n");
    const std::string response200("HTTP/1.1 200 OK\r\n");
    const std::string response404("HTTP/1.1 404 Bad Request\r\n");

    // response handlers
    void info(shrpResponse response, shrpRequest request);
    void sensors(shrpResponse response, shrpRequest request);
}

#endif //ROOMBACONTROLLER_RESPONSES_H
