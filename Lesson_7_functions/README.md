# functions

- function prototypes and function definition
- passing parameters and passing type
- overloading functions
- recursive functions
- C++11 lambda functions

- function prototypes like in needfuncs.cpp are declared on lines 7 and 8 to tell
the compiler what the terms Area and Circumference are when used in main()

- and Area and Circumference are defined below main()

- compartmentalizing the computation of area and Circumference allows for reusability and great for testing such functions individually


# What is a function prototype

double Area(double radius);
double Circumference(double radius);

- double is the return type value
- Area is the function name
- the function parameters are optional (), but here we have a list of parameters
separated by commas

Note 
- a parameter is a variable declared in a function's definition
- an argument is a value that is passed to a function when it is called

- without the prototype, when calling the function in main the compiler would not 
know what the terms Area and Circumference are.

The function prototypes
tell the compiler that Area and Circumference are functions; they take one parameter
of type double and return a value of type double. 

The compiler then recognizes these
statements as valid and the job of linking the function call to its implementation and
ensuring that the program execution actually triggers them is that of the linker.

- if you comment out the prototypes and you call that function before it is defined,
then you'll run in a compile error

- but if you define those functions first even without a prototype, no errors will appear if
you defined first before calling

- header files entail function prototypes for other files to see and use them without having to 
define a function everytime

Header files in C and C++ typically contain function prototypes, among other things. These prototypes allow other parts of the program to see and use the functions without having to redefine them each time they are needed.

By including the header file in other source files, those files gain access to the function prototypes declared within the header. This allows the compiler to check the validity of function calls, ensuring that the correct number and types of arguments are passed to the functions.

They provide abstraction

- See folder and code ./headers in more detail

#ifndef: This directive stands for "if not defined." It checks if a certain identifier (typically a macro) has not been defined previously. If it hasn't been defined, the code within the #ifndef block is processed by the preprocessor.

#define: Inside the #ifndef block, you define the identifier that you want to use as the guard. Typically, this identifier is the name of the header file itself, converted to uppercase and with underscores replacing any periods or other special characters.

#endif: Finally, at the end of the header file, you use #endif to close the conditional block.

Note of worthy:
The header guard macros solve these issues by ensuring that the contents of the header file are processed by the preprocessor only once within a single translation unit. Here's how it works:

The #ifndef directive checks whether a specific macro (usually named after the header file) has been defined. If it hasn't been defined, it means the current file hasn't been included before in the current translation unit.

Inside the #ifndef block, the macro is defined using #define, preventing subsequent inclusions of the same header file from reaching the contents of the block.

At the end of the header file, the #endif directive closes the conditional block.
This mechanism ensures that the contents of the header file are only processed once per translation unit, regardless of how many times the header file is included indirectly or directly in source files.


# function definition 

- the actual meat and potatoes -  the implementation of the function - is the definition

double Area(double radius){
    return Pi * radius * radius;
}

- a function definition is comprised of a statement block
- a return statement is necessary only if the function type is not void
- this function has a parameter radius that contains the radius as argument sent by the caller
to compute the area of the circle.

- you don't need to use all the parameters of course

- you can have function parameters with default values
see code default.cpp

- you can have multiple return statements, given conditionals, in a single function

# recursive functions

- where a function calls itself
see fib.cpp


# overloading functions

- functions with the same return type and same name but with different parameters are
said to be overloaded functions

Overloaded functions can be quite useful in applications where a function with a 
particular name that produces a certain type of output might need to be invoked with 
different sets of parameters

see code overloaded.cpp


# passing an array of values to a function

Arrays decay into pointers when passed to functions in C++. 

This means that when you pass an array to a function, you're actually passing a pointer 
to the first element of the array. 

Therefore, changes made to the elements of the array within the function will affect the 
original array outside the function.


# passing by reference

- C++ supports both pass by value and pass by reference.

// Function definitions (implementations)
double Area(double radius)
{
    return Pi * radius * radius;
}

Here, the parameter radius contains a value that is copied into it when the function is
invoked in main():

// Call function "Area"
cout << "Area is: " << Area(radius) << endl;

This means that the variable radius in main() is unaffected by the function call, as
Area() works on a copy of the value radius contains, held in radius.

- if you want to affect the value within the function along with the outside function, you
would do pass by reference

Note
Pass by value involves making a copy of the parameter being passed to the function.
Therefore, any changes made to the parameter inside the function do not affect the original 
variable outside the function.

Pass by reference, on the other hand, directly operates on the memory address of the variable being passed.
This means changes made to the parameter inside the function will directly affect the 
original variable outside the function.

In C++, you use the '&' symbol to denote passing by reference.
This allows you to modify the original variable from within the function.

// output parameter result by reference
void Area(double radius, double& result)
{
 result = Pi * radius * radius;
}

This sign & indicates to the compiler that the second
argument should NOT be copied to the function; instead, it is a reference to the variable
being passed

see code ref.cpp

Note:

In C++, arrays decay into pointers when passed to functions, so you don't need to explicitly 
use the & operator to pass them by reference. 

However, for other types like vectors or strings, which are objects, you typically do 
need to use the & operator to pass them by reference if you want the function to be able 
to modify the original object.

see refOther.cpp

- a function can only return one value using the return statement.
- so if your function needs to perform operations that affect many values required at they
caller, passing arguments by reference is one way to get a function to supply those many
modifications back to the calling module

The "caller" is the function that invokes or calls another function.
The "callee" is the function that is invoked or called by another function


# how function calls are handled by the microprocessor

- understanding how a function call is implemented on a microprocessor level will help you
understand why C++ gives you the option of programming inline functions

- a function call means that the microprocessor jumps to executing the next instruction
belonging to the called function at a nonsequential memory location

- after it is done with executing the instructions in the function, it returns to where
it left off 

- to implement this logic, the compiler converts your function call into a CALL instruction 
for the microprocessor.

- this instruction is accompanied by the address in memory the next instruction needs
to be taken from -- this address belongs to your function routine

- when the microprocessor encounters CALL, it saves the position of the instruction to 
be executed after the function call on the stack and jumps to the memory location contained
in the CALL instruction 

- this memory location contains instructions belonging to the function 

- the microprocessor executes them until it reaches the RET statement
(the microprocessor's code for return programmed by you)

- the RET statement results in the microprocessor popping that address from the stack
stored during the CALL instruction

- this address contains the location in the calling function where the execution needs
to continue from

- thus, the microprocessor is back to the caller and continues where it left off


Note
The nature of the stack makes it optimal for handling function calls. 

When a function is called, all local variables are instantiated on the stack—that is, 
pushed onto the stack.

When the function ends, they’re simply popped off it, and the stack pointer
returns to where it originally was.


# inline functions

- a regular function call is translated into a CALL instruction, which results in 
stack operations and microprocessor execution shift to the function and so only

- all this happens super fast

- but what if our function is very simple like

double GetPi()
{
 return 3.14159;
}

The overhead of performing an actual function call on this might be quite high for the
amount of time spent actually executing GetPi().

This is why C++ compilers enable the programmer to declare such functions as inline. 

Keyword inline is the programmers’ request that these functions be expanded 
inline where called.

inline double GetPi()
{
 return 3.14159;
}

Functions that perform simple operations like doubling a number are good candidates for
being inlined, too

see code inline.cpp


- compilers typically see this keyword as a request to place the contents of the function 
DoubleNum() in inline.cpp directly where the function has been invoked in main(),
which increases the speed of the code.

Classifying functions as inline can also result in a lot of code bloat, especially if the
function being inline does a lot of sophisticated processing

Using the inline keyword should be kept to a minimum and reserved for only those 
functions that do very little and need to do it with minimal overhead

Note

Most modern C++ compilers offer various performance
optimization options. Some, such as the Microsoft C++ Compiler,
offer you to optimize for size or speed. Optimizing for size may
help in developing software for devices and peripherals where
memory may be at a premium. When optimizing for size, the
compiler might often reject many inline requests as that might
bloat code.

When optimizing for speed, the compiler typically sees and utilizes opportunities to inline code where it would make sense and
does it for you—sometimes even in those cases where you have
not explicitly requested it.


# auto for function type

- just like variables you can use auto for the type of a function (C++14)

Instead of specifying the return type, you would use auto and
let the compiler deduce the return type for you on the basis of return values you program 


# lambda functions

- lesson 22 dives deeper into lambda functions

Lambda functions were introduced in C++11 and help in the usage of STL algorithms to
sort or process data

The syntax of a lambda function is the following:
[optional parameters](parameter list){ statements; }

Lambda functions were introduced in C++11 and help in the usage of STL algorithms to
sort or process data. 

Typically, a sort function requires you to supply a binary predicate.

This is a function that compares two arguments and returns true if one is less than the
other, else false, thereby helping in deciding the order of elements in a sort operation.

Such predicates are typically implemented as operators in a class, leading to a tedious bit
of coding. Lambda functions can compact predicate definitions

see code lambda.cpp


The program contains integers pushed into a dynamic array provided by the C++
Standard Library in the form of a std::vector in Lines 15–19. 

The function DisplayNums() uses the STL algorithm for_each to iterate through each 
element in the array and display its value. 

In doing so, it uses a lambda function in Line 8. 

std::sort used in Line 25 also uses a binary predicate (Line 26) in the form of
a lambda function that returns true if the second number is smaller than the first,
effectively sorting the collection in an ascending order
