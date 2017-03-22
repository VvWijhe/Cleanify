//
// Created by jamie on 3/17/17.
//

#ifndef ROOMBACONTROLLER_RESPONSES_H
#define ROOMBACONTROLLER_RESPONSES_H

#include <restbed>
#include <memory>

namespace responses {
    using pSession = std::shared_ptr<restbed::Session>;
    using responseHandler = std::function<void(const pSession session)>;

    const std::string endh("\r\n\r\n");
    const std::string response200("HTTP/1.1 200 OK\r\n");
    const std::string response404("HTTP/1.1 404 Bad Request\r\n");

    // response handlers
    void info(pSession session);
}

#endif //ROOMBACONTROLLER_RESPONSES_H
