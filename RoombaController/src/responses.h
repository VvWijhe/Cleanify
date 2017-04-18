//
// Created by jamie on 3/17/17.
//

#ifndef ROOMBACONTROLLER_RESPONSES_H
#define ROOMBACONTROLLER_RESPONSES_H

#include <memory>
#include <vector>
#include <restbed>
#include <string>

#include "file_handler.h"

namespace responses {
    using pSession = std::shared_ptr<restbed::Session>;
    using responseHandler = std::function<void(const pSession session)>;

    /**
     * @brief Response to http get /. It sends an html page.
     * @param session contains http request information.
     */
    void index(pSession session);

    /**
     * @brief Handles client post request. The client starts a roomba session and can send instructions in json format.
     * The json format is then parsed. If there is an error in the received json, the response contains an error log,
     * which is also in json format. The log is then send to the client.
     *
     * If a session is already started by another client, no other client can control the roomba.
     * @param session contains http request information.
     */
    void handle_post(pSession session);

    /**
     * @brief Responses the roomba status in json format.
     * @param session contains http request information.
     */
    void status(pSession session);

    /**
     * @brief Responses to a client if the client tries to acces a page that is not a resource on the server.
     * @param session contains http request information.
     */
    void error404(pSession session);
}

#endif //ROOMBACONTROLLER_RESPONSES_H
