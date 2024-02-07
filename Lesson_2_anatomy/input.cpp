#include <iostream>
#include <string>
// using namespace std;

int main(){
    // Declare a variable to store an integer
    int inputNumber;

    std::cout << "Enter an integer ";

    // store integer given user input
    std::cin >> inputNumber;

    // the same with text i.e. string data
    std::cout << "Enter your name: ";
    std::string inputName;
    std::cin >> inputName;

    std::cout << inputName << " entered " << inputNumber << std::endl;

    return 0;
}