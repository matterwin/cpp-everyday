# overview

C++ programmers do not necessarily need to use plain pointer types
when managing memory on the heap (or the free store); they can make
use of smart pointers.

In this lesson, you learn
 ■ What smart pointers are and why you need them
 ■ How smart pointers are implemented
 ■ Different smart pointer types
 ■ Why you should not use the deprecated std::auto_ptr
 ■ The Standard Library smart pointer std::unique_ptr
 ■ Popular smart pointer libraries


# what are smart pointers

- a smart pointer in C++ is a class with overloaded operators, which behaves
like a conventional pointer

- yet it supplies additional value by ensuring proper and timely destruction
of dynamically allocated data and facilitates a well-defined object lifecycle


# the problem with using conventional (raw) pointers

- unlike other modern programming languages, C++ supplies full flexibility to the
programmer in memory allocation, deallocation, and mangement

- but this flexibility is a double-edged sword 

- on one side it makes C++ a powerful language, but on the other side it allows
the programmer to create memory-related problems like memory leaks, when
dynamically allocated objects are not correctly released.

For example:
SomeClass* ptrData = anObject.GetData ();
/*
 Questions: Is object pointed by ptrData dynamically allocated using new?
 If so, who calls delete? Caller or the called?
 Answer: No idea!
*/
ptrData->DoSomething();

In the preceding code, there is no obvious way to tell whether the memory pointed to by
ptrData
 ■ Was allocated on the heap, and therefore eventually needs to be deallocated
 ■ Is the responsibility of the caller to deallocate
 ■ Will automatically be destroyed by the object’s destructor

Although such ambiguities can be partially solved by inserting comments and enforcing
coding practices, these mechanisms are much too loose to efficiently avoid all errors
caused by abuse of dynamically allocated data and pointers.


# how do smart pointers help?

- the programmer can choose a smarter way to allocate and manage dynamic data by adopting the use
of smart pointers in his programs:

smart_pointer<SomeClass> spData = anObject.GetData();

// Use a smart pointer like a conventional pointer!
spData->Display();
(*spData).Display();

// Don't have to worry about de-allocation
// (the smart pointer's destructor does it for you!)

- thus, smart pointers behave like conventional pointers (let's call those raw pointers now)
but supply useful features via their overloaded operators and destructors to ensure that 
dynamically allocated data is destroyed in a timely manner


# how are smart pointers implemented?

- "How did the smart pointer spData function like a conventional pointer?"

- The answer is: Smart pointer classes overload derefencing operator (*) and member selection operator
(->) to make the programmer use them as conventional pointers.

- additionally, to allow you to manage a type of your choice on the heap, almost all good
smart pointer classes are template classes that contain a generic implementation of their
functionality

- being templates, they are versatile and can be specialized to manage an object of a type of your
choice

- see code smartPtr.cpp (The Minimal Essential Components of a Smart Pointer Class)

- the class in smartPtr.cpp displays the implementation of the 2 operators * and ->,
that help this class to function as a "pointer" in the conventional sense.

- for instance, to use the smart pointer on an object of type class Tuna, you would instantiate it like
so:

smart_pointer <Tuna> smartTuna (new Tuna);
smartTuna->Swim();
//Alternatively:
(*smartTuna).Swim();

- this class smart_pointer still doesn't display or implement any functionality that would make 
this pointer class very smart and make using it an advantage over using a conventional pointer 

- the constructor accepts a pointer that is saved as the internal pointer object in the smart 
pointer class

- the destructor frees this pointer, allowing for automatic memory release

The implementation that makes a smart pointer really “smart”
is the implementation of the copy constructor, the assignment
operator, and the destructor. 

They determine the behavior of the
smart pointer object when it is passed across functions, when it
is assigned, or when it goes out of scope (that is, gets destructed).

So, before looking at a complete smart pointer implementation,
you should understand some smart pointer types.


# types of smart pointers

- the mangement of the memory resource (that is, the ownership model implemented) is what sets
smart pointer classes apart

- smart pointers decide what they do with the resource when they are copied and assigned too

- the simplest implementations often result in performance issues, whereas the fastest ones might not 
suit all applications

- in the end, it's up for the programmer to understand how a smart pointer functions before she 
decides to use it in her application

Classification of smart pointers is actually a classification of their memory resource management strategies. These are

 ■ Deep copy
 ■ Copy on Write (COW)
 ■ Reference counted
 ■ Reference linked
 ■ Destructive copy

Let’s take a brief look into each of these strategies before studying the smart pointer
 supplied by the C++ standard library—the std::unique_ptr


# deep copy

- in a smart pointer that implements deep copy, every smart pointer instance holds a complete 
copy of the object that is being manage.

- whenever the smart pointer is copied, the object pointed to is also copied (thus, deep copy)

- when the smart pointer goes out of scope, it releases the memory it points to (via the destructor)

- although the deep-copy-based smart pointer does not seem to render any value over passing objects 
by value, its advantage becomes apparent in the treatment of polymorphic objects,
as seen in the following, where it can avoid slicing:

// Example of Slicing When Passing Polymorphic Objects by Value
// Fish is a base class for Tuna and Carp, Fish::Swim() is virtual
void MakeFishSwim (Fish aFish) // note parameter type
{
 aFish.Swim(); // virtual function
}
// ... Some function
Carp freshWaterFish;
MakeFishSwim (freshWaterFish); // Carp will be 'sliced' to Fish
// Slicing: only the Fish part of Carp is sent to MakeFishSwim()
Tuna marineFish;
MakeFishSwim(marineFish); // Slicing again// Example of Slicing When Passing Polymorphic Objects by Value
// Fish is a base class for Tuna and Carp, Fish::Swim() is virtual
void MakeFishSwim (Fish aFish) // note parameter type
{
 aFish.Swim(); // virtual function
}
// ... Some function
Carp freshWaterFish;
MakeFishSwim (freshWaterFish); // Carp will be 'sliced' to Fish
// Slicing: only the Fish part of Carp is sent to MakeFishSwim()
Tuna marineFish;
MakeFishSwim(marineFish); // Slicing again

Slicing is a phenomenon that occurs in C++ when you pass a derived class object to a function that
accepts a parameter of its base class type by value. 

This results in the loss of the derived class-specific information, leaving only the base class 
part accessible within the function.

---
Fish is a base class for Tuna and Carp.
Fish::Swim() is declared as a virtual function, indicating that it can be overridden in derived classes.
MakeFishSwim is a function that takes a Fish object by value as a parameter.
When you call MakeFishSwim(freshWaterFish), you're passing a Carp object (freshWaterFish) to a function expecting a Fish object. 
Here's where slicing occurs:

Only the Fish part of Carp is copied into the parameter aFish within MakeFishSwim. 
Any additional data or behavior specific to Carp (or Tuna) is lost because the function 
only knows about the Fish part.

So, when aFish.Swim() is called inside MakeFishSwim, it calls Fish::Swim() rather than Carp::Swim().

Similarly, when MakeFishSwim(marineFish) is called with a Tuna object, slicing occurs again, 
resulting in the loss of any Tuna-specific data or behavior.
---

- Slicing issues are resolved when the programmer chooses a deep-copy smart pointer, as
shown in slicingFixed.cpp

- deepcopy_smart_ptr implements a copy constructor that allows a deep copy of the polymorphic object 
via a Clone() function that the class needs to implement 

- similarly, it also implements a copy assignment operator 

- for the sake of simplicity, it is taken for granted in this example that the virtual function 
implemented by the base class Fish is called Clone() 

- typically, smart pointers that implement deep-copy models have this function supplied as either a 
template parameter or a function object

- thus, when the smart pointer itself is passed as a pointer to base class type Fish:
deepcopy_smart_ptr<Carp> freshWaterFish(new Carp);
MakeFishSwim(freshWaterFish); // carp will not be 'sliced'

- the deep copy implemented in the smart pointer's constructor kicks in to ensure that the object 
being passed is not sliced, even though syntactically only the base part of it is required by 
the destination function MakeFishSwim() 

- the disadvantage of the deep-copy-based mechanism is performance.

- this might not be a factor for some applications, but for many others it might inhibit the 
programmer from using a smart pointer for his application 

- instead, he might simply pass a base type pointer (conventional pointer, Fish*) to functions 
such as MakeFishSwim().

i.e. he means 

To avoid slicing, you can pass objects by reference or pointer. 
This allows you to pass derived class objects to functions expecting base class objects 
without losing the derived class-specific information. 

For example:
void MakeFishSwim(Fish& aFish) // Pass by reference
{
    aFish.Swim(); // virtual function
}

void MakeFishSwim(Fish* aFish) // Pass by pointer
{
    aFish->Swim(); // virtual function
}

- other pointer types try to address this performance issue in various ways


# copy on write mechanism

- Copy on Write (COW as it's popularly called) attempts to optimize the performance of 
deep-copy smart pointers by sharing pointers until the 1st attempt at writing to the object is made

- on the 1st attempt at invoking a non-const function, a COW pointer typically creates a copy of 
the object on which the non-const function is invoked, whereas other istances of the pointer 
continue sharing the source object 

- COW has its fair share of fans.
- For those that swear by COW, implementing operators (*) and (->) in their const and non-const
verisons is key to the functionality of the COW pointer.
- the latter creates a copy

- the point is that when you chose a pointer implementation that follows the COW philosophy, be sure 
that you understand the implementation details before you proceed to use such an implementation

- otherwise, you might land in situations where you have a copy too few or a copy too many


# reference-counted smart pointers

- reference counting in general is a mechanism that keeps a count of the number of users of 
an object 

- when the count reduces to zero, the object is released

-so, reference counting makes a very good mechanism for sharing objects wihout having to 
copy them 

- such smart pointers, when copied, need to have the reference count of the object in 
question incremented

- there are at least 2 popular ways to keep this count:

1. reference count maintained in the object being point to 
2. reference count maintained by the pointer class in a shared object

- the 1st variant where the reference count is maintained in the object is called
instrusive reference counting b/c the obj needs to be modified

- the 2nd variant where the reference count is maintained in a shared object is a mechanism where 
the smart pointer class can keep the ref count on the free store (a dynamically allocated integer, i.e.)
and when copied, the copy constructor increments this value

- therefore, the ref-counting mechanism makes it pertinent that the programmer works with the smart 
pointers only when using the object 

- a smart pointer managing the object and a raw pointer pointing to it is a bad idea b/c the smart 
pointer (smartly) releases the obj when the count maintained by it goes down to zero, but the raw 
pointer continues pointing to the part of the memory that no longer belongs to your application

- similarly, ref counting can cause issues peculiar to their situation:
2 objects that hold a pointer to each other are never released b/c their cyclic dependency holds their 
reference counts at a minimum of 1 


# reference-linked smart pointers 

- ref-linked smart pointers are ones that don't proactively count the number of references using 
the object; rather, they just need to know when the number comes down to zero so that the obj 
can be released

- they are called ref-linked b/c their implementaiton is based on a double-linked list 

- when a new smart pointer is created by copying an existing one, it is appended to the list 

- when a smart pointer goes out of scope of is destroyed, the destructor de-indexes the smart 
pointer from this list.

- ref linking also suffers from the problem caused by cyclic dependency, as applicable to 
reference-counted pointers


# destructive copy 

- destructive copy is a mechanism where a smart pointer, when copied, transfers complete ownership of the 
obj being handled to the destrination and resets itself:

destructive_copy_smartptr <SampleClass> smartPtr(new SampleClass());

SomeFunc(smartPtr); // ownership transferred to SomeFunc 
// don't use smartPtr in the caller anymore!

- although this mechanism is obviously not intuitive to use, the advantage supplied by 
destructive copy smart pointers is that they ensure that at any point in time, only 1 
active pointer points to an object 

- so, they make good mechanisms for returning pointers from functions, and are of use in 
scenarios where you can use their "destructive" properties to your advantage 

The implementation of destructive copy pointers deviates from standard, recommended
C++ programming techniques, as shown in Listing 26.3.

std::auto_ptr is by far the most popular (or notorious, depending on how you look at it) 
pointer that follows the principles of destructive copy. 

Such a smart pointer is useless after it has been passed to a function or copied into another.

std::auto_ptr has been deprecated in C++11. 

Instead, you should use std::unique_ptr, which cannot be passed by
value due to its private copy constructor and copy assignment
operator. 

It can only be passed as a reference argument.

- see code destructiveCopySmartPtr.cpp

- this code demonstrates the implementation of a destructive-copy-based smart pointer 

- the copy constructor and copy assignment operator are present still 

- these functions invalidate the source when making a copy; that is, the copy constructor sets 
the pointer contained by the sourec to NULL, after copying it, therefore justifying the name
"destructive copy."

- the assignment operator does the same thing.

- Thus, nums is actually invalidated in Line 34, destructivecopy_ptr<int> copy = num;, when it 
is assigned to another pointer.

- this behavior is counterintuitive to the act of assignment 

The copy constructor and copy assignment operators that are
critical to the implementation of destructive copy smart pointers as shown in Listing 26.3 
also attract maximum criticism.

Unlike most C++ classes, this smart pointer class cannot have
the copy constructor and assignment operator accept const
references, as it needs to invalidate the source after copying it.

This is not only a deviation from traditional copy-constructor and
assignment-operator semantics, but also makes using the smart
pointer class counter intuitive. 

Few expect the copy source or the assignment source to be damaged after a copy or assignment step. 

The fact that such smart pointers destroy the source also
makes them unsuitable for use in STL containers, such as the
std::vector, or any other dynamic collection class that you
might use. 

These containers need to copy your content internally
and end up invalidating the pointers.

So, for more than one reason, you are advised to avoid using
destructive copy smart pointers in your programs.

The auto_ptr was a destructive-copy–based smart pointer
supported by the C++ Standard until recently. 

It was finally marked as deprecated in C++11, and you should use std::unique_ptr instead.


# using the std::unique_ptr 

- std::unique_ptr was introduced to C++ starting with C++11 and is slightly different from auto_ptr 
in the sense that it does not allow copy or assignment

To use class std::unique_ptr, include header:
#include <memory>

- the unique_ptr is a simple smart pointer similar to what's show in smartPtr.cpp, but with a 
private copy constructor and assignment operator to disallow copy via passing as an argument 
to a function by value, or copy via assignment

- see code uniquePtr.cpp

- follow the construction and destruction sequence, as visible in the output

- note that even though the obj pointed to by smartFish was constructed in main(), as expected, 
it was destroyed (and automatically so) even without having invoked operator delete 

- this is the behavior of unique_ptr where the pointer that goes out of scope releases the object 
it owns via the destructor 

- note how you are able to pass smartFish as an argument to MakeFishSwim()

- this is not a copy step as MakeFishSwim() accepts the parameter by reference 

- if you were to remove the reference symbol & from it, you would immediately encounter a compiler 
error caused by the private copy constructor

- similarly, assignment of 1 unique_ptr obj to another, as in the commented out code in main() is 
also not permitted due to a private copy assignment operator 

In a nutshell, the unique_ptr is safer than the auto_ptr (that was deprecated in
C++11) as it does not invalidate the source smart pointer object during a copy or assignment.
Yet, it allows simple memory management by releasing the object at time of destruction.

Tip:
Listing 26.4 demonstrated that the unique_ptr doesn’t support
copy:
copySmartFish = smartFish; // error: operator= is
private
It however does support move semantics. Therefore, an option
that would work is
unique_ptr<Fish> sameFish (std::move(smartFish));
// smartFish is empty henceforth
If you were ever to write a lambda expression that would need
to capture an unique_ptr, then you would use std::move() in
your lambda capture as supported by C++14.
std::unique_ptr<char> alphabet(new char);
*alphabet = 's';
auto lambda = [capture = std::move(alphabet)]()
{ std::cout << *capture << endl; };
// alphabet is empty henceforth as contents have been
'moved'
lambda();
Don’t be frustrated if the preceding code seems too exotic—it is
admittedly complicated and covers a use case that most professional programmers would 
possibly never come across.


Note:
When writing applications using multiple threads, evaluate using
std::shared_ptr and std::weak_ptr supplied by C++11-
compliant libraries. 
These facilitate thread-safe and referencecounted object sharing

- also there are other smart pointer libraries out there to meet your needs
