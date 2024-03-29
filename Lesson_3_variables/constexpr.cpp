#include <iostream>
constexpr double GetPi() { return 22.0/7; }
constexpr double TwicePi() { return 2*GetPi(); }

int main(){
    using namespace std;
    const double pi = 22.0 / 7;

    cout << "const pi contains value " << pi << endl;
    cout << "constexpr GetPi() returns value " << GetPi() << endl;
    cout << "constexpr TwicePi() returns value " << TwicePi() << endl;    

    return 0;
}

// constant pi contains value 3.14286
// constexpr GetPi() returns value 3.14286
// constexpr TwicePi() returns value 6.28571