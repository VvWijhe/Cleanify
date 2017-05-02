//
// Created by jamie on 4/19/17.
//

#ifndef ROOMBACONTROLLER_GLB_ROOMBA_PARAM_H
#define ROOMBACONTROLLER_GLB_ROOMBA_PARAM_H

#include <map>
#include <mutex>

namespace globals {
    /**
     * @brief Stores values of the roomba open interface commands. To avoid a parameter is set while reading, a mutex
     * is included.
     *
     * Note: this class does not send the values.
     */
    class RoombaParameters {
    public:
        enum paramaters {
            WHEEL_L, WHEEL_R,
            BRUSHES,
            COMMAND
        };

        RoombaParameters() {}

        std::mutex& mutex() {
            return mutex_;
        }

        void lock() {
            mutex_.lock();
        }

        void unlock() {
            mutex_.unlock();
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

    extern RoombaParameters rmbPrm;
}

#endif //ROOMBACONTROLLER_GLB_ROOMBA_PARAM_H
