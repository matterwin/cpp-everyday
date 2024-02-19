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
