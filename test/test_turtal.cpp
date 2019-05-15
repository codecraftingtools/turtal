// Copyright (c) 2019 Jeffrey A. Webb

#include <turtal/turtal.hpp>
#include <iostream>

int main()
{
    using namespace turtal;
    using namespace std;
    
    Clock_Parameters Other_Clock_{2, "System"};
    Clock_ID Other_Clock{Other_Clock_.id()};
    Clock_Parameters Other_Clock2_{3, "System"};
    Clock_ID Other_Clock2{Other_Clock2_.id()};
    Duration dt;
    cout << dt.clock_id().value() << endl;
    dt = seconds(1.0);
    cout << dt.clock_id().value() << " " << dt.nanoseconds() << endl;
    Duration dt2(Other_Clock);
    dt2 = nanoseconds(200);
    cout << dt2.clock_id().value() << " " << dt2.nanoseconds() << endl;
    dt2 = Duration(Other_Clock2);
    cout << dt2.clock_id().value() << " " << dt2.nanoseconds() << endl;
    dt2 = dt;
    cout << dt2.clock_id().value() << " " << dt2.nanoseconds() << endl;
    return 0;
}
