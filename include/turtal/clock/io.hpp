// Copyright (c) 2019 Jeffrey A. Webb

#ifndef TURTAL_CLOCK_IO_HPP
#define TURTAL_CLOCK_IO_HPP

#include <turtal/clock/clock.hpp>
#include <ostream>

namespace turtal { namespace clock {

inline std::ostream& operator <<(std::ostream& os, const ID& id)
{
    os << id.value();
    return os;
} 

inline std::ostream& operator <<(std::ostream& os, const Parameters& p)
{
    os << p.name() << ": "
       << "offset: " << p.time_offset_ns() << " ns, "
       << "sf: " << p.time_scale_factor() << ", "
       << "updated: " << p.system_time_of_last_offset_update_ns() << " ns";
    return os;
}

} } // namespace turtal::clock

#endif // TURTAL_CLOCK_IO_HPP
