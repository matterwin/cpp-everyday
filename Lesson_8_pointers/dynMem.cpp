#include <iostream>
using namespace std;

int main()
{
    // Request for memory space for an int
    int* pointsToAnAge = new int;

    // Use the allocated memory to store a number
    cout << "Enter your dog’s age: ";
    cin >> *pointsToAnAge;

    // Use indirection operator * to access value
    cout << "Age " << *pointsToAnAge << " is stored at 0x" << hex <<
    pointsToAnAge << endl;

    delete pointsToAnAge; // Release memory

    return 0;
}


// Enter your dog’s age: 9
// Age 9 is stored at 0x00338120
