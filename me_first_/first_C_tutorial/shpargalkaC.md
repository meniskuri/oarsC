# Shpargalka  C - KapanaC

>C “wears well as one’s experience with it grows.”
>
>C does not hide the complexity and the capabilities of
>the machine underneath. You have a lot of power,
>once you know what you can do.

## დასაწყისი ✨Magic ✨

- C:\raylib\mingw\i686-w64-mingw32\include (ბიბლიოთეკები)

### CHAPTER 1: A Tutorial Introduction

#### 1.1 Getting Started
Now for some explanations about the program itself.
A C program, whatever its size, consists of functions and variables.

A function contains statements that specify the computing operations to be done, and variables store values used during the computation.

C functions are like the subroutines and functions of Fortran or the procedures and functions of Pascal.

Our example is a function named main. Normally you are at liberty to give functions whatever names you like, but “main” is special—your program begins executing at the beginning of main. This means that every program must have a main somewhere.


#### 1.2 Variables and Arithmetic Expressions

Ternary Operator in C Explained  <https://www.freecodecamp.org/news/c-ternary-operator/>

#### 1.3 The for statement
#### 1.4 Symbolic constants
#### 1.5 Character input and output















### ints

```
✨Magic ✨

DATA TYPE SIZE (IN BYTES) |           RANGE          |    FORMAT  SPECIFIER
int                  4     -2147483648 to 2147483647	         %d
unsigned int         4               0 to 4294967295	         %u
short                2          -32768 to 32767	              %hd
unsigned short       2               0 to 65535	              %hu
long                 8  -9223372036854775808
                                       to 9223372036854775807    %ld
unsigned long        8               0 to 18446744073709551615   %llu

```

### printf

```
✨Magic ✨

Specifier                |           Output          |       Examples
d or i	                    Signed decimal integer	         392
u	                         Unsigned decimal integer	       7235
o	                              Unsigned octal	            610
x	                         Unsigned hexadecimal integer	   7fa
X	                Unsigned hexadecimal integer (uppercase)    7FA
f	                     Decimal floating point, lowercase	  392.65
F	                     Decimal floating point, uppercase	  392.65
e	    Scientific notation (mantissa/exponent), lowercase	  3.9265e+2
E	    Scientific notation (mantissa/exponent), uppercase	  3.9265E+2
g	            Use the shortest representation: %e or %f	   392.65
G	            Use the shortest representation: %E or %F	   392.65
a	                 Hexadecimal floating point, lowercase	  -0xc.90fep-2
A	                 Hexadecimal floating point, uppercase	  -0XC.90FEP-2
c	                                 Character	              a
s	                           String of characters	         sample
p	                              Pointer address	           b8000000
n	                              Nothing printed.
```


### Arrays
<https://www.simplilearn.com/tutorials/c-tutorial/array-in-c> გადავხედო

`int masiviIntebis[] = {2,5,6}; // ესე იქმნება ინტების მასივი`

Array in C can be defined as a method of clubbing multiple entities of similar type into a larger group.
These entities or elements can be of int, float, char, or double data type or can be of user-defined data types too like structures. However, in order to be stored together in a single array, all the elements should be of the same data type.  The elements are stored from left to right with the left-most index being the 0th index and the rightmost index being the (n-1) index.
Array  in C are of two types, single dimensional arrays and Multidimensional arrays.

##### Single Dimensional Arrays:
Single dimensional array or 1-D array is the simplest form of arrays that can be found in C. This type of array consists of elements of similar types and these elements can be accessed through their indices.
```
✨Magic ✨
                    array[1]   ->    4
                    ints array -> |1|4|9| | | | | | | | | | | | | | |
                    Indices        0 1 2 3 4
```
##### Multi-dimensional Arrays:
The most common type of multi-dimensional array that is used in the C language is a 2-D array. However, the number of dimensions can be more than 2 depending upon the compiler of the user’s system. These arrays consist of elements that are array themselves.
```
✨Magic ✨
                                 columns 1,2,3
                                  _ _ _ _ _ _
                          row1-> |_|_|_|_|_|_|
                          row2-> |_|_|_|_|_|_| array1
                          row3-> |_|_|_|_|_|_|
                                  _ _ _ _ _ _
                              -> |_|_|_|_|_|_|
                              -> |_|_|_|_|_|_| array2     3D array
                              -> |_|_|_|_|_|_|
                                  _ _ _ _ _ _
                              -> |_|_|_|_|_|_|
                              -> |_|_|_|_|_|_| array3
                              -> |_|_|_|_|_|_|

```
- ჩასამატებელია კიდევ 

### Strings
In C, strings are one special kind of array: a string is
an array of char values:
- `char name[7];`
- `char name[7] = { 'F', 'l', 'a', 'v', 'i', 'o' };`

>```
> ✨Magic ✨
> #include <string.h>`
>
> And once you do that, you have access to:
>
> - strcpy()  // to copy a string over another string
> - strcat()  // to append a string to another string
> - strcmp()  // to compare two strings for equality
> - strncmp() // to compare the first n characters of two strings
> - strlen()  // to calculate the length of a string and many, many more.
>```



### Pointer
<https://www.tutorialspoint.com/cprogramming/c_pointers.htm>

###### Adress of variable

>```
> ✨Magic ✨
> int  var1;
> char var2[10];
>
> printf("Address of var1 variable: %x\n", &var1  );
> printf("Address of var2 variable: %x\n", &var2  );
>```
> - What are Pointers? (hexadecimal number that represents a memory address)
> - A pointer is a variable whose value is the address of another variable, i.e.,
> direct address of the memory location. Like any variable or constant, you must declare
> a pointer before using it to store any variable address. The general form of a pointer variable declaration
> is − type *var_name;



Here, type is the pointer's base type; it must be a valid C data type and var-name is
the name of the pointer variable. The asterisk * used to declare a pointer is the same
asterisk used for multiplication. However, in this statement the asterisk is being used
to designate a variable as a pointer.
Take a look at some of the valid pointer declarations:
```
✨Magic ✨
int    *ip;    /* pointer to an integer  */
double *dp;    /* pointer to a double    */
float  *fp;    /* pointer to a float     */
char   *ch     /* pointer to a character */
```

The actual data type of the `value of all pointers`,
whether integer, float, character, or otherwise, is the same,
`a long hexadecimal number` that represents a memory address.
The only difference between pointers of different data types is
the data type of the variable or constant that the pointer points to.


##### How to Use Pointers?

There are a few important operations,
which we will do with the help of pointers very frequently.
(a) We define a pointer variable,
(b) assign the address of a variable to a pointer and
(c) finally access the value at the address available in the pointer variable.
This is done by using unary operator * that returns the value of the variable
located at the address specified by its operand. The following example makes use of these operations −

```
✨Magic ✨
#include <stdio.h>

int main ()
{

   int  var = 20;   /* actual variable declaration */
   int  *ip;        /* pointer variable declaration */

   ip = &var;       /* store address of var in pointer variable*/

   printf("Address of var variable: %x\n", &var);

   /* address stored in pointer variable */
   printf("Address stored in ip variable: %x\n", ip);

   /* access the value using the pointer */
   printf("Value of *ip variable: %d\n", *ip);

   return 0;
}
```

When the above code is compiled and executed,
it produces the following result:

- `Address of var variable: bffd8b3c`
- `Address stored in ip variable: bffd8b3c`
- `Value of *ip variable: 20`




### Malloc