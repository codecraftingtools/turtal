// Copyright (c) 2019 Jeffrey A. Webb

#include <turtal/clock/clock.hpp>

namespace turtal { namespace clock {

int count_{2};

Parameters clocks_[max_count_] {
    Parameters{"System"},
    Parameters{"Unspecified"}
};

} } // namespace turtal::clock
