#include <iostream>
using namespace std;

int main()
{
    int age = 30;
    int* pointsToInt = &age; // pointer initialized to &age

    // Displaying the value of pointer
    cout << "Integer age is at 0x" << hex << pointsToInt << endl;

    return 0;
}


// Integer age is at: 0x0045FE00
