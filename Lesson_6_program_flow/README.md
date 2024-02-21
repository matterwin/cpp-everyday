# If else

- simple stuff like

if (conditional expression)
 Do something when expression evaluates true;
else // Optional
 Do something else when condition evaluates false;

- other than false, nullptr, or 0, everything else is true

- nested if stms

if (expression1)
{
 DoSomething1;
 if(expression2)
DoSomething2;
 else
DoSomethingElse2;
}
else
 DoSomethingElse1;

- switch statements work as if statements as well

- * Listing 6.5 switch-case

Note:
in C++ (and many other programming languages), if you omit the break statement within a case block in a switch statement, execution 
will continue into the next case block without any further checks.

This behavior is often referred to as "falling through" the cases.

- ternary operators

condition ? expression_if_true : expression_if_false



DO use enumerators in switch
expressions to make code
 readable.

DO remember to handle
default, unless deemed totally
unnecessary.

DO check whether you
inadvertently forgot to insert
break in each case statement.

DON’T add two cases with the same
label—it won’t make sense and won’t
compile.

DON’T complicate your case statements
by including cases without break and
relying on sequence. This will break
functionality in the future when you move
the case statements without paying
adequate attention to sequence.

DON’T use complicated conditions or
expressions when using conditional
operators (?:).


# loops

int someNums[] = { 1, 101, -1, 40, 2040 };
for (int aNum : someNums) // range based for
 cout << "The array elements are " << aNum << endl;

- for, while, do-while loops you should know

- use continue to skip over current iteration of loop
- use break to break out of the entire loop
- use return to break and and return from the current function

- can use auto to compose a for loop 

for (auto anElement : elements) // range based for
 cout << "Array elements are " << anElement << endl;

