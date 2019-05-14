// Copyright (c) 2019 Jeffrey A. Webb

#ifndef TURTAL_TIME_POINT_HPP
#define TURTAL_TIME_POINT_HPP

#include <turtal/Clock.hpp>

namespace turtal {

class Time_Point {
public:
    Time_Point(const Clock &clock = clock::System) : clock_(clock) {}

    const Clock &clock() const {return clock_;}

private:
    uint64_t time_ns_{0};
    const Clock &clock_;
};

} // namespace turtal

#endif // TURTAL_TIME_POINT_HPP
