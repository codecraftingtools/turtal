// Copyright (c) 2019 Jeffrey A. Webb

#ifndef TURTAL_TIME_IO_HPP
#define TURTAL_TIME_IO_HPP

#include <turtal/clock/io.hpp>
#include <turtal/time/time.hpp>
#include <ostream>

namespace turtal { namespace time {

inline std::ostream& operator <<(std::ostream& os, const Difference& d)
{
    os << "clock[" << d.clock_id() << "]: " << d.nanoseconds() << " ns";
    return os;
}

} } // namespace turtal::time

#endif // TURTAL_TIME_IO_HPP
