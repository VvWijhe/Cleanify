//
// Created by jamie on 5/2/17.
//

#include "gtest/gtest.h"
#include <chrono>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class Timer {
public:
    using clock = std::chrono::high_resolution_clock;
    using second = std::chrono::duration<double, std::ratio<1>>;

    Timer() : beg_(clock::now()) {}

    void reset() { beg_ = clock::now(); }

    double elapsed() {
        auto tmp = std::chrono::duration_cast<second>
                (clock::now() - beg_).count();
        reset();
        return tmp;
    }

private:
    std::chrono::time_point<clock> beg_;
};

TEST(algorithm, dt) {
    using namespace std;

    const int frequency{500};
    int counter{};
    boost::asio::io_service io;
    Timer timer;

    while(counter++ < 5) {
        boost::asio::deadline_timer t(io, boost::posix_time::milliseconds(frequency));

        if(!counter) ASSERT_NEAR(timer.elapsed(), frequency, 0.0001);

        t.wait();
    }
}

