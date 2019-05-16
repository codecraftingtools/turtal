// Copyright (c) 2019 Jeffrey A. Webb

#include <turtal/turtal.hpp>
#include <iostream>

int main()
{
    using namespace turtal;
    using namespace std;
    using namespace turtal::time::units;
        
    for (int i=0; i<clock::max_count() - 2; i++) {
        cout << "added clock " << clock::add() << endl;
    }

    clock::ID Clk2{2};
    auto& p2 = clock::get_parameters_for(Clk2);
    p2.name("Clk2").time_scale_factor(2.0).time_offset_ns(200);

    clock::ID Clk3{3};
    auto& p3 = clock::get_parameters_for(Clk3);
    p3.name("Clk3").time_scale_factor(3.0).time_offset_ns(300);

    for (int i=0; i<clock::count(); i++) {
        auto p = clock::get_parameters_for(i);
        cout << "[" << i << "] " << p << endl;
    }

    time::Duration dt;
    cout << "dt " << dt << endl;
    cout << "seconds() " << seconds(3.0) << endl;
    dt = seconds(0.5);
    cout << "dt " << dt << endl;
    time::Duration dt2(Clk2, seconds(2));
    cout << "dt2 " << dt2 << endl;
    time::Duration dt3(seconds(3), Clk3);
    cout << "dt3 " << dt3 << endl;
    dt = dt2;
    cout << "dt " << dt << endl;
    dt2 = nanoseconds(10, clock::System);
    cout << "dt2 " << dt2 << endl;
    dt2 = dt;
    cout << "dt2 " << dt2 << endl;
    dt3 = seconds(1.0);
    dt2 = dt3;
    cout << "dt2 " << dt2 << endl;

    return 0;
}
