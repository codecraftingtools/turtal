#include <turtal/turtal.hpp>
#include <iostream>

int main()
{
    using namespace turtal;
    using namespace turtal::clock;
    using namespace std;

    Time_Point t;
    Duration dt;
    cout << t.clock().id() << " " << dt.clock().id() << endl;
    return 0;
}
