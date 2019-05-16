// Copyright (c) 2019 Jeffrey A. Webb

#ifndef TURTAL_INSTANT_HPP
#define TURTAL_INSTANT_HPP

#include <turtal/time/Difference.hpp>

namespace turtal { namespace time {

class Instant {
  public:
    Instant(clock::ID id = clock::System) : clock_id_{id} {};

    clock::ID clock_id() const {return clock_id_;}
    int64_t nanoseconds() const {return nanoseconds_;}
    double seconds() const {return nanoseconds_*1e-9;}

    static Instant from_nanoseconds(
            uint64_t ns, clock::ID id = clock::System) {
        Instant t{id};
        t.nanoseconds_ = ns;
    }
    static Instant from_seconds(
            double s, clock::ID id = clock::System) {
        Instant t{id};
        t.nanoseconds_ = round(s*1e9);
    }

  private:
    clock::ID clock_id_;
    uint64_t nanoseconds_{0};
};

} } // namespace turtal::time

#endif // TURTAL_INSTANT_HPP
