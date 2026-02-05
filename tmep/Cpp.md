# Hello World
# Printing using COUT
	* Endl
	* pattern using multiple cout
	* escape sequences
# Variables
	* case sensitive
	* Use var where value is used multiple times
	* using variables in output
	* const
# Input using CIN
# Operators
	* arithematic (+-*/%, ++, --)
	* assignment (=)
	* binary (&&, ||, &, |, ^, <<, >>)
	* compound assignment (+=, -=, *=, /=, %=, &=, |=, ^=, >>=, <<=)
	* comparison (==, !=, <, >, >=, <=)
	* logical (&&, ||, !)
	* operator precedance
	* alphabetic form of operators
# Comments
# Data Types
	* char
	* string
	* int
	* bool
	* float
	* double
	* long
	* long long
	* auto

	* Integer overflow
	* type casting
	* Floating Point Imprecision

	* working with strings
	* string variables
	* access string's one char (0-indexing)
# Header Files and Libraries (useful resource -> https://manual.cs50.io/)
	* #include <iostream>
	* using namespace std;
	* cmath
# string functions
	* concatenation
	* length [length() and size()]
	* at()
	* C-Style Strings [char greeting2[] = "Hello";]
	* String Comparison
# Boolean Expressions
# decision making
	* if
	* composite if
	* Multiple if
	* Multiple vs nested if
	* nested if
	* else
	* else if
	* ternary
	* logical operators
	* switch case
# Loops
	* while
	* do while
	* for
	* nested loop
	* for each
	* break and continue
# Arrays
	* Accessing using indexes
	* using loop to traverse (for and for each)
	* omit array size [string fruit[] = {"Apple", "Water Melon", "Orange"};]
	* getting array size using SIZEOF
	* multi-dim arrays
	## 2d array traversal
		- int a[2][3] = { {1,2,3}, {4,5,6} };// Complete row initialization
		- int b[2][3] = { 1,2,3,4,5,6 }; // Flattened initialization
		- int c[][3] = { {1,2,3}, {4,5,6} }; // Rows can be omitted
  		- int d[2][3] = { {1}, {4,5} }; // Partial initialization others default 0
  		- int e[2][3] = {}; // All elements default 0

int e[2][3] = {}; // All elements default 0
# Structs
	* creation
	* Accessing
# C++ references
	* Updating Through References
	* print mem address using &
# Pointers
	* print address val
	* dereference
	* modify pointer values
# Dynamic Memory
	* NEW and DELETE keywords
	* Single Variable
	* arrays
	* 2d arrays
# Functions
	* create functions
	* label elements of functions
	* call a function
	* function prototypes
	## Function with params
		- default & custom params
		- multiple params
		- return values
		- pass by reference
		- pass arrays & structs
	## Scope concept
	## Recursion
	## Params to main()
# File Handling
	* ofstream
	* ifstream
	* Text Files vs Binary Files
	* read and write files
	* append to file
	* Storing var, arrays(char, int) to files
	* file modes
	* file pointers
	* seek and tell
	* PGM Binary Image Read and Write
# Exit Codes
	* return 0
	* return 1