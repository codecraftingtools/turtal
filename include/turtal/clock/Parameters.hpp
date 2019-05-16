// Copyright (c) 2019 Jeffrey A. Webb

#ifndef TURTAL_CLOCK_PARAMETERS_HPP
#define TURTAL_CLOCK_PARAMETERS_HPP

#include <cstdint>
#include <string>

namespace turtal { namespace clock {

class Parameters {
  public:
    Parameters(const char* name = "Unnamed") : name_{name} {}

    std::string name() const {return name_;}
    int64_t time_offset_ns() const {return time_offset_ns_;}
    double time_scale_factor() const {return time_scale_factor_;}
    uint64_t system_time_of_last_offset_update_ns() const {
        return system_time_of_last_offset_update_ns_;
    }

    Parameters& name(const char* name) {
        name_ = name;
        return *this;
    }
    Parameters& time_offset_ns(int64_t dt) {
        time_offset_ns_ = dt;
        return *this;
    }
    Parameters& time_scale_factor(double sf) {
        time_scale_factor_ = sf;
        return *this;
    }
    Parameters& system_time_of_last_offset_update_ns(uint64_t t) {
        system_time_of_last_offset_update_ns_ = t;
        return *this;
    }

  private:
    std::string name_;
    int64_t time_offset_ns_{0};
    double time_scale_factor_{1.0};
    uint64_t system_time_of_last_offset_update_ns_{0};
};

} } // namespace turtal::clock

#endif // TURTAL_CLOCK_PARAMETERS_HPP
