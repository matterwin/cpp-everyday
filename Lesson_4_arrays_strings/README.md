# Arrays 

- an array is a collection of data of the same kind

- in C++, arrays enable you to store data elements of a type in the memory, in a sequential and ordered fashion

# Declaring and initializing static arrays

- array declaration in C++ follows a simple syntax:
ElementType ArrayName [constant_number of elements] = { optional init values };

int nums[5] = {1, 2, 3, 4, 5};
// array of len 5 with explicit init values

int nums[5] = {34, 56};
// array of len 5 but with the first 2 values explicitly labeled

int nums[] = {34, 54, 65};
// array with no explicit size but the explicit elements give the array its size of 3

- indexes in C++ and most languages start from 0 to array.

- the memory space occupied by the array is comprised of n blocks (n being the size of the array), each of equal size, that is defined by the type of data to be held in the array

- the amount of memory reserved by the compiler for the array is hence sizeof(array_type) * array_size

In general, the amount of memory reserved by the compiler for an array in bytes is
Bytes consumed by an array = sizeof(element-type) * Number of Elements


# Accessing Data Stored in an Arrays

- arrays are 0-indexed

When asked to access element at index N, the compiler uses the memory address of the
first element (positioned at index zero) as the starting point and then skips N elements
by adding the offset computed as N*sizeof(element) to reach the address containing
the (N+1)th element. 

The C++ compiler does not check if the index is within the actual
defined bounds of the array.

- if you manipulate or access data outside the array bounds, you are welcoming bugs

- * Listing 4.1 Declaring an Array of Integers and Accessing Its Elements


# Modifying Data Stored in an Arrays

- like many languages, modify an index by arr[index] = 4;
// at whatever index, the new value will be 4 if of course the arr is of type int

- * Listing 4.2 Assigning Values to Elements in an Array

DO always initialize arrays, or else
they will contain junk values.

DO always ensure that your arrays are
used within their defined boundaries.

DON’T ever access the Nth element
using index N, in an array of N
elements. Use index (N–1).

DON’T forget that the first element in
an array is accessed using index 0.


# Multidimensional Arrays

- a 2D array of integers would be represented asked
int solarPanels [2][3];

- could also init it as
int solarPanels [2][3] = {{0, 1, 2}, {3, 4, 5}};

- note the arrays do not have to be symtrical as shown above 

Note:
- even though C++ enables you to model multidimensional arrays, the memory where the array is contained is 1-dimensional
- so the compiler maps the multidimensional array into the memory space, which expands in only 1 direction


# Acessing Elements in a Multidimensional Array

int threeRowsThreeColumns [3][3] = {{-501, 205, 2016}, {989, 101, 206}, {303, 456, 596}};

- it goes by threeRowsThreeColumns[rows][columns] to access or change a value

- * Listing 4.3 Accessing Elements in a Multidimensional Array


# Dynamic Arrays

- choose to use dynamic arrays instead of static arrays when you are dealing with a variable change of size of an arrays
- choose dynamic arrays that optimize memory consumption and scale up depending on the demand for resources and memory at execution-time

std::vector is the library that is the dynamic array called vector

- * Listing 4.4 Dynamic Arrays

#include <vector>
using namespace std;

vector<int> myVector; // Creates an empty vector of integers

vector<int> myVector(5); // Creates a vector of 5 integers, initialized to 0

vector<int> myVector(5, 10); // Creates a vector of 5 integers, initialized to 101

vector<int> myVector = {1, 2, 3, 4, 5}; // Creates a vector with elements 1, 2, 3, 4, 5

vector<int> anotherVector = {6, 7, 8, 9, 10};
vector<int> myVector(anotherVector.begin(), anotherVector.end()); // Creates a vector with elements from anotherVector

vector<int> anotherVector = {6, 7, 8, 9, 10};
vector<int> myVector(std::move(anotherVector)); // Moves elements from anotherVector to myVector


# C style Character Strings

- C-style strings are a special case of an array of characters.

std::cout << "Hello World";

is equivalent to using the array declaration sayHello

char sayHello[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'};
std::cout << sayHello << std::endl;

Note:
- strings are essentially char pointers under the hood
char *str = "Hello";

-------------------------

More advanced stuff:
    char str[] = "Hello";
    char *ptr = str;  // Pointer to the beginning of the string
    
    // Change the character at index 1 to 'u'
    *(ptr + 1) = 'u';

or
    char *str = "Hello";
    // Attempting to change the character at index 1 (e.g., *(str + 1) = 'u';) would result in undefined behavior

so you cannot edit char* pointers as easily if it is not pointing to an array char, but it's useful for certain situations:

char *str = malloc(100 * sizeof(char)); // dynamic memory allocation for a 99 character string + 1 null terminator
free(str);

void processString(char *str) {
    // Process the string
}

char *str = malloc(100 * sizeof(char));
strcpy(str, "Hello");  // Copy a string into dynamically allocated memory
free(str);

Rabbit hole of dynamic memory stuff:
In C++, use delete to deallocate memory allocated with new.
In C, use free() to deallocate memory allocated with malloc(), calloc(), or realloc().
In modern C++, prefer using std::string for string handling to avoid manual memory management.


int* ptr = new int; // Allocate memory for a single integer
// Use ptr
delete ptr; // Free the allocated memory


char* str = (char*)malloc(100 * sizeof(char)); // Allocate memory for a string
// Use str
free(str); // Free the allocated memory


#include <string>
std::string str = "Hello"; // No need to manage memory manually

-------------------------

- note the last character is a null character '\0'
- this is called a string terminator
- it tells the compiler the string has ended 

When you embed a string literal in your code, the compiler does the job of adding a '\0' after it.
If you inserted '\0' anywhere in the middle of the array, it would not change the size of the array; 
    it would only mean that string-processing using the array as input would stop at that point

You could not write '0' directly because that would be accepted as character zero, which has the nonzero ASCII code 48.
- the '\' is an escaped character and is a special character that the compiler knows about

- * Listing 4.5 Null-Terminator in a string

Caution:
If you forget to add the '\0' when declaring and initializing the
character array in Listing 4.5 at Line 5, then expect the output
to contain garbled characters after printing “Hello World”; this is
because std::cout does not stop with printing the array until it
reaches a null character, even if it means exceeding the bounds
of the array.

This mistake can cause your program to crash and, in some
cases, compromise the stability of the system.

Caution:
Applications programmed in C (or in C++ by programmers who
have a strong C background) often use string copy functions
such as strcpy(), concatenation functions such as strcat(),
and strlen() to determine the length of a string, in addition to
others of this kind.

These functions take C-style strings as input and are dangerous
as they seek the null-terminator and can exceed the boundaries
of the character array they’re using if the programmer has not
ensured the presence of the terminating null.
