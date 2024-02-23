#include <iostream>
#include <vector>
using namespace std;

// Function to double each element of a vector passed by reference
void doubleElementsByRef(vector<int>& arr) {
    for (int& elem : arr) {
        elem *= 2;
    }
}

// Function to double each element of a vector passed by value (without reference)
void doubleElementsByValue(vector<int> arr) {
    for (int& elem : arr) {
        elem *= 2;
    }
}

int main() {
    vector<int> myVector = {1, 2, 3, 4, 5};

    // Print original vector
    cout << "Original vector: ";
    for (int elem : myVector) {
        cout << elem << " ";
    }
    cout << endl;

    // Call function to double elements of the vector by reference
    doubleElementsByRef(myVector);

    // Print modified vector after passing by reference
    cout << "Modified vector (by reference): ";
    for (int elem : myVector) {
        cout << elem << " ";
    }
    cout << endl;

    // Call function to double elements of the vector by value
    doubleElementsByValue(myVector);

    // Print original vector after passing by value (unchanged)
    cout << "Original vector after function call (by value): ";
    for (int elem : myVector) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}

// Original vector: 1 2 3 4 5 
// Modified vector (by reference): 2 4 6 8 10 
// Original vector after function call (by value): 2 4 6 8 10 

