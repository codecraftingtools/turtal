// Copyright (c) 2019 Jeffrey A. Webb

#ifndef TURTAL_DURATION_HPP
#define TURTAL_DURATION_HPP

#include <turtal/Clock.hpp>

namespace turtal {

class Duration {
public:
    Duration(const Clock &clock = clock::System) : clock_ptr_(&clock) {}

    const Clock &clock() const {return *clock_ptr_;}
  
private:
    int64_t dt_ns_{0};
    const Clock *clock_ptr_;
};

} // namespace turtal

#endif // TURTAL_DURATION_HPP
