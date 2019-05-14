// Copyright (c) 2019 Jeffrey A. Webb

#ifndef TURTAL_CLOCK_HPP
#define TURTAL_CLOCK_HPP

#include <cstdint>

namespace turtal {

class Clock {
public:
    Clock(int id) : id_(id) {}

    int id() const {return id_;}

    friend class Time_Point;
    friend class Duration;

private:
    uint64_t system_time_of_last_sync_ns_{0};
    uint64_t time_offset_ns_{0};
    double time_scale_factor_{1.0};
    int id_{0};
};

namespace clock {
  Clock System(0);
};

} // namespace turtal

#endif // TURTAL_CLOCK_HPP
