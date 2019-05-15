// Copyright (c) 2019 Jeffrey A. Webb

#ifndef TURTAL_CLOCK_ID_HPP
#define TURTAL_CLOCK_ID_HPP

namespace turtal {

class Clock_ID
{
  public:
    Clock_ID(int value) : value_{value} {}
    
    int value() const {return value_;}

    bool operator == (const Clock_ID r) const {
    	return value_ == r.value_;
    }
    
  private:
    const int value_;
};

} // namespace turtal

#endif // TURTAL_CLOCK_ID_HPP
