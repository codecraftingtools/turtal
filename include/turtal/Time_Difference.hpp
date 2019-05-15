// Copyright (c) 2019 Jeffrey A. Webb

#ifndef TURTAL_TIME_DIFFERENCE_HPP
#define TURTAL_TIME_DIFFERENCE_HPP

#include <turtal/clock.hpp>
#include <math.h>

#include <iostream> // test

namespace turtal {

class Time_Difference {
  public:
    Time_Difference(Clock_ID clock_id = clock::System) : clock_id_{clock_id} {}
    Time_Difference(const Time_Difference& r) = default;
    Time_Difference(Time_Difference&& r) = default;

    Time_Difference& operator=(const Time_Difference& r) {

        // test
        std::cout << "equal " << clock_id_.value() << " " << r.clock_id_.value() << std::endl;

        if (r.clock_id_ == clock::Unspecified || r.clock_id_ == clock_id_) {
            nanoseconds_ = r.nanoseconds_;
        } else if (r.clock_id_ == clock::System) {
            //auto sf = clock::get_parameters_for(clock_id_);
            nanoseconds_ = 88888;
        } else {
            nanoseconds_ = 99999;
        }
	    return *this;
    }
    Time_Difference& operator=(Time_Difference&& r) = default;

    Clock_ID clock_id() const {return clock_id_;}
    int64_t nanoseconds() const {return nanoseconds_;}
    double seconds() const {return nanoseconds_*1e-9;}

  public:
    Clock_ID clock_id_;
    int64_t nanoseconds_{0};
};

Time_Difference nanoseconds(int64_t ns) {
    Time_Difference dt{clock::Unspecified};
    dt.nanoseconds_ = ns;
    return dt;
}

Time_Difference seconds(double s) {
    Time_Difference dt{clock::Unspecified};
    dt.nanoseconds_ = round(s*1e9);
    return dt;
}

using Duration = Time_Difference;

} // namespace turtal

#endif // TURTAL_TIME_DIFFERENCE_HPP
