#include <iostream>
using namespace std;

int main()
{
    int dogsAge = 30;
    cout << "Initialized dogsAge = " << dogsAge << endl;

    int* pointsToAnAge = &dogsAge;
    cout << "pointsToAnAge points to dogsAge" << endl;

    cout << "Enter an age for your dog: ";

    // store input at the memory pointed to by pointsToAnAge
    cin >> *pointsToAnAge;

    // Displaying the address where age is stored
    cout << "Input stored at 0x" << hex << pointsToAnAge << endl;

    cout << "Integer dogsAge = " << dec << dogsAge << endl;

    // Changing dogsAge to 4 through the pointer
    *pointsToAnAge = 4;

    cout << "Changed dogsAge through the pointer: " << dogsAge << endl;

    return 0;
}


// Initialized dogsAge = 30
// pointsToAnAge points to dogsAge
// Enter an age for your dog: 10
// Input stored at 0x0025FA18
// Integer dogsAge = 10
// Changed dogsAge through the pointer: 4
