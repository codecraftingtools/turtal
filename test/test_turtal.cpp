#include <turtal/turtal.hpp>
#include <iostream>

int main()
{
    using namespace turtal;
    using namespace std;

    const Clock_ID Other_Clock{2};
    Duration<clock::System> dt;
    dt = seconds(1.0);
    Duration<Other_Clock> dt2(nanoseconds(1));
    auto t = Time_Point<clock::System>::from_seconds(3.0);
    cout << dt.Clock_ID << " " << Duration<clock::System>::Clock_ID << endl;
    cout << t.seconds() << " " << dt.nanoseconds() << endl;

    return 0;
}
