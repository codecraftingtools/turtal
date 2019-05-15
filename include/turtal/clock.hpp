// Copyright (c) 2019 Jeffrey A. Webb

#ifndef TURTAL_CLOCK_HPP
#define TURTAL_CLOCK_HPP

#include <turtal/Clock_Parameters.hpp>

namespace turtal { namespace clock {

Clock_Parameters System_Clock_{0, "System"};
Clock_Parameters Unspecified_Clock_{Clock_Parameters::max_clocks(), "Unspecified"};

const Clock_ID System{System_Clock_.id()};
const Clock_ID Unspecified{Unspecified_Clock_.id()};

inline Clock_Parameters& get_parameters_for(Clock_ID id)
{
    return Clock_Parameters::get_for(id);
}

} } // namespace turtal::clock

#endif // TURTAL_CLOCK_HPP
