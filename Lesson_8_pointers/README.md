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

-  
