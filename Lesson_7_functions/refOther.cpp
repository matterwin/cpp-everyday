#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to modify an integer
void modifyInteger(int& x) {
    x += 10;
}

// Function to modify a vector
void modifyVector(vector<int>& vec) {
    vec.push_back(100);
}

// Function to modify a string
void modifyString(string& str) {
    str += " World!";
}

int main() {
    // Modifying an integer
    int num = 5;
    modifyInteger(num);
    cout << "Modified integer: " << num << endl;  // Output will be 15

    // Modifying a vector
    vector<int> myVector = {1, 2, 3};
    modifyVector(myVector);
    cout << "Modified vector: ";
    for (int elem : myVector) {
        cout << elem << " ";  // Output will be 1 2 3 100
    }
    cout << endl;

    // Modifying a string
    string myString = "Hello";
    modifyString(myString);
    cout << "Modified string: " << myString << endl;  // Output will be "Hello World!"

    return 0;
}


