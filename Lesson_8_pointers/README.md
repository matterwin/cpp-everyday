# about

- pointers
- free store
- operators new and delete
- references vs pointers


# What is a pointer

- a pointer is also a variable - one that stores an address in memory

- just like how a variable of type int stores an integer, a pointer variable is
used to contain a memory address

- since a pointer is a variable it also occupies space in memory

- what's special about pointers is that the value contained in a pointer 
is interpreted as a memory address

- a pointer is a special variable that points to a location in memory

Note:
memory addresses are expressed in hexadecimal notation 

hexadecimal notation starts with 0x and it is base 16, so 0-9 and A-F

0xA is 10 in decimal for example


# declaring a pointer

- pointers are variables, so they need to be declared as you would expect

- you would declare a pointer to point to a specific value type (for ex int)

- this would mean that the address contained in the pointer points to a location
in memory that holds an integer

- you can also specify a pointer to a block of memory (a void pointer)

A pointer being a variable needs to be declared like all variables do:
PointedType * PointerVariableName;

- as in the case for most variables, unless you initialize a pointer it will
contain a random value

- you don't want a random memory address to be accessed, so it's best to initialize
a pointer to NULL or nullptr

NULL is a value that can be checked against and one that cannot be a
memory address:

PointedType * PointerVariableName = NULL; // initializing value

Thus, declaring a pointer to an integer would be

int *pointsToInt = NULL;

- uninitialized pointers can try to access invalid memory locations, resulting in 
a crash


# determing the address of a variable using the reference operator &

- if varName is a variable, &varName gives the address in memory where its value is placed

So, if you have declared an integer, using the syntax that you’re well acquainted 
with, such as
int age = 30;

&age would be the address in memory where the value (30) is placed.

** see code address.cpp

You know that the amount of memory consumed by a variable is
dependent on its type. 

Listing 3.4 in Lesson 3 uses sizeof()
to demonstrate that the size of an integer is 4 bytes (on my
system, using my compiler). 

So, using the preceding output that says that integer age is located at 
address 0x0045FE00 and using the knowledge that sizeof(int) is 4, you know that
the four bytes located in the range 0x0045FE00 to 0x0045FE04
belong to the integer age.


# using pointers to store addresses

- you've learned how to declare pointers and how to determine the address of a variable

- you've learned that pointers are variables that are used to hold memory addresses

- it's time to connect the dots and use pointers to store the addresses obtained
using the reference operator (&)

Assume a variable declaration of the types you already know:
// Declaring a variable

Type VariableName = InitialValue;

- to store the address of this variable in a pointer, you would declare a pointer
to the same Type and initialize the pointer to the variable's address using
the reference operator (&)

// Declaring a pointer to Type and initializing to address
Type* Pointer = &Variable;

Thus, if you have declared an integer, using the syntax that you’re well acquainted with, such as

int age = 30;

You would declare a pointer to the type int to hold the actual address where age is
stored, like this:

int* pointsToInt = &age; // Pointer to integer age

** see addressTwo.cpp

- the code is the same as before but now the address is first assigned to a pointerand the value of the pointer (now the address) is displayed via cout

Now that you know how to store an address in a pointer variable, it is easy to imagine
that the same pointer variable can be reassigned a different memory address and made to
point to a different value, as shown in addressThree.cpp


# access pointed data using the dereference opearator (*)

- you have a pointer to data, containing a valid address

- how do you access that location -- that is, get or set data at that location?

- the answer lies in using the dereference operator (*)

- basically, if you have a valid pointer pData, use *pData to access the value stored at the address contained in the pointer

** see code deref.cpp

When the dereference operator (*) is used, the application essentially uses the address
stored in the pointer as a starting point to fetch 4 bytes from the memory that belong to
an integer (as this is a pointer to integers and sizeof(int) is 4).

Thus, the validity of
the address contained in the pointer is absolutely essential. By initializing the pointer to
&age in Line 11, you have ensured that the pointer contains a valid address. When you
don’t initialize the pointer, it can contain any random value (that existed in the memory
location where the pointer variable is located) and dereference of that pointer usually
results in an Access Violation—that is, accessing a memory location that your application
was not authorized to

The dereferencing operator (*) is also called the indirection
operator.

You have used the pointer in the preceding sample to read (get) values from the pointed
memory location. Listing 8.5 shows what happens when *pointsToInt is used as an
l-value—that is, assigned to instead of just being accessed.

see code deref2.cpp

Any change to that memory location where dogsAge is stored,
and where pointsToAnAge points to, made using one is going to be reflected in the
other.


# what is the sizeof() of a pointer?


