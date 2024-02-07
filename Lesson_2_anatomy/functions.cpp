#include <iostream>
using namespace std;

// Declare a function
int DemoConsoleOutput();

int main(){
    // Call i.e. invoke the function
    DemoConsoleOutput();

    return 0;
}

// Define i.e. implement the previously declared function
int DemoConsoleOutput(){
    cout << "This is a demo call" << endl;
    return 0;
}