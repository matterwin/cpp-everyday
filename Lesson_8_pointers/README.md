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

- you have learned that the pointer is just another variable that contains a memoryaddress

- hence, irrespective of the type that is being pointed to, the content of a pointer is an address 
--- a number

- the length of an address, that is the number of bytes required to store it, is a constant for a given system

- the sizeof() a pointer is hence dependent on the compiler and the OS the program has been compiled for
and is not dependent on the nature of the data being pointed pointsToAnAge

see code sizeofptr.cpp

- as you see in the code and output, the sizeof all the pointers is 4 bytes

- this is b/c the amount of memory consumed by a pointer that stores an address is the same, 
irrespective of whether the memory at the address contains 1 byte or 8 bytes of data

Note:
The output was generated when the code was compiled using a
32-bit compiler. If you use a 64-bit compiler and run the program
on a 64-bit system, you might see that the sizeof your pointer
variable is 64 bits—that is, 8 bytes.


# dynamic memory allocation

- when you delcare an array such as 
int nums[100]; // a static array of 100 integers

- your program has 2 problems:

1. you are limited to 100 integers
2. you are reducing system performance in cases where only 1 number needs to be stored, yet you
reserved space for 100

- this problem exists b/c the memory allocation in a static declared array is static and fixed by the compiler

- to program an application that optimally consumes memory resources on the basis of the needs of the user/
programer, you need to use dynamic memory allocation

- this enables you to allocate more when you need more memory and release memory that you have in excess

- C++ offers you two operators, new and delete, to help you better manage the memory consumption
of your program

- pointers beings variables that are used to contain memory addresses play a critical role in efficient
dynamic memory allocation

Note:
In C++:
new: Allocates memory for a single object on the heap and calls the object's constructor.

delete: Deallocates memory for a single object on the heap and calls the object's destructor.


In C:
malloc: Allocates a block of memory of a specified size on the heap. It returns a pointer to the allocated memory.

calloc: Allocates a block of memory for an array of elements, initialized to zero. It takes the number of elements and 
the size of each element as arguments.

free: Deallocates memory that was previously allocated by malloc, calloc, or realloc.

- in C++ it's best to use new and delete b/c they are better suited for object oriented applications, but C++ still has access to the 
C standard library, so you could still use C's memory allocation operators


# using new and delete

- use new to allocate new memory blocks

- the most frequently used form of new returns a pointer to the requested memory if successful or else throws an exception

- when using new, you need to specify the data type for which the memory is being allocated:

Type* Pointer = new Type; // request memory for one element

- you can also specify the number of elements you want to allocate that memory for 
(when you need to allocate memory for more than one element)

Type* Pointer = new Type[numElements]; // request memory for numElements

- thus, if you need to allocate integers:

int* pointToAnInt = new int; // get a pointer to an integer
int* pointToNums = new int[10]; // pointer to a block of 10 integers

Note that new indicates a request for memory. There is no
guarantee that a call for allocation always succeeds because
this depends on the state of the system and the availability of
memory resources

- every allocation using new needs to be eventually released using an equal and opposite de-allocation via delete

Type* pointer = new Type; // allocate memory
delete pointer; //release memory allocated above

- this rule also applies when you request memory for multiple elements

Type* pointer = new int[10]; // allocate a block
delete[] pointer; // release block allocated above

- if you don't release allocated memory after you stop using it, this memory remains reserved and allocated for your application

- this in turn reduces the amount of system memory available for applications to consume and possibly even makes the execution
of your application slower

- this is called a leak and should be avoided at all costs

see code dynMem.cpp

- note in the code that new returns a pointer and that is the reason it is assigned to one
- the age entered by the user is stored in this newly allocated memory using cin and the dereference operator (*) against
and also displays the memory address where the value is stored

Note that the address contained in pointsToAnAge in
Line 13 still is what was returned by new in Line 6 and hasn’t changed since.

Operator delete cannot be invoked on any address contained in
a pointer, rather only those that have been returned by new and
only those that have not already been released by a delete.

- note that when you allocate for a range of elements using new[...], you would de-allocate using delete[]
see code dynMem2.cpp

Operators new and delete allocate memory from the free store.
The free store is a memory abstraction in the form of a pool of
memory where your application can allocate (that is, reserve)
memory from and de-allocate (that is, release) memory to.


# incrementing and decrementing operators ++ and -- on pointers

- a pointer contains a memory address

- for ex, in one of those code examples, the pointer to an integer in such example contains 0x002EFB34 -- the address where
the integer is placed

- the integer itself is 4 bytes long and hence occupies 4 places in memory from 0x002EFB34 to 0x002EFB37

- incrementing this pointer using ++ would NOT result in the pointer pointing to 0x002EFB35, for pointing to the middle of an integer
would literally be pointless 

- an increment or decrement operation on a pointer is interpreted by the compiler as your need to point to the next value in 
the block of memory, assuming it to be of the same type, and NOT to the next byte (unless the value type is 1 byte long like a char, for ex) 

- so incrementing a pointer that points to an address like above would result in it being incremented by 4 bytes (int is 4 bytes on 32bit machine)

- using ++ on this pointer is telling the compiler that you want it to point to the next consecutive integer
- hence after ++, the pointer would then point to 0x002EFB38

- similarly, adding 2 to this pointer would result it in moving 2 integers ahead, that is 8 bytes ahead

- later you will see this behavior displayed by pointers and indexes used in arrays

- decrementing pointers via -- demonstrates the same effect
- the address value contained in the pointer is reduced by the sizeof that data type it is being pointed those

What Happens When You Increment or Decrement a Pointer?
The address contained in the pointer is incremented or decremented by the sizeof
the type being pointed to (and not necessarily a byte). 
This way, the compiler ensures that the pointer never points to the middle or end of data placed in the 
memory; it only points to the beginning.
If a pointer has been declared as

Type* pType = Address;

++pType would mean that pType contains (and hence points to) Address +
sizeof(Type).

- see code incDecPtrs.cpp

- the code demonstrates 2 ways of incrementing pointers
1. one uses an offset value via counter variable + pointer to place the value at on offset from the beginning of the allocated memory block
(or meaning from the where the pointer is which is the start of the memory block)
2. one uses the ++ to increment the address contained in the pointer variable to the next valid integer in the allocated memory

Note:
it's necessary to bring the pointer back to its original position before calling delete[] because the pointer passed to delete[]
must point to the beginning of the memory block that was allocated with new[]. 

If you move the pointer (as you did in the code with pointsToInts++), it will no longer point to the start of the allocated
memory block, which can lead to undefined behavior when delete[] is called


 # using the const keyword on pointers

- const on a variable ensures that the value of the variable is fixed as the initialization value for the life of the variable
- the value of a const-variable cannot be changed, and therefore it cannot be used as an l-value

- pointers are variables too, hence the const keyword that is relevant to variables is relevant to pointers as well.

- however, pointers are a special kind of variable as they contain a memory address and are used to modify memory at that address

 Thus, when it comes to pointers and constants, you have the following combinations:

 ■ The address contained in the pointer is constant and cannot be changed, yet the data at that address can be changed:
int daysInMonth = 30;
int* const pDaysInMonth = &daysInMonth;
*pDaysInMonth = 31; // OK! Data pointed to can be changed
int daysInLunarMonth = 28;
pDaysInMonth = &daysInLunarMonth; // Not OK! Cannot change address!

 ■ Data pointed to is constant and cannot be changed, yet the address contained in the
pointer can be changed—that is, the pointer can also point elsewhere:
int hoursInDay = 24;
const int* pointsToInt = &hoursInDay;
int monthsInYear = 12;
pointsToInt = &monthsInYear; // OK!
*pointsToInt = 13; // Not OK! Cannot change data being pointed to
int* newPointer = pointsToInt; // Not OK! Cannot assign const to non-const

 ■ Both the address contained in the pointer and the value being pointed to are
 constant and cannot be changed (most restrictive variant):
int hoursInDay = 24;
const int* const pHoursInDay = &hoursInDay;
*pHoursInDay = 25; // Not OK! Cannot change data being pointed to
int daysInMonth = 30;
pHoursInDay = &daysInMonth; // Not OK! Cannot change address


These different forms of const are particularly useful when passing pointers to
functions. Function parameters need to be declared to support the highest possible
(restrictive) level of const-ness, to ensure that a function does not modify the pointed
value when it is not supposed to. This will keep programmers of your application from
making unwanted changes to pointer values or data.


# passing pointers to functions

- pointers are an effective way to pass memory space that contains relevant data for functions to work one

- the memory space shared can also return the result of an operation

When using a pointer with functions, it becomes important to ensure that the
called function is only allowed to modify parameters that you want to let it modify, but
not others

 For example, a function that calculates the area of a circle given radius sent as
a pointer should not be allowed to modify the radius. This is where you use the keyword
const to control what a function is allowed to modify and what it isn’t as demonstrated

- see code constPtrs.cpp

in the code you can see the diff types of const pointers, and notice how you check first the validity of a pointer before
using it in order to avoid bugs and crashes


# similarities between arrays and pointers

- when you declare an array of integers
int myNumbers[5];

you tell the compiler to allocate a fixed amount of memory to hold 5 integers and give you a pointer to the first element 
in that array that is identified by the name you assign the array variable

- i.e. myNumbers is a pointer to the 1st element myNumbers[0] 

- see code arrPtrs.cpp

- in this code you can see that arrays is akin to a pointer

- should you need to access the 2nd element via the expression myNumbers[1], you can also access the same using the pointer
pointToNums with the syntax *(pointToNums + 1)

- and so on for each element like elem 3 is myNumbers[2] or *(pointToNums + 2) 

- b/c array variables are essentially pointers, it should be possible to use the de-reference operator (*) that you have used with pointers
to work with arrays

- similarly, it should be possible to use the array opeartor ([]) to work with pointers 

- see code arrPtrs2.cpp

Thus, what this program demonstrates is that both array myNumbers and pointer
pointToNums actually exhibit pointer behavior. In other words, an array declaration is
similar to a pointer that will be created to operate within a fixed range of memory. Note
that one can assign an array to a pointer as in Line 11, but one cannot assign a pointer to
an array. This is because by its very nature, an array like myNumbers is static and cannot
be used as an l-value. myNumbers cannot be modified.

Remember:
It is important to remember that pointers that are allocated
dynamically using operator new still need to be released using
operator delete, even if you accessed data using syntax commonly used with static arrays.
If you forget this, your application leaks memory, and that’s bad.


# common programming mistakes when using pointers

C++ enables you to allocate memory dynamically so that you can optimize and control
the memory consumption of your application. Unlike newer languages such as C#
and Java that are based on a runtime environment, C++ does not feature an automatic
 garbage collector that cleans up the memory your program has allocated but can’t use.
This incredible control over managing memory resources using pointers is accompanied
by a host of opportunities to make mistakes.


# memory leaks

- the longer a C++ application runs, the larger amount of memory they consume and the slower the system gets

- this happens when the programmer didn't ensure that his application releases memory allocated dynamically using new with a 
matching call to delete after the block of memory is no longer required

It is up to you—the programmer—to ensure that all allocated memory is also released
by your application. Something like this should never be allowed to happen:

int* pointToNums = new int[5]; // initial allocation
// use pointToNums
...
// forget to release using delete[] pointToNums;
...
// make another allocation and overwrite
pointToNums = new int[10]; // leaks the previously allocated memory


# when pointers don't point to valid memory locations

- when you dereference a pointer via (*) to access the pointed value, you need to be sure that the pointer contains a valid
memory location, or else your program will either crash or misbehave.

Pointers can be invalid for a range of reasons, primarily
due to poor programming and memory management.

- see code poorPtr.cpp

- many problems with that code like 
1. the ptr wasn't initialized to nullptr
2. if the if statement never gets executed, then the ptr remains invalid and if you deref that ptr, a crash will or can happen
3. deleting an unallocated pointer that hasn't been declared via new is also a big no no

A better (safer, more stable) version of this program would be one where pointers are initialized, used where their values are valid, 
and released only once but only when valid.


# dangling pointers (also called stray or wild pointers)

- note that any valid pointer is invalid after it has been released using delete 

- to avoid any problems, some programmers follow the convention of assigning NULL to a pointer when initializing it or after 
it has been deleted

- they also always check a pointer for validity (by comparing against NULL) before dereferencing it using (*)

- see code poorPtrFixedMistake.cpp for fixed mistakes of prev example

- note 
We also initialized the
Boolean value being pointed to, to true in Line 11. This data initialization doesn’t add to
the stability of the program but to the reliability of the output.


# checking whether the allocation request using new succeeded

- in our code from this point, we assumed that new will return a valid pointer to a block of memory

Indeed, new usually succeeds unless the application asks for an unusually
large amount of memory or if the system is in such a critical state that it has no memory
to spare.

C++ provides you with two possible methods to ensure that your pointer is valid before you use it

The default method—one that we have been using thus far—uses exceptions wherein unsuccessful
allocations result in an exception of the type std::bad_alloc to be thrown

An exception results in the execution of your application being disrupted, and unless you have
programmed an exception handler, your application ends rather unelegantly with an
error message “unhandled exception.”

- see code exception.cpp to see how error handling can be used to check for failed memory allocation requests

Had I not programmed an exception handler (the catch block you see in Lines 14–17), the program would
have ended disgracefully

The exception handling try-catch construct thus helped the application in making a
controlled exit after informing the user that a problem in memory allocation hampers
normal execution.

For those who don’t want to rely on exceptions, there is a variant of new called
new(nothrow). This variant does not throw an exception when allocation requests
fail, rather it results in the operator new returning NULL

- see code nothrow.cpp

Note:
In C++, the new operator will return a null pointer (nullptr) if the memory allocation fails and cannot be completed successfully.
So, you could just check always if the ptr is not a nullptr


DO always initialize pointer variables,
or else they will contain junk values.
These junk values are interpreted as
address locations—ones your application is not authorized to access.
If you cannot initialize a pointer to
a valid address returned by new
during variable declaration, initialize
to NULL.

DO ensure that your application is
programmed in a way that pointers are used when their validity is
assured, or else your program might
encounter a crash.

DO remember to release memory
allocated using new by using
delete, or else your application will
leak memory and reduce system
 performance.

DON’T access a block of memory
or use a pointer after it has been
released using delete.

DON’T invoke delete on a memory
address more than once.

DON’T leak memory by forgetting to
invoke delete when done using an
allocated block of memory.


# what is a reference?

- a reference is an alias for a variable 
- when you declare a reference, you need to initialize it to a variable

- thus, the reference variable is just a different way to access the data stored in the variable being referenced

You would declare a reference using the reference operator (&) as seen in the following
statement:

VarType original = Value;
VarType& ReferenceVariable = original;

Difference btw reference variables and memory address via &

int x = 10;
int& refX = x; // refX is a reference to x
refX = 20; // Modify the value of x through the reference variable refX

whereas

int x = 10;
int* ptrX = &x; // ptrX stores the memory address of x
*ptrX = 20; // Modify the value of x through the pointer variable ptrX

- see code refVars.cpp

references are true aliases—that is, just another name for the variable they are referencing


# what makes references useful?

- references enable you to work with the memory locations they are initialized to.
- this makes references particularly useful when programming functions

- see code vectorsRef.cpp

a typical function is declared like this:
ReturnType DoSomething(Type parameter);

Function DoSomething() is invoked like this:
ReturnType Result = DoSomething(argument); // function call

The preceding code would result in the argument being copied into Parameter, which is
then used by the function DoSomething(). This copying step can be quite an overhead if
the argument in question consumes a lot of memory. Similarly, when DoSomething()
returns a value, it is copied again into Result. It would be ideal if we could avoid or
eliminate the copy steps, enabling the function to work directly on the data in the caller’s
stack. 

References enable you to do just that.

A version of the function without the copy step looks like this:
ReturnType DoSomething(Type& parameter); // note the reference&

This function would be invoked as the following:
ReturnType Result = DoSomething(argument);

- as the argument is being passed by reference, Parameter is not a copy of argument rather an alias of the latter

- also, a function that accepts a parametere as a reference can optionally return values using reference parameters

- see code refBasic.cpp


# using keyword const on references

You might need to have references that are not allowed to change the value of the
 original variable being aliased. Using const when declaring such references is the way
to achieve that:

int original = 30;
const int& constRef = original;
constRef = 40; // Not allowed: constRef can’t change value in original
int& ref2 = constRef; // Not allowed: ref2 is not const
const int& constRef2 = constRef; // OK


# passing arguments by reference to functions

- there are significant performance improvements by using references on parameters, since values are not copied

However, as the called function works using parameters
directly on the stack of the calling function, it is often important to ensure that the called
function cannot change the value of the variable at the caller’s end.

- and that is only the case if you want that to be as so, and you use const for that

- a const reference parameter cannot be used as an l-value, so any attempt at assigning to it causes a compilation failure

- see code constRefParam.cpp
