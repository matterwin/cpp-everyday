# Statements

- all statements in C++ end with a ;

- white spaces aren't visible to the compiler (remember our lexical analyzer)

- you can split a statement like this

cout << "Hello \
 World" << endl; // split to two lines is OK

cout << "Hello "
 "World" << endl; // two string literals is also OK


# Operators

- diff type of operators like the basics

int num1 = 22;
int num2 = 5;
int addNums = num1 + num2; // 27
int subtractNums = num1 – num2; // 17
int multiplyNums = num1 * num2; // 110
int divideNums = num1 / num2; // 4
int moduloNums = num1 % num2; // 2

- prefix ++ or -- means you add 1 to the variable first, then evaluate it with whatever after
- post fix is the opposite

int num1 = 101;
int num2 = num1++; // Postfix increment operator
int num2 = ++num1; // Prefix increment operator
int num2 = num1--; // Postfix decrement operator
int num2 = --num1; // Prefix decrement operator

- equality operators

int personAge = 20;
bool checkEquality = (personAge == 20); // true
bool checkInequality = (personAge != 100); // true
bool checkEqualityAgain = (personAge == 200); // false
bool checkInequalityAgain = (personAge != 20); // false

int personAge = 20;
bool checkLessThan = (personAge < 100); // true
bool checkGreaterThan = (personAge > 100); // false
bool checkLessThanEqualTo = (personAge <= 20); // true
bool checkGreaterThanEqualTo = (personAge >= 20); // true
bool checkGreaterThanEqualToAgain = (personAge >= 100); // false

- 0 is false
- any non-zero values is considered true in C++ (besides false of course)

- more basics of logical operators

&& AND
|| OR
!  NOT

- bitwise operators

~   NOT
&   AND
|   OR
^   XOR

- bitwise right shift >>
- bitwise left shift <<

shifting to the right by 1 means we shift the bits one position to the right, which halves the number
shifting to the left by 1 means we shift the bits one position to the left, which doubles the number

- shifting is theoretically faster than multiplication or division, but modern compilers are usually very efficient with the latter

- can do compound operations

int num += 2;
int num = num + 2;

etc


# Using sizeof

sizeof(variable) tells you the amount of memory in bytes consumed by a particular type or a variable
sizeof(type)

Note:
sizeof(...) might look like a function call, but it is not a function.
sizeof is an operator. Interestingly, this operator cannot be defined by the programmer and hence cannot be overloaded.


DO use parentheses to make your
code and expressions readable.

DO use the right variable types
and ensure that it will never reach
overflow situations.

DO understand that all l-values (for
example, variables) can be r-values,
but not all r-values (for example,
“Hello World”) can be l-values.

DON’T program complicated expressions relying on the operator precedence table; your code needs to be
human readable, too.

DON’T confuse ++Variable and
Variable++ thinking they’re the
same. They’re different when used in
an assignment.
