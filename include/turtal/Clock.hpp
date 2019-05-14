// Copyright (c) 2019 Jeffrey A. Webb

#ifndef TURTAL_CLOCK_HPP
#define TURTAL_CLOCK_HPP

#include <cstdint>

namespace turtal {

class Clock {
public:
    Clock(int id) : id_(id) {}

    int id() const {return id_;}
    int64_t time_offset_ns() const {return time_offset_ns_;}
    double time_scale_factor() const {return time_scale_factor_;}
    uint64_t system_time_of_last_offset_update_ns() const {
        return system_time_of_last_offset_update_ns_;
    }

    Clock &time_offset_ns(int64_t t) {
        time_offset_ns_ = t;
        return *this;
    }
    Clock &time_scale_factor(double sf) {
        time_scale_factor_ = sf;
        return *this;
    }
    Clock &system_time_of_last_offset_update_ns(uint64_t t) {
        system_time_of_last_offset_update_ns_ = t;
        return *this;
    }

private:
    int id_{0};
    int64_t time_offset_ns_{0};
    double time_scale_factor_{1.0};
    uint64_t system_time_of_last_offset_update_ns_{0};
};

namespace clock {
  Clock System(0);
};

} // namespace turtal

#endif // TURTAL_CLOCK_HPP
