// Copyright (c) 2019 Jeffrey A. Webb

#ifndef TURTAL_CLOCK_HPP
#define TURTAL_CLOCK_HPP

namespace turtal {

typedef int Clock_ID;
  
namespace clock {
  const Clock_ID Unspecified{-1};
  const Clock_ID System{0};
};

} // namespace turtal

#endif // TURTAL_CLOCK_HPP
