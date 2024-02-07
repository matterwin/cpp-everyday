# Preprocessor Directive #include

- a preprocessor is a tool that runs beofre the actual compilation starts.
- Preprocessor directives are commands to the preprocessor and always start with a # "pound" sign

- to include other files in a file you use #inclue "...relatiev path to such used file"


# Body of program int main()

- Following the preprocessor directive(s) is the body of the program characterized by the function main()
- The execution of a C++ program always starts here

- int main() {}
- int main(int argc, char* argv[]) is another way of declaring main

- argc (argument count): 
It stores the number of command-line arguments passed to the program, including the name of the program itself. 
This parameter is of type int.

- argv (argument vector): 
It is an array of strings (char*) where each element represents a command-line argument. 
The first element (argv[0]) is always the name of the program itself. 
The rest of the elements (argv[1] to argv[argc-1]) are the actual command-line arguments passed to the program.

- example:
./myprogram arg1 arg2 arg3

argc would be 4, and argv would be an array containing:
argv[0] = "./myprogram"
argv[1] = "arg1"
argv[2] = "arg2"
argv[3] = "arg3"


# cout

- cout is a stream defined in the standard std namespace (std::cout) that outputs whatever to the console
- the notion '<<' is the same for other stream types like std::fstream to write a file to disk


# Returning a value

- functions return stuff unless its a void ptr function or void function
- main() is a function and returns an integer to the OS
- This is important b/c the OS can provide queries  to the return value of an application that has terminated naturally.

- An example is when one application is launched by another and the parent application (that launches) wants to know if the child application
    (that was launched) has completed its task successfully and it knows that if so from that return int of main()

- Conventionally, in main()
- return 0 in the event of success
- return -1 in the event of error


# Namespaces

- namespaces are names given to parts of code that help in reducing the potential for a naming conflict

- by invoking std::cout you are telling the compiler to use that one unique cout that is available in the std namespace
- stick without declaring std namespace (cherno's opinion) because programmers can question where such a function is coming from it is resembles another std function

- * Listing 2.2 The using namespace Declaration code *
- * Listing 2.3 Another demo of using keyword *

- the diff btw using namespace std & using std::cout is that the former allows all artifacts in the std namespace (cout, cin, etc.) to be used without explicit inclusion
    of the namespace qualifier std::
- With the latter, the convenience of not needing to disambiguate the namespace explicitly is restricted to only std::cout and std::endl


# Comments in code

- // for single line
- /* for multiline */


# Functions in C++

- funcs enable you to divide the content of your application into functional units that can be invoked in a sequence of your choosing
- a func when invoked typically returns a value unless its a void type

- * Listing 2.4 functions *

- 2.4 Analysis
- Notice there is a function declartion before the actual implementation of it.
- This tells the compiler that you want to create a function called DemoConsoleOutput() that returns an int.
- This declaration enables the compiler to compile where DemoConsoleOutput() is called inside main()

- The compiler assumes that the definition (that is the implementation of the function) is going to come up, which it does down the code


- * Listing 2.5 Using the return value of a function *

- 2.5 Analysis
- We can declare and define a function all at once and get rid of single declaration from before
- Most C++ compilers take it as a function declaration and definition in one
- in main() we used the return type and value of DemoConsoleOutput() as well

- functions that do not return anything are of void type
- void DemoConsoleOutput() and cannot return a value

- functions can be recursive, take parameters, contain multiple return stms, be overloaded, be in-lined, and much more (detailed in Lesson 7)


# Basics of std::cin and std::cout

- you use std::cout to write simple text data to the console
- you use std::cin to read text and numbers (entered using the keyboard) from the console.

- the usage of cin is similar to cout
- std::cin >> variable;
- as cin is used for input, it is accompained by the variable you want to be storing the input data in

- extraction operator from input stream is >>
- insertion operator to the input stream is <<

- If the user input needs to be stored in two variables, each containing data separated by a space, then you can do so using one stm:
std::cin >> var1 >> var 2;

- * Listing 2.6 Using cin and cout to display number and text input by user * 

- to be able to store entire lines you can use the getline() function (Lesson 4)