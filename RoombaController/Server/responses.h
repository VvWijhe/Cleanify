//
// Created by jamie on 3/17/17.
//

#ifndef ROOMBACONTROLLER_RESPONSES_H
#define ROOMBACONTROLLER_RESPONSES_H

#include <memory>

#include <restbed>
#include "file_handler.h"

namespace responses {
    using pSession = std::shared_ptr<restbed::Session>;
    using responseHandler = std::function<void(const pSession session)>;

    // response handlers
    void info(pSession session);
    void ajax(pSession session);
    void error404(pSession session);
}

#endif //ROOMBACONTROLLER_RESPONSES_H
