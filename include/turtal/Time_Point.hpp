// Copyright (c) 2019 Jeffrey A. Webb

#ifndef TURTAL_TIME_POINT_HPP
#define TURTAL_TIME_POINT_HPP

#include <turtal/Clock.hpp>

namespace turtal {

class Time_Point {
public:
    Time_Point(const Clock &clock = clock::System) : clock_ptr_(&clock) {}
    Time_Point(Time_Point&&) = delete;
    Time_Point& operator=(Time_Point&&) = delete;
    Time_Point(const Time_Point& r) {
        time_ns_ = r.time_ns_;
        clock_ptr_ = r.clock_ptr_;
    }
    Time_Point& operator=(const Time_Point& r) {
        time_ns_ = r.time_ns_;
        clock_ptr_ = r.clock_ptr_;
    }
    ~Time_Point() {};

    const Clock &clock() const {return *clock_ptr_;}

private:
    uint64_t time_ns_{0};
    const Clock *clock_ptr_;
};

} // namespace turtal

#endif // TURTAL_TIME_POINT_HPP
