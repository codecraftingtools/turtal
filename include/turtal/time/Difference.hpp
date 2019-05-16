// Copyright (c) 2019 Jeffrey A. Webb

#ifndef TURTAL_TIME_DIFFERENCE_HPP
#define TURTAL_TIME_DIFFERENCE_HPP

#include <turtal/clock/clock.hpp>
#include <math.h>

namespace turtal { namespace time {

class Difference;

namespace units {
Difference seconds(double, clock::ID);
Difference nanoseconds(int64_t, clock::ID);
}

class Difference {
  public:
    Difference(clock::ID id = clock::System) : clock_id_{id} {}
    Difference(clock::ID id, const Difference& r) : clock_id_{id} {
        Difference d{id};
        d = r;
        nanoseconds_ = d.nanoseconds_;
    }
    Difference(const Difference& r, clock::ID id) : Difference(id, r) {}
    Difference(const Difference&) = default;
    Difference(Difference&&) = default;

    clock::ID clock_id() const {return clock_id_;}
    int64_t nanoseconds() const {return nanoseconds_;}
    double seconds() const {return nanoseconds_*1e-9;}

    Difference& operator =(const Difference& r) {
        if (r.clock_id_ == clock::Unspecified || r.clock_id_ == clock_id_) {
            nanoseconds_ = r.nanoseconds_;
        } else if (clock_id_ == clock::System) {
            auto p = clock::get_parameters_for(r.clock_id_);
            auto sf = p.time_scale_factor();
            nanoseconds_ = r.nanoseconds_/sf;
        } else if (r.clock_id_ == clock::System) {
            auto p = clock::get_parameters_for(clock_id_);
            auto sf = p.time_scale_factor();
            nanoseconds_ = r.nanoseconds_*sf;
        } else {
            Difference d{clock::System};
            d = r;
            *this = d;
        }
	    return *this;
    }
    Difference& operator =(Difference&&) = default;

    Difference operator +(const Difference& r) const {
        Difference dt(clock_id_, r);
        dt.nanoseconds_ += nanoseconds_;
        return dt;
    }
    Difference operator -(const Difference& r) const {
        Difference dt(clock_id_, r);
        dt.nanoseconds_ -= nanoseconds_;
        return dt;
    }
    Difference operator *(double r) const {
        Difference dt(*this);
        dt.nanoseconds_ *= r;
        return dt;
    }
    Difference operator /(double r) const {
        Difference dt(*this);
        dt.nanoseconds_ /= r;
        return dt;
    }

    Difference& operator +=(const Difference& r) {
        *this = (*this) + r;
        return *this;
    }
    Difference& operator -=(const Difference& r) {
        *this = (*this) - r;
        return *this;
    }

    friend Difference units::seconds(double, clock::ID);
    friend Difference units::nanoseconds(int64_t, clock::ID);

  private:
    clock::ID clock_id_;
    int64_t nanoseconds_{0};
};

inline Difference operator *(double left, const Difference &r)
{
    return r*left;
}
inline Difference operator /(double left, const Difference &r)
{
    return units::seconds(left/r.seconds(), r.clock_id());
}

namespace units {

inline Difference seconds(double s = 1, clock::ID id = clock::Unspecified)
{
    Difference dt{id};
    dt.nanoseconds_ = round(s*1e9);
    return dt;
}
inline Difference seconds(clock::ID id, double s)
{
    return seconds(s, id);
}

inline Difference nanoseconds(int64_t ns = 1, clock::ID id = clock::Unspecified)
{
    Difference dt{id};
    dt.nanoseconds_ = ns;
    return dt;
}
inline Difference nanoseconds(clock::ID id, int64_t ns)
{
    return nanoseconds(ns, id);
}

inline Difference microseconds(double dt = 1, clock::ID id = clock::Unspecified)
{
    return seconds(dt*1e-6, id);
}
inline Difference microseconds(clock::ID id, double dt)
{
    return microseconds(dt, id);
}

inline Difference milliseconds(double dt = 1, clock::ID id = clock::Unspecified)
{
    return seconds(dt*1e-3, id);
}
inline Difference milliseconds(clock::ID id, double dt)
{
    return milliseconds(dt, id);
}

inline Difference minutes(double dt = 1, clock::ID id = clock::Unspecified)
{
    return seconds(dt*60.0, id);
}
inline Difference minutes(clock::ID id, double dt)
{
    return minutes(dt, id);
}

inline Difference hours(double dt = 1, clock::ID id = clock::Unspecified)
{
    return minutes(dt*60.0, id);
}
inline Difference hours(clock::ID id, double dt)
{
    return hours(dt, id);
}

inline Difference days(double dt = 1, clock::ID id = clock::Unspecified)
{
    return hours(dt*24.0, id);
}
inline Difference days(clock::ID id, double dt)
{
    return days(dt, id);
}

inline Difference hertz(double f = 1, clock::ID id = clock::Unspecified)
{
    return seconds(1.0/f, id);
}
inline Difference hertz(clock::ID id, double dt)
{
    return hertz(dt, id);
}

inline Difference kilohertz(double f = 1, clock::ID id = clock::Unspecified)
{
    return hertz(f*1e3, id);
}
inline Difference kilohertz(clock::ID id, double dt)
{
    return kilohertz(dt, id);
}

inline Difference megahertz(double f = 1, clock::ID id = clock::Unspecified)
{
    return hertz(f*1e6, id);
}
inline Difference megahertz(clock::ID id, double dt)
{
    return megahertz(dt, id);
}

inline Difference gigahertz(double f = 1, clock::ID id = clock::Unspecified)
{
    return hertz(f*1e9, id);
}
inline Difference gigahertz(clock::ID id, double dt)
{
    return gigahertz(dt, id);
}

inline Difference operator ""_ns(unsigned long long int dt)
{
    return nanoseconds(dt);
}
inline Difference operator ""_ns(long double dt)
{
    return nanoseconds(dt);
}

inline Difference operator ""_us(unsigned long long int dt)
{
    return microseconds(dt);
}
inline Difference operator ""_us(long double dt)
{
    return microseconds(dt);
}

inline Difference operator ""_ms(unsigned long long int dt)
{
    return milliseconds(dt);
}
inline Difference operator ""_ms(long double dt)
{
    return milliseconds(dt);
}

inline Difference operator ""_s(unsigned long long int dt)
{
    return seconds(dt);
}
inline Difference operator ""_s(long double dt)
{
    return seconds(dt);
}

inline Difference operator ""_min(unsigned long long int dt)
{
    return minutes(dt);
}
inline Difference operator ""_min(long double dt)
{
    return minutes(dt);
}

inline Difference operator ""_hrs(unsigned long long int dt)
{
    return hours(dt);
}
inline Difference operator ""_hrs(long double dt)
{
    return hours(dt);
}

inline Difference operator ""_days(unsigned long long int dt)
{
    return days(dt);
}
inline Difference operator ""_days(long double dt)
{
    return days(dt);
}

inline Difference operator ""_Hz(unsigned long long int f)
{
    return hertz(f);
}
inline Difference operator ""_Hz(long double f)
{
    return hertz(f);
}

inline Difference operator ""_kHz(unsigned long long int f)
{
    return kilohertz(f);
}
inline Difference operator ""_kHz(long double f)
{
    return kilohertz(f);
}

inline Difference operator ""_MHz(unsigned long long int f)
{
    return megahertz(f);
}
inline Difference operator ""_MHz(long double f)
{
    return megahertz(f);
}

inline Difference operator ""_GHz(unsigned long long int f)
{
    return gigahertz(f);
}
inline Difference operator ""_GHz(long double f)
{
    return gigahertz(f);
}

} // namespace units

using Duration = Difference;

} } // namespace turtal::time

#endif // TURTAL_TIME_DIFFERENCE_HPP
