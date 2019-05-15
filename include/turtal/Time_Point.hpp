// Copyright (c) 2019 Jeffrey A. Webb

#ifndef TURTAL_TIME_POINT_HPP
#define TURTAL_TIME_POINT_HPP

#include <turtal/Time_Difference.hpp>

namespace turtal {

class Time_Point {
public:
    Time_Point(Clock_ID id = clock::System) : id_{id} {};

    Clock_ID id() const {return id_;}
    int64_t nanoseconds() const {return nanoseconds_;}
    double seconds() const {return nanoseconds_*1e-9;}

    static Time_Point from_nanoseconds(
            uint64_t ns, Clock_ID id = clock::System) {
        Time_Point t{id};
        t.nanoseconds_ = ns;
    }
    static Time_Point from_seconds(
            double s, Clock_ID id = clock::System) {
        Time_Point t{id};
        t.nanoseconds_ = round(s*1e9);
    }

private:
    Clock_ID id_;
    uint64_t nanoseconds_{0};
};

} // namespace turtal

#endif // TURTAL_TIME_POINT_HPP
