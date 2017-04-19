//
// Created by jamie on 4/19/17.
//

#ifndef ROOMBACONTROLLER_GLB_ROOMBA_PARAM_H
#define ROOMBACONTROLLER_GLB_ROOMBA_PARAM_H

#include <map>
#include <mutex>

namespace globals {
    class RoombaParameters {
    public:
        enum paramaters {
            M_LEFT, M_RIGHT,
            BRUSHES,
            COMMAND
        };

        RoombaParameters() {}

        std::mutex& mutex() {
            return mutex_;
        }

        void setParameter(paramaters parameter, int val) {
            parameters_[parameter] = val;
        }

        int getParameter(paramaters parameter) {
            return parameters_[parameter];
        }

        void clear() {
            for(auto &parameter : parameters_) {
                parameter.second = 0;
            }
        }

    private:
        std::mutex mutex_;
        std::map<paramaters, int> parameters_;
    };

    extern RoombaParameters roomba_param;
}

#endif //ROOMBACONTROLLER_GLB_ROOMBA_PARAM_H
