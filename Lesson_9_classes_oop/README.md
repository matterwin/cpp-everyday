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

















