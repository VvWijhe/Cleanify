//
// Created by jamie on 3/15/17.
//

#include "server.h"

using namespace server;
using namespace responses;
using namespace std;

RoombaServer::RoombaServer(unsigned short port) {
    server_.config.port = port;

    // default response
    server_.default_resource["GET"] = [this](shared_ptr<httpServer::Response> response,
                                               shared_ptr<httpServer::Request> request) {
        try {
            auto web_root_path = boost::filesystem::canonical("");
            auto path = boost::filesystem::canonical(web_root_path / request->path);
            //Check if path is within web_root_path
            if (distance(web_root_path.begin(), web_root_path.end()) > distance(path.begin(), path.end()) ||
                !equal(web_root_path.begin(), web_root_path.end(), path.begin()))
                throw invalid_argument("path must be within root path");
            if (boost::filesystem::is_directory(path))
                path /= "index.html";
            if (!(boost::filesystem::exists(path) && boost::filesystem::is_regular_file(path)))
                throw invalid_argument("file does not exist");

            std::string cache_control, etag;

            auto html = make_shared<ifstream>();
            html->open(path.string(), ifstream::in | ios::binary | ios::ate);

            if (*html) {
                auto length = html->tellg();
                html->seekg(0, ios::beg);

                *response << response200 << cache_control << etag << "Content-Length: " << length
                          << "\r\n\r\n";
                htmlResponse(this->server_, response, html);
            } else
                throw invalid_argument("could not read file");
        }
        catch (const exception &e) {
            string content = "Error 404 Page not found";
            *response << response404 << "Content-Length: " << content.length() << endh
                      << content;
        }
    };

    server_.resource["^/status"]["GET"] = responseHandler(info);
}

RoombaServer::~RoombaServer() {

}

void RoombaServer::run() {
    thread_ = thread([this]() {
        this->server_.start();
    });

    this_thread::sleep_for(chrono::seconds(1));

    cout << "server started" << endl;
}

void RoombaServer::stop() {
    server_.stop();
    thread_.join();
    cout << "server stopped" << endl;
}

void RoombaServer::htmlResponse(const httpServer &server, const std::shared_ptr<httpServer::Response> &response,
                              const std::shared_ptr<std::ifstream> &ifs) {
    //read and send 128 KB at a time
    static vector<char> buffer(131072); // Safe when server is running on one thread
    streamsize read_length;
    if((read_length=ifs->read(&buffer[0], buffer.size()).gcount())>0) {
        response->write(&buffer[0], read_length);
        if(read_length==static_cast<streamsize>(buffer.size())) {
            server.send(response, [this, response, ifs](const boost::system::error_code &ec) {
                if(!ec)
                    htmlResponse(this->server_, response, ifs);
                else
                    cerr << "Connection interrupted" << endl;
            });
        }
    }
}
