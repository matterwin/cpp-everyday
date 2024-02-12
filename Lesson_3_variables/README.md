# Memory and Addressing in Brief

- all computers contain a microprocessor and a certain amount of memory for temporary storage called Random Access Memory (RAM)
- and may allow data to persist on a storage device such as a hard disk or disk

- the microprocessor executes your application, and in doing so it works with RAM to fetch the application binary code to be executed as well
    as the data associated with it

- the RAM itself is like a storage area akin to a row of lockers in the dorms, each locker having a number -- that is, an address
- to access a location in memory, say location 578, the processor needs to be asked via an instruction to fetch a value from there or write a value to it


# Declaring vars to access and use memory

- variableType variableName = ititialValue;

- the variable type attribute tells the compiler the nature of data the variable can store, and the compiler reserves the necessary space for it
- the name chosen by the programmer is a friendly replacement for the address in the memory where the variable's value is stored.

- unless the init value is assigned, you cannot be sure of the contents of that memory location, which can be bad for the program
- therefore, initilization is optional, but it's often best practice.

- * I am skipping the code segment on this cause it's very trivial

- the compiler manages memory-addressing and creates the instructions for the microprocessor to execute in working with the RAM

- variables cannot be named certain ways that you should already know/lookup if not

- variables stored in RAM is lost when the application terminates, but can persist if the programmer explicitly persists the data on a storage medium like a disk
(Lesson 27)


# Multiple variables initilized at once

- int first = 0, second = 0, third = 0;

- can do this type of init for simplicity


# Understanding scope of variables

- when variables are used outside of scope, they will not be recognized by the compiler and your program will not compile
- beyond its scope, a variable is an unidentified entity that the compiler knows nothing of

- * Skipping code segment due to its simplicity and what we've seen so far


# Global variables

- variables are global if they are defined at the outer most scope of a cpp file
- meaning the global variable can be used anywhere within a program without compilation issues

- but note that indiscriminate use of global variables is considered poor programming practice.
- This is b/c global variables can be assigned values in any/every function and can contain an unpredictable state, especially when functions that modify them
    run in different threads or are programmed by different programmers in a team.

- * Listing 3.3 Using global variables

- follow a camelCase naming convention for mostly everything


# Common Compiler-Supposted C++ Variable Types

- type                      - values

- bool                      true or false
- char                      256 character values
- unsigned short int        0 to 65,535
- short int                 -32,768 to 32,767
- unsigned long int         0 to 4,294,967,295 (or 2^32)
- long int                  -2,147,483,648 to 2,147,483,648
- unsigned long long        0 to 18,4446,744,073,709,551,615 (or 2^64)
- long long                 -9,223,372,036,854,775,808 to 9,223,372,036,854,775,808

- int (16 bit)              -32,768 to 32,767
- int (32 bit)              -2,147,483,648 to 2,147,483,648
- unsigned int (16 bit)     0 to 65,535
- unsigned int (32 bit)     0 to 4,294,967,295 (or 2^32)
- float                     1.2e-38 to 3.4e38
- double                    2.2e-308 to 1.8e308


# bool type

- bool alwaysOnTop = false;

- expressions can evalue to a bool type
- bool deleteFile = (userSelection == "yes");
- // evals to true is userSelection contains "yes" otherwise false


# char type

- use char to store a single character
- char userInput = 'Y';

- the numeric representation of chars has been standarized by the American Standard Code for Information Interchange, aka ASCII
- know 'a' is 97 and 'A' is 65

- ASCII

  0  NUL (null)                      32  SPACE     64  @         96  `
  1  SOH (start of heading)          33  !         65  A         97  a
  2  STX (start of text)             34  "         66  B         98  b
  3  ETX (end of text)               35  #         67  C         99  c
  4  EOT (end of transmission)       36  $         68  D        100  d
  5  ENQ (enquiry)                   37  %         69  E        101  e
  6  ACK (acknowledge)               38  &         70  F        102  f
  7  BEL (bell)                      39  '         71  G        103  g
  8  BS  (backspace)                 40  (         72  H        104  h
  9  TAB (horizontal tab)            41  )         73  I        105  i
 10  LF  (NL line feed, new line)    42  *         74  J        106  j
 11  VT  (vertical tab)              43  +         75  K        107  k
 12  FF  (NP form feed, new page)    44  ,         76  L        108  l
 13  CR  (carriage return)           45  -         77  M        109  m
 14  SO  (shift out)                 46  .         78  N        110  n
 15  SI  (shift in)                  47  /         79  O        111  o
 16  DLE (data link escape)          48  0         80  P        112  p
 17  DC1 (device control 1)          49  1         81  Q        113  q
 18  DC2 (device control 2)          50  2         82  R        114  r
 19  DC3 (device control 3)          51  3         83  S        115  s
 20  DC4 (device control 4)          52  4         84  T        116  t
 21  NAK (negative acknowledge)      53  5         85  U        117  u
 22  SYN (synchronous idle)          54  6         86  V        118  v
 23  ETB (end of trans. block)       55  7         87  W        119  w
 24  CAN (cancel)                    56  8         88  X        120  x
 25  EM  (end of medium)             57  9         89  Y        121  y
 26  SUB (substitute)                58  :         90  Z        122  z
 27  ESC (escape)                    59  ;         91  [        123  {
 28  FS  (file separator)            60  <         92  \        124  |
 29  GS  (group separator)           61  =         93  ]        125  }
 30  RS  (record separator)          62  >         94  ^        126  ~
 31  US  (unit separator)            63  ?         95  _        127  DEL


# Concept of signed vs unsigned integers

- sign implies positive and negative
- unsigned only implies positive

- all numbers you work with using a computer are stored in the memory in the form of bits and bytes
- a memory location that is 1 byte large contains 8 bits

- each bit can either be a 0 or 1
- thus, a memory location that is 1 byte large can contain a maximum of 2 to the power 8 values -- that is, 256 unique values

- similarly, a memory location that is 16 bits large can contain 2 ^ 15 values -- that is, 65,536 unique values

- if these values were to be unsigned -- assumed to be positive only -- then 1 byte could contain integer values ranging from 0 through 255
- and 2 bytes would contain values ranging from 0 through 65,535

- table 3.1 shows an unsigned short as the type and that supports the range of 0 to 65,535 (as it is contained in 16 bits of memory)

Table 3.1
15..........Bit0
1111111111111111    = 65535

16 bits

- how to model negative numbers in space?
- would be sacrifice a bit to serve as a "sign bit" that would indicate if the values contained in the other bits are positive or negative

- the sign-bit needs to be the most-significant-bit (MSB or the leftmost bit) 
- as the least-significant-bit (LSB or the rightmost bit) would be required to model odd numbers since the LSB is the 2^0 = 1 so if we add 1 or not to make it odd or even respct.

- so the sign-bit shows the positive or negative values:
- 0 : indiciates positive integer
- 1 : indiciates negative integer

Figure 3.2
15..........Bit0
1111111111111111    = 65535
|
|   16 bits - 1 MSB = 15 bits available to programmer
v
sign-bit is the leftmost bit (MSB)

- 8-bit signed contains values  -128 to 128         or 2^7
- 16-bit signed contains values -32,768 to 32,768   or 2^15


# little endian vs big endian

- Little endian and big endian are two different ways of ordering bytes in memory, particularly relevant in computer architecture and data representation. The distinction arises when multi-byte data types, such as integers or floating-point numbers, are stored in memory.

- Big Endian:

- In big endian systems, the most significant byte (MSB) of a multi-byte data type is stored at the lowest memory address, and the least significant byte (LSB) is stored at the highest memory address.
- This means that when you write out the bytes in memory, the most significant byte comes first, followed by the less significant bytes.
- For example, consider the 32-bit integer 0x12345678:
- In big endian, it would be stored as: 12 34 56 78 (assuming each pair of digits represents one byte).

- Little Endian:

- In little endian systems, it's the opposite: the least significant byte (LSB) is stored at the lowest memory address, and the most significant byte (MSB) is stored at the highest memory address.
- This means that when you write out the bytes in memory, the least significant byte comes first, followed by the more significant bytes.
- Using the same example of the 32-bit integer 0x12345678:
- In little endian, it would be stored as: 78 56 34 12.

- The choice between little endian and big endian often depends on the architecture and design of the system. Different processors and systems may use either format. For instance:

- x86 and x86-64 architectures commonly use little endian.
- PowerPC, ARM, and SPARC architectures can be configured to use either big endian or little endian.
- Network protocols, such as TCP/IP, typically use big endian for standardized data representation.


# signed integer types: short, int, long, long long

- theses types differ in size and therefore their range

short int gradesInMath = -5; // not your best score
int moneyInBank = -70000; // overdraft
long populationChange = -85000; // reducing population
long long countryGDPChange = -70000000000;


# unsigned integer types: short, int, long, long long

- Unlike their signed counterparts, unsigned integer variable types cannot contain sign
information, and hence they can actually support twice as many positive values.

unsigned short int numColorsInRainbow = 7;
unsigned int numEggsInBasket = 24; // will always be positive
unsigned long numCarsInNewYork = 700000;
unsigned long long countryMedicareExpense = 70000000000;


# avoiding overflow errors

- all these types above are finite, and if you exceed the limit, you create an overflow

- ex: unsigned short consumes 16 bits (2 bytes) and stores 0 through 2^16 - 1 or 65535
- when you add 1 to 65535 in an unsigned short, the value overflows to 0

- ex: signed short, range is -32768 to 32767
- adding 1 to 32767 may result in the signed integer taking the highest negative value (so -32768)
- that behavior is compiler dependent

- * Listing 3.4 Overflow errors


# type float and double

- float point numbers can be positive or negative
- so if you want to store the value of pi, use a float

float pi = 3.14;

- a double precision float (or a double) can store many more digits than a float
- double uses 64 bits, float uses 32 bit

- Tip:
C++14 adds support for chunking separators in the form of a
single quotation mark. This improves readability of code, as seen
in the following initializations:
int moneyInBank = -70'000; // -70000
long populationChange = -85'000; // -85000
long long countryGDPChange = -70'000'000'000; // -70 billion
double pi = 3.141'592'653'59; // 3.14159265359

The data types mentioned thus far are often referred to as POD
(Plain Old Data). The category POD contains these as well as
aggregations (structs, enums, unions, or classes) thereof.


# using sizeof

- size is the amount of memory that the compiler reserves when the programmer declares a variable to 
    hold the data assigned to it
- the size of a variable depends on its type, and C++ has an operator called sizeof that tells you the
    size in bytes of a variable or a type

- * Listing 3.5 sizeof

- the outputs of the various sizes are specific to the compiler, OS, and hardware
- the output in the code is specific to running it on a 32-bit compiler on a 64-bit OS

- Note that a 64-bit compiler probably creates different results, and the reason I chose a
32-bit compiler was to be able to run the application on 32-bit as well as 64-bit systems.
The output tells that the sizeof a variable doesn’t change between an unsigned or signed
type; the only difference in the two is the MSB that carries sign information in the former.

- Tip:
C++11 introduced fixed-width integer types that allow you to
specify the exact width of the integer in bits. These are int8_t
or uint8_t for 8-bit signed and unsigned integers, respectively.
You may also use 16-bit (int16_t, uint16_t), 32-bit (int32_t,
uint32_t), and 64-bit (int64_t, uint64_t) integer types. To use
these types, remember to include header
<cstdint>.


# avoid narrowing conversion errors using list initialization

- when you initialize a variable of a smaller integer type (say, short) using another of a larger type (say, an int),
you are risking a narrowing conversion error b/c the compiler has to fit data stored in a type that can potentially
hold much larger numbers into a type that doesn't have the same capacity (that is, narrower)

int largeNum = 5000000;
short smallNum = largeNum; // compiles OK, yet narrowing error

- Narrowing isn’t restricted to conversions between integer types only. You may face
narrowing errors if you initialize a float using a double, a float (or double) using
an int, or an int using a float. 
- Some compilers may warn, but this warning will not cause an error that stops compilation. In such cases, you may be 
confronted by bugs that occur infrequently and at execution time. 

- To avoid this problem, C++11 recommends list initialization techniques that prevent narrowing. 
- To use this feature, insert initialization values/variables within braces {…}. 

The list initialization syntax is as follows:
int largeNum = 5000000;
short anotherNum{ largeNum }; // error! Amend types
int anotherNum{ largeNum }; // OK!
float someFloat{ largeNum }; // error! An int may be narrowed
float someFloat{ 5000000 }; // OK! 5000000 can be accomodated

- It may not be immediately apparent, but this feature has the potential to spare bugs that
occur when data stored in a type undergoes a narrowing conversion at execution time—
these occur implicitly during an initialization and are tough to solve


# automatic type inference using auto

