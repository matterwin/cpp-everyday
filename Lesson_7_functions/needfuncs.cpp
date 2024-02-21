#include <iostream>
using namespace std;

const double Pi = 3.14159265;

// Function Declarations (Prototypes)
// double Area(double radius);
// double Circumference(double radius);
// Function definitions (implementations)
double Area(double radius)
{
    return Pi * radius * radius;
}

double Circumference(double radius)
{
    return 2 * Pi * radius;
}


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


// Enter radius: 6.5
// Area is: 132.732
// Circumference is: 40.8407



