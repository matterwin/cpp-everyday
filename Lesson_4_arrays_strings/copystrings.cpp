#include <iostream>
#include <string>

using namespace std;

int main()
{
    string greetString("Hello std::string!");
    cout << greetString << endl;

    cout << "Enter a line of text: " << endl;
    string firstLine;
    getline(cin, firstLine);

    cout << "Enter another: " << endl;
    string secondLine;
    getline(cin, secondLine);

    cout << "Result of concatenation: " << endl;
    string concatString = firstLine + " " + secondLine;
    cout << concatString << endl;

    cout << "Copy of concatenated string: " << endl;
    string aCopy;
    aCopy = concatString;
    cout << aCopy << endl;

    cout << "Length of concat string: " << concatString.length() << endl;

    return 0;
}

// Hello std::string!
// Enter a line of text:
// I love
// Enter another:
// C++ strings
// Result of concatenation:
// I love C++ strings
// Copy of concatenated string:
// I love C++ strings
// Length of concat string: 18
