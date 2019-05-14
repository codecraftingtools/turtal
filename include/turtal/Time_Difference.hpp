// Copyright (c) 2019 Jeffrey A. Webb

#ifndef TURTAL_TIME_DIFFERENCE_HPP
#define TURTAL_TIME_DIFFERENCE_HPP

#include <turtal/clock.hpp>
#include <cstdint>
#include <math.h>

namespace turtal {

template<turtal::Clock_ID N>
class Time_Difference {
public:
    Time_Difference() {};
    Time_Difference(const Time_Difference<clock::Unspecified>& r) {
        nanoseconds_ = r.nanoseconds_;
    }
    Time_Difference& operator=(const Time_Difference<clock::Unspecified>& r) {
        nanoseconds_ = r.nanoseconds_;
    }

    int64_t nanoseconds() {return nanoseconds_;}
    double seconds() {return nanoseconds_*1e-9;}

    static const turtal::Clock_ID Clock_ID{N};

public: // should be private
    int64_t nanoseconds_{0};
};

Time_Difference<clock::Unspecified> nanoseconds(int64_t ns) {
    Time_Difference<clock::Unspecified> dt;
    dt.nanoseconds_ = ns;
    return dt;
}

Time_Difference<clock::Unspecified> seconds(double s) {
    Time_Difference<clock::Unspecified> dt;
    dt.nanoseconds_ = round(s*1e9);
    return dt;
}

template<turtal::Clock_ID N>
using Duration = Time_Difference<N>;
  
} // namespace turtal

#endif // TURTAL_TIME_DIFFERENCE_HPP
