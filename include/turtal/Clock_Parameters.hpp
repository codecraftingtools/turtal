// Copyright (c) 2019 Jeffrey A. Webb

#ifndef TURTAL_CLOCK_PARAMETERS_HPP
#define TURTAL_CLOCK_PARAMETERS_HPP

#include <turtal/Clock_ID.hpp>
#include <cstdint>
#include <string>

namespace turtal {

class Clock_Parameters;
namespace clock {
    Clock_Parameters& get_parameters_for(Clock_ID);
}

class Clock_Parameters {
  public:
    Clock_Parameters(Clock_ID id, const char* name) : id_{id}, name_{name} {
        register_clock(id);
    }
    Clock_Parameters(int id, const char* name) : Clock_Parameters(Clock_ID(id), name) {}

    static int max_clocks() {return max_clocks_;}

    Clock_ID id() const {return id_;}
    std::string name() const {return name_;}
    int64_t time_offset_ns() const {return time_offset_ns_;}
    double time_scale_factor() const {return time_scale_factor_;}
    uint64_t system_time_of_last_offset_update_ns() const {
        return system_time_of_last_offset_update_ns_;
    }

    Clock_Parameters& time_offset_ns(int64_t dt) {
        time_offset_ns_ = dt;
        return *this;
    }
    Clock_Parameters& time_scale_factor(double sf) {
        time_scale_factor_ = sf;
        return *this;
    }
    Clock_Parameters& system_time_of_last_offset_update_ns(uint64_t t) {
        system_time_of_last_offset_update_ns_ = t;
        return *this;
    }

    friend Clock_Parameters& clock::get_parameters_for(Clock_ID);

  private:
    void register_clock(Clock_ID id) {
        clocks_[id.value()] = this;
    }
    static Clock_Parameters& get_for(Clock_ID id) {
        return *clocks_[id.value()];
    }

    static const int max_clocks_ = 10;
    static Clock_Parameters* clocks_[max_clocks_];

    Clock_ID id_;
    std::string name_{"Unnamed"};
    int64_t time_offset_ns_{0};
    double time_scale_factor_{1.0};
    uint64_t system_time_of_last_offset_update_ns_{0};
};

} // namespace turtal

#endif // TURTAL_CLOCK_PARAMETERS_HPP
