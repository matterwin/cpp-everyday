#include <iostream>
using namespace std;

int main()
{
    cout << "How many integers you wish to enter? ";
    int numEntries = 0;
    cin >> numEntries;

    int* pointsToInts = new int[numEntries];

    cout << "Allocated for " << numEntries << " integers" << endl;
    for (int counter = 0; counter < numEntries; ++counter)
    {
        cout << "Enter number " << counter << ": ";
        cin >> *(pointsToInts + counter);
    }

    cout << "Displaying all numbers entered: " << endl;
    for (int counter = 0; counter < numEntries; ++counter)
        cout << *(pointsToInts++) << " ";

    cout << endl;

    // Return pointer to initial position
    pointsToInts -= numEntries;

    // Done with using memory? Release
    delete[] pointsToInts;

    return 0;
}


// How many integers you wish to enter? 2
// Allocated for 2 integers
// Enter number 0: 8774
// Enter number 1: -5
// Displaying all numbers entered:
// 8774 -5
// Another run:
// How many integers you wish to enter? 5
// How many integers you wish to enter? 5
// Allocated for 5 integers
// Enter number 0: 543
// Enter number 1: 756
// Enter number 2: 2017
// Enter number 3: -101
// Enter number 4: 101010012
// Displaying all numbers entered:
// 543 756 2017 -101 101010012


