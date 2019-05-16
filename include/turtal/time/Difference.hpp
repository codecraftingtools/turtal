// Copyright (c) 2019 Jeffrey A. Webb

#ifndef TURTAL_TIME_DIFFERENCE_HPP
#define TURTAL_TIME_DIFFERENCE_HPP

#include <turtal/clock/clock.hpp>
#include <math.h>

namespace turtal {

namespace time { class Difference; }

time::Difference nanoseconds(int64_t);
time::Difference seconds(double);

namespace time {

class Difference {
  public:
    Difference(clock::ID id = clock::System) : clock_id_{id} {}
    Difference(clock::ID id, const Difference& r) : clock_id_{id} {
        Difference d{id};
        d = r;
        nanoseconds_ = d.nanoseconds_;
    }
    Difference(const Difference& r, clock::ID id) : Difference(id, r) {}
    Difference(const Difference&) = default;
    Difference(Difference&&) = default;

    clock::ID clock_id() const {return clock_id_;}
    int64_t nanoseconds() const {return nanoseconds_;}
    double seconds() const {return nanoseconds_*1e-9;}

    Difference& operator=(const Difference& r) {
        if (r.clock_id_ == clock::Unspecified || r.clock_id_ == clock_id_) {
            nanoseconds_ = r.nanoseconds_;
        } else if (clock_id_ == clock::System) {
            auto p = clock::get_parameters_for(r.clock_id_);
            auto sf = p.time_scale_factor();
            nanoseconds_ = r.nanoseconds_/sf;
        } else if (r.clock_id_ == clock::System) {
            auto p = clock::get_parameters_for(clock_id_);
            auto sf = p.time_scale_factor();
            nanoseconds_ = r.nanoseconds_*sf;
        } else {
            Difference d{clock::System};
            d = r;
            *this = d;
        }
	    return *this;
    }
    Difference& operator=(Difference&&) = default;

    friend time::Difference turtal::nanoseconds(int64_t);
    friend time::Difference turtal::seconds(double);

  private:
    clock::ID clock_id_;
    int64_t nanoseconds_{0};
};

using Duration = Difference;

} // namespace time

time::Difference nanoseconds(int64_t ns) {
    time::Difference dt{clock::Unspecified};
    dt.nanoseconds_ = ns;
    return dt;
}

time::Difference seconds(double s) {
    time::Difference dt{clock::Unspecified};
    dt.nanoseconds_ = round(s*1e9);
    return dt;
}

} // namespace turtal

#endif // TURTAL_TIME_DIFFERENCE_HPP
