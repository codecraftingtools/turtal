// Copyright (c) 2019 Jeffrey A. Webb

#ifndef TURTAL_TIME_DIFFERENCE_HPP
#define TURTAL_TIME_DIFFERENCE_HPP

#include <turtal/Clock.hpp>

namespace turtal {

class Time_Difference {
public:
    Time_Difference(const Clock &clock = clock::System) : clock_ptr_(&clock) {}

    const Clock &clock() const {return *clock_ptr_;}
  
private:
    int64_t dt_ns_{0};
    const Clock *clock_ptr_;
};

typedef Time_Difference Duration;
  
} // namespace turtal

#endif // TURTAL_TIME_DIFFERENCE_HPP
