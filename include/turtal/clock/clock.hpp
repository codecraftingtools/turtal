// Copyright (c) 2019 Jeffrey A. Webb

#ifndef TURTAL_CLOCK_HPP
#define TURTAL_CLOCK_HPP

#include <turtal/clock/ID.hpp>
#include <turtal/clock/Parameters.hpp>
#include <stdexcept>

namespace turtal { namespace clock {

const ID System{0};
const ID Unspecified{1};

const int max_count_ = 10;
extern int count_;
extern Parameters clocks_[];

inline int max_count() {return max_count_;};
inline int count() {return count_;};

inline ID add()
{
    if (count_ >= max_count_) {
        throw std::runtime_error("too many clocks");
    }

    ID new_id(count_);
    count_++;
    return new_id;
}

inline Parameters& get_parameters_for(int i)
{
    if (i < 0 || i >= count_) {
        throw std::runtime_error("clock index out of bounds");
    }
    return clocks_[i];
}
inline Parameters& get_parameters_for(ID id)
{
    return get_parameters_for(id.value());
}

} } // namespace turtal::clock

#endif // TURTAL_CLOCK_HPP
