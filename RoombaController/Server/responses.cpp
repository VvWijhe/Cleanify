//
// Created by jamie on 3/17/17.
//

#include <fstream>

#include "responses.h"

using namespace std;
using namespace restbed;

void responses::info(pSession session) {
    const auto request = session->get_request();

    int content_length = request->get_header("Content-Length", 0);

    session->fetch(content_length, [](const shared_ptr<Session> session, const Bytes &body) {
        fprintf(stdout, "%.*s\n", (int) body.size(), body.data());
        session->close(OK, "Hello, World!", {{"Content-Length", "13"}});
    });
}
