//
// Created by jamie on 3/17/17.
//

#include "responses.h"

using namespace std;
using namespace restbed;

void responses::info(pSession session) {
    const auto request = session->get_request();

    int content_length = request->get_header("Content-Length", 0);

    session->fetch(static_cast<const size_t >(content_length),
                   [](const shared_ptr<Session> s, const Bytes &body) {
                       s->close(OK,
                                "<h1>Hello World!</h1>",
                                {{"Content-Length", "21"}});
                   });
}

void responses::error404(pSession session) {
    const auto request = session->get_request();

    int content_length = request->get_header("Content-Length", 0);

    session->fetch(static_cast<const size_t >(content_length),
                   [](const shared_ptr<Session> s, const Bytes &body) {
                       std::string content("Error 404, page not found");

                       s->close(NOT_FOUND,
                                content,
                                {{"Content-Length", std::to_string(content.size())}});
                   });
}
