# learn

- classes and objects
- how classes help consolidate data with functions that work on them
- constructors, copy constructors, deconstructors
- what the move constructor is
- encapsulation and abstraction
- this pointer
- struct and how it differs from class


# declaring a class

- declare a class via class keyword followed by the name of the class,
followed by a statement block {...} that encloses a set of memeber attributes and 
member functions with curly braces, and finally terminated by a semicolon ;

- a declaration of a class tells the compiler about the class and its properties

A class that models a human looks like the following (ignore syntactic short-comings for
the moment):

class Human
{
 // Member attributes:
 string name;
 string dateOfBirth;
 string placeOfBirth;
 string gender;
 // Member functions:
 void Talk(string textToTalk);
 void IntroduceSelf();
 ...
};

- members of a class are the functions and attributes 

- encapsulation is the ability to logically group data and functions that work
using it

- methods are another name for the functions of a class


# on object as an instance of a class

- the real-world avatar of a class at program execution time is an object

- to use the members of a class, you typically create an instance of that class 
i.e. an object

Creating an object of type class Human is similar to creating an instance of another
type, say double:

double pi= 3.1415; // a variable of type double
Human firstMan; // firstMan: an object of class Human

Alternatively, you would dynamically create an instance of class Human using new as
you would for another type, say an int:

int* pointsToNum = new int; // an integer allocated dynamically
delete pointsToNum; // de-allocating memory when done using

Human* firstWoman = new Human(); // dynamically allocated Human
delete firstWoman; // de-allocating memory


# accessing members using the dot operator (.)

- Human firstMan; // an instance i.e. an object of Human

- firstMan has attributes such as dateOfBirth that can be accessed using the
dot operator

firstMan.dateOfBirth = "1970";

- if you have a pointer firstWoman to an instance of class Human, you can
either use the pointer operator (->) to access members, or use the 
indirection operator (*) to reference the obj following the dot operator

Human* firstWoman = new Human();
(*firstWoman).IntroduceSelf();


# accessing members using the pointer opeartor (->)

- if an obj has been instantiated on the free store using new or if you
have a pointer to an obj, then you use the pointer operator (->) to access
the member attributes and functions:

Human* firstWoman = new Human();
firstWoman->dateOfBirth = "1970";
firstWoman->IntroduceSelf();
delete firstWoman;

- see code class.cpp


# keywords public and private

- public class members can be used by anyone in possession of an obj of the class
- private class members can be used only within the class (or its "friends")

class Human
{
private:
 // Private member data:
 int age;
 string name;
public:
 int GetAge()
 {
return age;
 }
 void SetAge(int humansAge)
 {
age = humansAge;
 }
// ...Other members and declarations
};

- assume an instance of Human called Eve

Human eve;

- when the user of this instance tries to access member age:

cout << eve.age; // compile error

- then this user would get a compile error akin to “Error: Human::age—cannot access
 private member declared in class Human.”

- the only permissible way to know the age would be to ask for it via pubic 
method GetAge() supplied by class Human

cout << eve.GetAge(); // OK

- similarly Human::age cannot be assigned directly either

eve.age = 22; // compile error

- the only permissible way to set the age is via method SetAge();

eve.SetAge(22); // OK

“Error: Human::age—cannot access
 private member declared in class Human.” 


# abstraction of data via keyword private

- your implementation of a class can abstract member information that classes
and functions outside this class don't need to have access textToTalk

Note 
- in C++ classes are private by default, which means that members (variables and 
functions ) of a class are private unless otherwise specified.

- see code human.cpp

- notice how since the Human::age is private and we can only get it via GetAge(),
this means Human::age is abstracted from the outside world 

Abstraction is an important concept in object-oriented languages. It empowers
 programmers to decide what attributes of a class need to remain known only to the
class and its members with nobody outside it (with the exception of those declared as its
“friends”) having access to it.

Sidenote (protected):

private: Members declared as private are accessible only within the class itself. 
They cannot be accessed by code outside the class, including derived classes.

protected: Members declared as protected are accessible within the class itself and by its derived classes. 
However, they are not accessible from outside the class or its derived classes.

public: Members declared as public are accessible from anywhere, including outside the class, 
derived classes, and within the class itself.


# constructors

- a constructor is a special function (or method) invoked during the instantiation of a class
to construct an object

- just like functions, constructors can also be overloaded 


# declaring and implementing a constructor

- a constructor is a special function that takes the name of the class and returns no value.

So, class Human would have a constructor that is declared like this:

class Human
{
public:
 Human(); // declaration of a constructor
};

- this constructor can be implemented either inline within the class or externally outside the 
class declaration 

- an implementation (also called definition) inside the class looks like this:

class Human
{
public:
 Human()
 {
// constructor code here
 }
};

- a variant enabling you to define the constructor outside the class' declaration looks like this:

class Human
{
public:
 Human(); // constructor declaration
};
// constructor implementation (definition)
Human::Human()
{
 // constructor code here
}

:: is called the scope resolution operator. For example,
Human::dateOfBirth is referring to variable dateOfBirth
declared within the scope of class Human. 

::dateOfBirth, on the other hand would refer to another variable dateOfBirth in a
global scope.


# when and how to use constructors

- a constructor is always invoked during object creation, when an instance of a class 
is constructed 

- so this makes a perfect place for you to initialize class member variables such as 
integers, pointers, and so on to values you are given in the parameters of the constructor

- see code humanBetter.cpp

A constructor that is invoked without arguments is called the
default constructor. Programming a default constructor is
optional.

If you don’t program any constructor, as seen in Listing 9.1, the
compiler creates one for you (that constructs member attributes
but does not initialize Plain Old Data types such as int to any
specific non-zero value).


# overloading constructors 

- constructors cana be overloaded just like functions

class Human
{
public:
 Human()
 {
// default constructor code here
 }
 Human(string humansName)
 {
// overloaded constructor code here
 }
};

- see code humanOverloaded.cpp


# class without a default constructor 

- see code humanNoDefault.cpp

- this code has no default constructor, but has an overloaded one, so you should already know this 
basic stuff


# constructor parameters with default values

class Human
{
private:
 string name;
 int age;
public:
 // overloaded constructor (no default constructor)
 Human(string humansName, int humansAge = 25)
 {
name = humansName;
age = humansAge;
cout << "Overloaded constructor creates " << name;
cout << " of age " << age << endl;
 }
 // ... other members
};

Such a class can be instantiated with the syntax:
Human adam("Adam"); // adam.age is assigned a default value 25
Human eve("Eve, 18); // eve.age is assigned 18 as specified

- note a default constructor is one that can be instantiated without arguments, and not 
necessarily one that doesn't take parameters

- so you can create a default constructor via default parameters and have it instantiate member 
variables without providing any arguments and invoke the constructor via

Human adam; 


# constructors with initialization lists

- another way to init members is via init lists

class Human
{
private:
 string name;
 int age;
public:
 // two parameters to initialize members age and name
 Human(string humansName, int humansAge)
:name(humansName), age(humansAge)
 {
cout << "Constructed a human called " << name;
cout << ", " << age << " years old" << endl;
 }
// ... other class members
};

- the init list is characterized by a colon (:) following the parameter declaration 
contained in the parentheses (...), followed by an individual member variable and 
the value it is initialized to 

This initialization value can be a parameter such as humansName or can even be a fixed value.
Initialization lists can also be useful in invoking base class constructors with specific arguments.

- see code initList.cpp

- look at the code if you are confused, but it's rather simple

Note
It is possible to define a constructor as a constant expression
too, using keyword constexpr. In special cases where such a
construct would be useful from a performance point of view, you
would use it at the constructor declaration.

class Sample
{
const char* someString;
public:
 constexpr Sample(const char* input)
 :someString(input)
 { // constructor code }
};


# deconstructor 

- a destructor, like a constructor, is a special function

- a constructor is invoked at object instantiation, and a destructor is automatically invoked 
when an object is destroyed

- the destructor looks like a function that takes the name of the class, yet has a tilde (~) 
preceding it

class Human
{
    ~Human(); // declaration of destructor
}

- this destructor can either be implemented inline in the class or externally outside the class 
declaration 

An implementation or definition inside the class looks like this:

class Human
{
public:
 ~Human()
 {
// destructor code here
 }
};

A variant enabling you to define the destructor outside the class’s declaration looks like
this:

class Human
{
public:
 ~Human(); // destructor declaration
};
// destructor definition (implementation)
Human::~Human()
{
 // destructor code here
}

As you can see, the declaration of the destructor differs from that of the constructor
slightly in that this contains a tilde (~). The role of the destructor is, however,
 diametrically opposite to that of the constructor.


# when and how to use a destructor

- a destructor is always invoked when an object of a class is destroyed when it goes out of 
scope of is deleted via delete 

- this property makes an ideal place to reset variables and release dynamically allocated memory and
resources 

This book has recommended the usage of std::string over a char* buffer, so that you
don’t need to worry about managing memory allocation and timely deallocation yourself.

std::string and other such utilities are nothing but classes themselves that make use
of constructors and the destructor (in addition to operators, which you study in Lesson
12, “Operator Types and Operator Overloading”) in taking away the work of allocation,
deallocation, and memory management from you

- see code destructor.cpp

This class basically encapsulates a C-style string in MyString::buffer and relieves
you of the task of allocating memory; it deallocates the same every time you need
to use a string

The destructor ~MyString() is
automatically invoked when main ends, and this is demonstrated in the output that
 executes the cout statements in the destructor

A destructor cannot be overloaded. A class can have only one
destructor. If you forget to implement a destructor, the compiler
creates and invokes a dummy destructor, that is, an empty one
(that does no cleanup of dynamically allocated memory).


# copy constructor

- when objects are passed as arguments to a function, that too is copied via pass by value like normally for variables


# shallow copying and associated problems

- classes such as the one in deconstructor.cpp, contain a pointer member buffer that points to dynamically allocated 
memory, allocated in the constructor using new and deallocated in the destructor using delete[]

When an object of this class is copied, the
pointer member is copied, but not the pointed memory, resulting in two objects pointing
to the same dynamically allocated buffer in memory. When an object is destructed,
delete[] deallocates the memory, thereby invalidating the pointer copy held by the
other object. Such copies are shallow and are a threat to the stability of the program, as
shallow.cpp

- why does the shallow.cpp code fail but not the destructor.cpp?

- the diff is the job of using the obj sayHello was delated to another function UseMyString where the parameter
of that function is of type MyString 

- delegating work to this function has resulted in the obj sayHello in main() to be copied into parameter str 
used in UseMyString()

- this is a copy generated by the compiler as the function has been declared to take str as a parameter by value 
and not by reference 

- the compiler performs a binary copy of Plain Old Data such as integers, characters, and pointers to the same 

- so the pointer value contained in sayHello.buffer has simply been copied to str -- that is, sayHello.buffer 
points to the same memory location as str.buffer

- so you have 2 pointers that point to the same char* buffer  

- the binary copy did not perform a deep copy of the pointed memory location, and you now have 2 objects of class 
MyString pointing to the same location in memory

- thus, when the function UseMyString() ends, variable str goes out of scope and is destroyed

- in doing so, the destructor of class MyString is invoked, and the destructor releases the memory allocated 
to the buffer via delete[]

- this call to delete[] invalidates the memory being pointed to in copy sayHello contained in main() 

- when main() ends, sayHello goes out of scope and is destroyed

- this time, however, the destructor call is repeated twice due to this last out of scope deletion and repeats
a call to delete on a memory address that is no longer valid (released and invalidated via the previous 
destruction of str)

- so, the double delete is what results in a crash


# ensuring deep copy using a copy constructor

- the copy constructor is an overloaded constructor that you supply 
- it is invoked everytime an object of the class is copied

The declaration syntax of a copy constructor for class MyString is the following:
class MyString
{
 MyString(const MyString& copySource); // copy constructor
};
MyString::MyString(const MyString& copySource)
{
 // Copy constructor implementation code
}

- thus, a copy constructor takes an object of the same class by reference as a parameter 

- this parameter is an alias of the source object and is the handle you have in writing your custom copy code 

- you would use the copy constructor to ensure a deep copy of all buffers in the source 

- see code copyConstructor.cpp

- this is not a shallow copy of pointer values 

- this is a deep copy where the content being pointed to is copied to a newly allocated buffer that belongs 
to this object

- what makes a copy constructor a copy constructor

Constructor Signature: A copy constructor has a single parameter which is a reference to an object of the same class type (usually const).

Purpose: Its primary purpose is to initialize a new object with the contents of another object of the same class.

Invocation: It is invoked automatically when an object is:

Passed by value as an argument to a function.
Returned by value from a function.
Explicitly invoked to create a copy.

- the output in copyConstructor.cpp indicates that the memory address being pointed to by buffer is different 
in the copy -- that is, 2 objects don't point to the same dynamically allocated memory address

As a result, when function UseMyString() returns and
parameter str is destroyed, the destructor code does a delete[] on the memory address
that was allocated in the copy constructor and belongs to this object. In doing so, it does
not touch memory that is being pointed to by sayHello in main(). So, both functions
end and their respective objects are destroyed successfully and peacefully without the
application crashing.

Caution:
Using const in the copy constructor declaration ensures that
the copy constructor does not modify the source object being
referred to.

Additionally, the parameter in the copy constructor is passed by
reference as a necessity. If this weren’t a reference, the copy
constructor would itself invoke a copy, thus invoking itself again
and so on till the system runs out of memory

- Sidenote

The copy constructor has ensured deep copy in cases such as
function calls:
MyString sayHello("Hello from String Class");
UseMyString(sayHello);

However, what if you tried copying via assignment:
MyString overwrite("who cares? ");
overwrite = sayHello;

This would still be a shallow copy because you still haven’t yet
supplied a copy assignment operator=. In the absence of one,
the compiler has supplied a default for you that does a shallow
copy.
The copy assignment operator is discussed in length in Lesson
12. Listing 12.8 is an improved MyString that implements the
same:
MyString::operator= (const MyString& copySource)
{
 //... copy assignment operator code
}

- Sidenote

The class MyString with a raw pointer member, char* buffer
is used as an example to explain the need for copy constructors.
If you were to program a class that needs to contain string data
for storing names and so on, you use std::string instead of
char* and might not even need a copy constructor given the
absence of raw pointers.

This is because the default copy constructor inserted by the compiler would ensure the invocation
of all available copy constructors of member objects such as std::string.


# move constructors help improve performance

- there are cases where objects are subjected to copy steps automatically, due to the nature of the 
language and its needs

Consider the following:

class MyString
{
 // pick implementation from Listing 9.9
};
MyString Copy(MyString& source) // function
{
 MyString copyForReturn(source.GetString()); // create copy
 return copyForReturn; // return by value invokes copy constructor
}
int main()
{
 MyString sayHello ("Hello World of C++");
 MyString sayHelloAgain(Copy(sayHello)); // invokes 2x copy constructor
 return 0;
}

 a deep copy was performed twice because of our call to function
Copy(sayHello) that returns a MyString by value

- however, this value returned is very temporary and is not available outside this expression

- so, the copy constructor invoked in good faith by the C++ compiler is a burden on performance 

- this impact becomes significant if our class were to contain objects of great size

- to avoid this performance bottleneck, C++11 features a move constructor in addition to a copy constructor

The syntax of a move constructor is

// move constructor
MyString(MyString&& moveSource)
{
 if(moveSource.buffer != NULL)
 {
buffer = moveSource.buffer; // take ownership i.e. 'move'
moveSource.buffer = NULL; // set the move source to NULL
 }
}

- when a move constructor is programmed, the compiler automatically opts for the same for "moving" the 
temporary resource and hence avoiding a deep-copy step

With the move constructor implemented, the comment should be appropriately changed to the following:

MyString sayHelloAgain(Copy(sayHello)); // invokes 1x copy, 1x move constructors

- this move constructor is usually implemented with the move assignment operator, shown in lesson 12

- and the code in that lesson 12 is a better version of MyString class that implements a move constructor
and move assignment operator


# different uses of constructors and the destructor

















