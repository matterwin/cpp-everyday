#include <iostream>
using namespace std;

int main()
{
    int age = 30;
    int dogsAge = 9;

    cout << "Integer age = " << age << endl;
    cout << "Integer dogsAge = " << dogsAge << endl;

    int* pointsToInt = &age;
    cout << "pointsToInt points to age" << endl;

    // Displaying the value of pointer
    cout << "pointsToInt = 0x" << hex << pointsToInt << endl;

    // Displaying the value at the pointed location
    cout << "*pointsToInt = " << dec << *pointsToInt << endl;

    pointsToInt = &dogsAge;
    cout << "pointsToInt points to dogsAge now" << endl;

    cout << "pointsToInt = 0x" << hex << pointsToInt << endl;
    cout << "*pointsToInt = " << dec << *pointsToInt << endl;

    return 0;
}


// Integer age = 30
// Integer dogsAge = 9
// pointsToInt points to age
// pointsToInt = 0x0025F788
// *pointsToInt = 30
// pointsToInt points to dogsAge now
// pointsToInt = 0x0025F77C
// *pointsToInt = 9
