# Shpargalka  C - KapanaC

>C “wears well as one’s experience with it grows.”
>
>C does not hide the complexity and the capabilities of
>the machine underneath. You have a lot of power,
>once you know what you can do.

## დასაწყისი ✨Magic ✨

- C:\raylib\mingw\i686-w64-mingw32\include (ბიბლიოთეკები)

### CHAPTER 1: A Tutorial Introduction

##### 1.1 Getting Started
Now for some explanations about the program itself.
A C program, whatever its size, consists of functions and variables.

A function contains statements that specify the computing operations to be done, and variables store values used during the computation.

C functions are like the subroutines and functions of Fortran or the procedures and functions of Pascal.

Our example is a function named main. Normally you are at liberty to give functions whatever names you like, but “main” is special—your program begins executing at the beginning of main. This means that every program must have a main somewhere.


##### 1.2 Variables and Arithmetic Expressions

Ternary Operator in C Explained  <https://www.freecodecamp.org/news/c-ternary-operator/>

##### 1.3 The for statement
##### 1.4 Symbolic constants
##### 1.5 Character input and output

The standard library provides several functions for reading or writing one
character at a time, of which getchar and putchar are the simplest. Each
time it is called, getchar reads the next input character from a text stream
and returns that as its value. That is, after
c = getchar()
the variable c contains the next character of input. The characters normally
come from the keyboard; input from files is discussed in Chapter 7.
The function putchar prints a character each time it is called:
putchar(c)
prints the contents of the integer variable c as a character, usually on the
screen. Calls to putchar and printf may be interleaved;

##### 1.5.1 File copying
(კოდი ნახეთ წიგნში)

The problem is distinguishing the end of the input from valid data. The
solution is that getchar returns a distinctive value when there is no more
input, a value that cannot be confused with any real character. This value is
called EOF, for “end of file.” We must declare c to be a type big enough to
hold any value that getchar returns. We can’t use char since c must be big
enough to hold EOF in addition to any possible char. Therefore we use int.

EOF is an integer defined in <stdio.h>, but the specific numeric value
doesn’t matter as long as it is not the same as any char value

##### 1.5.2 Character counting
##### 1.5.3 Line counting 








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


### C File Handling
tutorial: <https://www.programiz.com/c-programming/c-file-input-output>

In this tutorial, you will learn about file handling in C. You will learn to handle standard I/O in C using `fprintf()`, `fscanf()`, `fread()`, `fwrite()`, `fseek()` `etc`. with the help of examples.

A file is a container in computer storage devices used for storing data.

In C, you can perform four major operations on files, either text or binary:
- Creating a new file
- Opening an existing file
- Closing a file
- Reading from and writing information to a file

###### working with Files
For reading and writing to a text file, we use the functions `fprintf()` and `fscanf()`.
They are just the file versions of `printf()` and `scanf()`. The only difference is that `fprintf()` and `fscanf()` expects a pointer to the structure `FILE`.

```
// Example 1: Write to a text file

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num;
   FILE *fptr;

   // use appropriate location if you are using MacOS or Linux
   fptr = fopen("C:\\program.txt","w");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }

   printf("Enter num: ");
   scanf("%d",&num);

   fprintf(fptr,"%d",num);
   fclose(fptr);

   return 0;
}
```
```
// Example 2: Read from a text file

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num;
   FILE *fptr;

   if ((fptr = fopen("C:\\program.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }

   fscanf(fptr,"%d", &num);

   printf("Value of n=%d", num);
   fclose(fptr);

   return 0;
}
```
```
/*
C program to find the size of file
The idea is to use fseek() in C and ftell() in C. Using fseek(),
we move file pointer to end, then using ftell(),
we find its position which is actually size in bytes.
*/

#include <stdio.h>

long int findSize(char file_name[])
{
    // opening the file in read mode
    FILE *fp = fopen(file_name, "r");

    // checking if the file exist or not
    if (fp == NULL) {
        printf("File Not Found!\n");
        return -1;
    }

    fseek(fp, 0L, SEEK_END); // ეს რას ნიშნავს? fseek() <<<<

    // calculating the size of the file
    long int res = ftell(fp); // ftell()

    // closing the file
    fclose(fp);

    return res;
}

// Driver code
int main()
{
    char file_name[] = { "program.txt" };
    long int res = findSize(file_name);
    if (res != -1)
        printf("Size of the file is %ld bytes \n", res);
    return 0;
}
```
