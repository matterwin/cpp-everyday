#include <iostream>
using namespace std;

int main()
{
    // Static array of 5 integers
    int myNumbers[5];

    // Array assigned to pointer to int
    int* pointToNums = myNumbers;

    // Display address contained in pointer
    cout << "pointToNums = 0x" << hex << pointToNums << endl;

    // Address of the first element of the array
    cout << "&myNumbers[0] = 0x" << hex << &myNumbers[0] << endl;

    return 0;
}


// pointToNums = 0x004BFE8C
// &myNumbers[0] = 0x004BFE8C
