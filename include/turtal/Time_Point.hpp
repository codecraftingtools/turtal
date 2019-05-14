// Copyright (c) 2019 Jeffrey A. Webb

#ifndef TURTAL_TIME_POINT_HPP
#define TURTAL_TIME_POINT_HPP

#include <turtal/clock.hpp>
#include <cstdint>
#include <math.h>

namespace turtal {

template<turtal::Clock_ID N>
class Time_Point {
public:
    int64_t nanoseconds() {return nanoseconds_;}
    double seconds() {return nanoseconds_*1e-9;}

    static Time_Point from_nanoseconds(uint64_t ns) {
        Time_Point t;
        t.nanoseconds_ = ns;
    }
    static Time_Point from_seconds(double s) {
        Time_Point t;
        t.nanoseconds_ = round(s*1e9);
    }

    static const turtal::Clock_ID Clock_ID{N};

private:
    uint64_t nanoseconds_{0};
};

} // namespace turtal

#endif // TURTAL_TIME_POINT_HPP
