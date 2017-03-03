#ifndef HELPER
#define HELPER

#define SCALE(meters) (meters * 35.0)

const double PI = 3.14159265358979323846;
const double PI_2 = 2.0 * PI;
const double DELTA_t_sec = 0.03;
const double MAX_t_sec = 10.0;
const double velocity = SCALE(0.2); // m/sec
const double angular_velocity = 45.0; // deg/sec

template<typename T>
bool compare(T v1, T v2, T marge) {
   return (v2 > (v1 - marge) && v2 < (v1 + marge)) || v1 == v2;
}

#endif // HELPER

