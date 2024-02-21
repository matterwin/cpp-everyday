#include <iostream>
#include "circle.h"

using namespace std;

int main()
{
    cout << "Enter radius: ";
    double radius = 0;
    cin >> radius;

    // Call function "Area"
    cout << "Area is: " << Area(radius) << endl;

    // Call function "Circumference"
    cout << "Circumference is: " << Circumference(radius) << endl;

    return 0;
}

