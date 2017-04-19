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

        void setParameter(paramaters parameter, int val) {
            std::unique_lock<std::mutex> lk(mutex_);
            parameters_[parameter] = val;
        }

        int getParameter(paramaters parameter) {
            std::unique_lock<std::mutex> lk(mutex_);
            return parameters_[parameter];
        }

        void clear() {
            std::unique_lock<std::mutex> lk(mutex_);
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
