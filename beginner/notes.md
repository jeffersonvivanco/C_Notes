# C Notes

## Compilers
* A compiler is necessary to make your source code (.c, .cpp, .cc files) into a running program.
* `gcc`
  * Released by the Free Software Foundation, gcc is a nix-based C compiler usually operated via the command-line.
  * To specify a name for the executable file `gcc filename -o outputFilename`
  * To run `./outputFilename`. (The `./` is there to ensure you run the program for the current working directory)
* Catching problems early
  * To compile with all warnings enabled and to produce AINSI C compatible code (*recommended*) use the flags `-Wall -ainsi`
  * If you want to have the compiler treat warnings as errors--meaning you don't even get an executable, you can use the `-Werror` flag.
  This will make sure you don't miss an error.
* GDB ready code
  * If you want to prepare your executable for use by GDB, include the flag `-g`.
  * This will enable GDB to give you detailed debugging information by including extra code in the executable file to allow GDB to find
  variable names and list the source code.
* Math library
  * If you need to use functions from the math library (such as sin or sqrt from math.h), then you need to explicitly ask it to link with that
  library with the `-l` flag and the library `m`. `gcc filename -o outputfileName -lm`
  * Don't need it for C++
* Use `man gcc` to find out more.

## printf()
* `%d` - print as decimal integer
* `%6d` - print as decimal integer, at least 6 characters wide
* `%f` - print as floating point
* `%6f` - print as floating point, at least 6 characters wide
* `%.2f` - print as floating point, 2 characters after decimal point
* `%6.2f` - print as floating point, at least 6 characters wide and 2 after the decimal point

Among others `printf` also recognizes `%o` for octal, `%x` for hexadecimal, `%c` for character, `%s` for character string, and `%%` for `%` itself.

## symbolic constants
* `#define name replacement text`
  * ex: `#define LOWER 0`

## character input and output
* `getchar()` and `putchar()`

## functions
* Since `main` is a function like any other, it may return a value to its caller, which is in effect the environment in which the program was executed.
  * Typically a return value of `0` implies normal terminate; non-zero values signal unusual or erronous termination conditions.
* In C, all function arguments are "passed by value". This means that the called function is given values of its arguments in temporary variables rather than the originals. This leads to some different properties that are seen with "call by reference".
* When necessary, it is possible to arrange for a function to modify a variable in a calling routine. The caller must provide the *address* of the variable to be set (technically, a *pointer* to the variable), and the called function must declare the parameter to be a pointer and access the variable indirectly through it.
* The story is different for arrays. When the name of an array is used as an argument, the value passed to the function is the location or address of the beginning of the array--there is no copying of array elements. By subscripting this value, the function can access and alter any element of the array.

## Character Arrays
* `'/0'` (the null character, whose value is zero) goes at the end of the character array, to mark the end of the string of characters. This convention is also used by the C language: when a string constant like `"hello\n"` appears in a C program, it is stored as array of characters containing the character of the string and terminated with a `'\0'` to mark the end.

## External Variables and Scope
* Syntactically, external definitions are just like definitions of local variables, but since they occur outside of functions, the variables are external. Before a function can use an external variable, the name of the variable must be made known to the function. One way to do this is to write an `extern` declaration in the function; the declaration is the same as before except for the added keyword `extern`.
* Common practice is to place definitions of all external variables at the beginning of the source file, and then omit all `extern` declarations.

## Data Types
| | | 
| --- | --- |
| char | a single byte (8 bits) |
| int | an integer, typically reflecting the natural size of integers on the host machine.
| float | single-precision floating number |
| double | double-precision floating number |

* In addition, there are a number of qualifiers that can be applied to these basic types. `short` and `long` apply to integers: `short int sh;`
  * The word `int` can be omitted in such declarations.
  * The intent is that `short` and `long` should provide different lengths of integers where practical: `int` will normally be the natural size for a particular machine. `short` is often *16 bits*, `long` *32 bits*, and `int` either * 16 or 32 bits*.
* The qualifier `signed` and `unsigned`may be applied to `char` or any integer.
  * `unsigned` numbers are always positive or zero, and obey the laws of arithmetic modulo 2^n, where n is the number of bits in the type. 
  * So for instance, if chars are 8 bits, unsigned char variables have values between 0 and 255, while signed chars have values between -128 and 127 (in a two's complement machine). Whether plain chars are are signed or unsigned is machine-dependent, but printable characters are always positive.
* The type `long double` specifies extended precision floating point. As with integers, the sizes of floating-point objects are implementation defined; float, double, and long double could represent one, two, or three distinct sizes.
* The standard headers `<limits.h>` and `<float.h>` contain symbolic constants for all these sizes, along with other properties of the machine and compiler.

## Constants
* A long constant is written with a terminal `l` or `L`, as in `123456789L`; an integer too big to fit into an int will also be taken as a long. Unsigned constants are written with a terminal `u` or `U`, and the suffix `ul` or `UL` indicates `unsigned long`.
* Floating-point constants contain a decimal point (123.4) or an exponent (1e-2) or both; their type is `double`, unless suffixed. The suffixes `f` or `F` indicate a float constant; `l` or `L` indicate a long double.
* The value of an integer can be specified in octal or hexadecimal instead of decimal. A leading 0 on an integer constant means octal; a leading `0x` or `0X` means hexadecimal. For example, decimal 31 can be written as 037 in octal and `0x1f` in hex. Octal and hexadecimal constants may also be followed by `L` to make them long and `U` to make them unsigned: `0XFUL` is an unsigned long constant.
* The character constant `'\0'` represents the character with value zero, the null character. `'\0'` is often written instead of 0 to emphasize the character nature of some expression, but the numeric value is just 0.
* The *enumeration constant*. 
  * An enumeration is a list of constant integer values, as in `enum boolean {NO, YES}`
  * The first name has in an enum has value 0, the next 1 and so on, unless explicit values are specified. If not all values are specified, unspecified values continue the progression from the last specified value.

## Declarations
* The qualifier `const` can be applied to the declaration of any variable to specify that its value will not be changed. For an array, the `const` qualifier says that the elements will not be altered. The `const` declaration can also be used with array arguments, to indicate that the function does not change the array.

## Increment and Decrement Operators
* The unusual aspect is that `++` and `--` may be used as either prefix operators or postfix. In both cases, the effect is to increment the variable. But the expression `++n` increments n **before its value is used**, while `n++` increments n **after its value has been used**.

## Bitwise Operators
* C provides six operators for bit manipulation; these may only applied integral operands, that is, `char`, `short`, `int`, and `long` whether signed or unsigned.
  * `&` - bitwise AND
    * is often used to mask off some set of bits
  * `|` - bitwise inclusive OR
    * is used to turn bits on
  * `^` - bitwise exclusive OR
    * sets a one in each bit position where its operands have different bits, and zero where they are the same.
  * `<<` - left shift
    * perform left or right shifts (applies to right shift as well) of their left operand by the number of bit 
    positions given by the right operand, which must be positive. Thus `x << 2` shifts the value of x left by two 
    positions, filling vacated bits with zero; this is equivalent to multiplication by 4. 
  * `>>` - right shift
    * Right shifting an unsigned quantity always fills vacated bits with zero. Right shifting a signed quality will fill with sign bits ("arithmetic") on some machines and with 0-bits ("logical shift") on others.
  * `~` - yields the one's complement for an integer
    * that is, it converts each 1-bit into a 0-bit and vice versa.

## Precedence and Order of Evaluation
* The order in which function arguments are evaluated is not specified, so the the statement
`printf("%d %d\n", ++n, power(2, n)); // WRONG`
can produce different results with different compilers depending on whether `n` is incremented before `power`
is called.
* Function calls, nested assignement statements, and increment and decrement operators cause "side-effects"--some
variable is changed as a by-product of the evaluation of an expression. In any expression involving side effects, there can be subtle dependencies on the order in which variables taking part in the expression are updated. One unhappy situation is typified by the statement `a[i] = i++;` The question is whether the subscript is the old value of i or the new. Compilers can interpret this in different ways, and generate different answers depending on their interpretation. The standard intentionally leaves most such matters unspecified. When side effects (assignment to variables) take place within an expression, it is left to the discretion of the compiler, since the
best order depends strongly on machine architecture. (The standard does specify that all side effects on arguments
take effect before a function is called, but that would not help in the `printf()` example above).
* The moral is that writing code that depends on order of evaluation is a bad programming practice in any
language.

## Loops--While and For
* One final C operator is the comma ",", which most often finds use in the `for` statement. A pair of expressions
separated by a comma is evaluated left to right, and the type and value of the result are the type and value of the right operand. Thus in a `for` statement, it is possible to place multiple expressions in the various parts,
for example to process two indices in parallel. Look at string_reverse.c
  * The commas that separate function arguments, variables in declarations, etc., are not *comma* operators, and do not
  guarantee left to right evaluation.
  * Comma operators should be used sparingly. The most suitable uses are for constructs strongly related to each other, as in
  the `for` loop in string_reverse.c, and in macros where a multistep computation has to be a single expression. A comma
  expression might also be appropriate for the exchange of elements in string_reverse.c, where the exchange can be thought of 
  as a single operation:
  ```c
  	for (start = 0, end = SIZE_OF_ARRAY - 2; start < end; start++, end--)
		char temp = s[end], s[end] = s[start], s[start] = temp;
  ```

## Goto and Labels
* C provides the infinitely abusable `goto` statement, and labels to branch to. Formally, the `goto` is never necessary, and in practice it is almost always
easy to write code without it.
* Nevertheless, there a few situations where `gotos` may find a place. The most common is to abandon processing in some deeply nested structure, such as breaking out of two or more loops at once. The `break` statement cannot be used directly since it only exits from the innermost loop.

## Basics of functions
* The mechanics of how to compile and load a C program that resides on multiple source files vary from one system to the next.
On the UNIX system, for example, the `cc` command mentioned in Chapter 1 does the job. Suppose that three functions are stored
in three files called `main.c, getline.c, and strindex.c`. Then the command `cc main.c getline.c strindex.c` compiles the
three files, placing the resulting object code in files `main.o, getline.o, strindex.o`, then loads them all into an executable
file called `a.out`. If there's an error, say in `main.c`, that file can be recompiled by itself and the result loaded with
the previous object files, with the command `cc main.c getline.o strindex.o`. The `cc` command uses the ".c" versus ".o" naming
convention to distinguish source files from object files.

## Functions Returning Non-integers
* It is important that the calling routine know that a function returns a non-int value. One way to ensure this is to declare
the function explicitly in the calling routine. For example, below, it says that sum is a double variable and that func_a is
a function that takes one `char []` argument and returns a double
```c
int main(){
  double sum, func_a(char []);
  char c[] = "Hello";
  sum = func_a(c);
}

double func_a(char s[]){
  // do something
  return 2.0;
}
```
* The function `func_a` must be declared and defined consistently. If `func_a` itself and the call to it in `main` have
inconsistent types in the same source file, the error will be detected by the compiler. But if (as is more likely) `func_a`
were compiled seperately, the mismatch would not be detected , `func_a` would return a double that `main` would treat as an
`int`, and meaningless answers would result.
* The special case of an unnamed parameter of type `void` as the only item in the list specifies that the function has no
parameters.

## Scope Rules
* The functions and external variables that make up a C program need not all to be compiled at the same time; the source text
of the program may be kept in several files, and previously compiled routines may be loaded from libraries. Among the questions
of interest are
  * How are declarations written so that variables are properly declared during compilation?
  * How are declarations arranged so that all the pieces will be properly connected when the program is loaded?
  * How are declarations organized so there is only one copy?
  * How are external variables initialized?

* The *scope* of a name is the part of the program within which the name can be used.
* The scope of an external variable or a function lasts from the point at which it is declared to the end of the file being
compiled. If an external variable is to be referred to before it is defined, or if it is defined in a different source file
from the one where it is being used, then an `extern` declaration is mandatory.
* It is important to distinguish between the *declaration* of an external variable and its *definition*. A declaration
announces the properties of a variable (primarily its type); a definition also causes storage to be set aside. If the lines
```c
int sp;
double val[MAXVAL];
```
appear outside of any function, they *define* the external variables `sp` and `val`, cause storage to be set aside, and also
serve as the declaration for the rest of the source file. On the other hand, the lines
```c
extern int sp;
extern double val[];
```
*declare* for the rest of the source file that `sp` is an `int` and that `val` is a double array (whose size is determined
elsewhere), but they do not create the variables or reserve storage for them.
* There must be only one *definition* of an external variable among all the files that make up the source program; other files
may contain `extern` declarations to access it. (There may also be `extern` declarations in the file containing the definition.) Array sizes must be specified with the definition, but are optional with an `extern` declaration.
* Initialization of an external variable goes only with the definition.

## Static Variables
* The `static` declaration, applied to an external variable or function, limits the scope of that object to the rest of the
source file being compiled.
* The external `static` declaration is most often used for variables, but it can be applied to functions as well. Normally,
function names are global, visible to any part of the entire program. If a function is declared `static`, however, its name
is invisible outside of the file in which it is declared.
* The `static` declaration can also be applied to internal variables. Internal `static` variables are local to a particular
function just as automatic variables are, but unlike automatics, they remain in existence rather than coming and going each
time the function is activated. This means that internal `static` variables provide private, permanent storage within a
single function.

## Register Variables
* A `register` declaration advises the compiler that the variable in question will be heaviliy used. The idea is that
`register` variables are to be placed in machine registers, which may result in smaller and faster programs. But compilers
are free to ignore this advice.
* The `register` declaration can only be applied to automatic variables and to the formal parameters of a function.
* In practice, there are restrictions on register variables, reflecting the realities of underlying hardware. Only a few
variables in each function may be kept in registers, and only certain types are allowed. And it is not possible to take the
address of a register variable, regardless of whether the variable is actually placed in a register. The specific restrictions
on number and types of register variables vary from machine to machine.

## Recursion
* Recursion may provide no saving in storage, since somewhere a stack of the values being processed must be maintained. Nor
will it be faster. But recursive code is more compact, and often much easier to write and understand than the non-recursive
equivalent. Recursion is especially convenient for recursively defined data structures like trees.

## The C Preprocessor
* C provides certain language facilities by means of a preprocessor, which is conceptually a separate first step in compilation. 
* File Inclusion
  * `#include` is the preferred way to tie the declarations together for a large program. It guarantees that all the source files will be supplied with the same definitions and variable declarations, and thus eliminates a particularly nasty kind of bug. Naturally, when an included file is changed, all files that depend on it must be recompiled.
* Macro Substitution
  * A definition has the form `#define name replacement text`
  * Normally the replacement text is the rest of the line, but a long definition may be continued onto several lines by placing a `\` at the end of each line to be continued. The scope of a name defined with `#define` is from its point of definition to the end of the source file being compiled. A definition may use previous definitions.
  * Substitutions are made only for tokens, and do not take place within quoted strings.
  * Any name may be defined with any replacement text. For example,
  ```c
  #define forever for (;;) // infinite loop
  ```
  * It is also possible to define macros with arguments, so the replacement text can be different for different calls of the
  macro. As an example, define a macro called max
  ```c
  #define max(A, B) ((A) > (B) ? (A) : (B))
  ```
  * Although it looks like a function call, a use of `max` expands into in-line code. Each occurrence of a formal parameter
  (here A or B) will be replaced by the corresponding actual argument. Thus the line
  ```c
  x = max(p+q, r+s);
  ```
  * will be replaced by the line
  ```c
  x = ((p+q) > (r+s) ? (p+q) : (r+s))
  ```
  * So long as the arguments are treated consistently, this macro will serve for any data type; there is no need for different kinds of `max` for different data types, as there would be with functions. If you examine the expansion of `max`, you will
  notice some pitfalls. The expressions are evaluated twice; this is bad if they involve side effects like increment operators
  or input and output. For instance will increment larger value twice.
  ```c
  max(i++, j++); // WRONG
  ```
  * Some care also has to be taken with parentheses to make sure the order of evaluation is preserved; consider what happens when the macro is invoked as `square(z+1)`
  ```c
  #define square(x) x*x // WRONG
  ```
  * Nonetheless, macros are valuable. One practical example comes from `<stdio.h>`, in which `getchar` and `putchar` are often defined as macros to avoid the run-time overhead of a function call per character processed. The functions in `<ctype.h>` are also usually implemented as macros.
  * Names may be undefined with `#undef`, usually to ensure that a routine is really a function, not a macro
  * Formal parameters are not replaced within quoted strings. If, however, a parameter name is preceded by a `#` in the replacement text, the combination will
  be expanded into a quoted string with the parameter replaced by the actual argument. This can be combined with string concatenation to make, for example, a 
  debugging print macro:
  ```c
  #define dprint(expr) printf(#expr " = %g\n", expr)
  ```
  * When this is invoked, as in `dprint(x/y);`, the macro is expanded into `printf("x/y" " = %g\n", x/y);` and the strings are concatenated, so the effect is
  `printf("x/y = %g\n", x/y);`. Within the actual argument, each `"` is replaced by `\"` and each `\` by `\\`, so the result is a legal string constant.
  * The preprocessor operator `##` provides a way to concatenate actual arguments during macro expansion. If a parameter in the replacement text is adjacent
  to a `##`, the parameter is replaced by the actual argument, the `##` and surrounding white space are removed, and the result is re-scanned. For example,
  the macro `paste` concatenates its two arguments:
  ```c
  #define paste(front, back) front ## back
  ```
  so `paste(name, 1)` creates the token `name1`
* Conditional Inclusion
  * It is possible to control preprocessing itself with conditional statements that are evaluated during preprocessing. This provides a way to include code
  selectively, depending on the value of conditions evaluated during compilation. ====> look at beginner/macro_subs.c
  * The `#if` line evaluates a constant integer expression (which may not include `sizeof`, casts, or `enum` constants). If the expression is non-zero, subsequent
  lines until an `#endif` or `#elif` or `#else` are included. 
  * The expression `defined(name)` in a `#if` is 1 if the *name* has been defined, and 0 otherwise.
  * For example, to make sure that the contents of a file `hdr.h` are included only once, the contents of the file are surrounded with a conditional like this:
  ```c
  #if !defined(HDR)
  #define HDR

  // contents of hdr.h go here

  #endif
  ```
  * The first inclusion of `hdr.h` defines the name `HDR`; subsequent inclusions will find the name defined and skip down to the `#endif`. A similar style can
  be used to avoid including files multiple times. If this style is used consistently, then each header can itself include any other headers on which it depends,
  without the user of the header having to deal with the interdependence.
  * This sequence tests the name `SYSTEM` to decide which version of a header to include:
  ```c
  #if SYSTEM == SYSV
    #define HDR "sysv.h"
  #elif SYSTEM == BSD
    #define HDR "bsr.h"
  #elif SYSTEM == MSDOS
    #define HDR "msdos.h"
  #else
    #define HDR "default.h"
  #endif
  #include HDR
  ```
  * The `#ifdef` and `ifndef` lines are specialized forms that test whether a name is defined.

## Pointers and Arrays
* Using `malloc`
  * initializes pointers using free memory. This allows dynamic allocation of memory.
  * it is useful in setting up structures such as linked lists or data trees where you don't know exactly how much memory
  will be needed at compile time, so you have to get memory during the programs execution.
  * `malloc()`, residing in the `stdlib.h`, is used to initialize pointers with memory from free store (a section of 
  memory available to all programs).
  * the argument to `malloc` is the amount of memory requested (in bytes), and `malloc` gets a block of memory of the size
  and then returns a pointer to the block of memory allocated.
  * since different variable types have different memory requirements, we need to get a size for the amount of memory malloc should return. This can be done using the keyword `sizeof`, which takes an expression and returns its size.
  ```c
  #include <stdlib.h>
  // This code set `ptr` to point to a memory address of size `int`.
  int *ptr = malloc(sizeof(int));
  /*
  A sligtly cleaner version, gets the size of the type of ptr
  malloc(sizeof(*ptr)); 
  */
  ```
  * The memory that is pointed to becomes unavailable to other programs. **This means that the careful coder should free
  this memory at the end of its usage lest the memory be lost to the operating system for the duration of the program (this
  is often called memory leak because the program is not keeping track of all of its memory).**
  * The free function returns memory to the operating system. `free(ptr);`
* A pointer is a variable that contains the address of a variable. It "points" to locations in memory.
* Pointers are much used in C, partly because they are sometimes the only way to express a computation, and partly because they usually lead to more compact
and efficient code than can be obtained other ways.

* Pointers and addresses
  * A pointer is a group of cells (often two or four) that can hold an address.
  * The unary operator `&` gives the address of an object, so the statement `p = &c` assigns the address of `c` to the
  variable `p`, and `p` is said to "point to" c.
  * The `&` operator only applies to objects in memory: variables and array elements. It cannot be applied to expressions, constants, or register variables.
  * The unary operator `*` is the *indirection* or *dereferencing* operator; when applied to a pointer, it accesses the 
  object the pointer points to.
  * A pointer is constrained to point to a particular kind of object: every pointer points to a specific data type.
    * There's one exception: a "pointer to void" is used to hold any type of pointer but cannot be dereferenced itself.

* Pointers and function arguments
  * Since C passes arguments to functions by value, there is no direct way for the called function to alter a variable in the
  calling function.
* Pointers and arrays
  * Any operation that can be achieved by array subscripting can also be done with pointers. The pointer version will
  in general be faster but, at least to the uninitiated, somewhat harder to understand.
  ```c
  int a[10]; // defines an array a of size 10, that is a block of 10 consecutive objects named a[0], a[1], ... a[9]
  int *pa; // pointer to an integer
  pa = &a[0]; // sets pa to point to element 0 of a; that is, pa contains the address of a[0]

  int x = *pa; // will copy the contents of a[0] into x
  ```
  * The meaning of "adding 1 to a pointer" and by extension, all pointer arithmetic, is that `pa + 1` points to the
  next object, and `pa + i` points to the `i-th` object beyond `pa`.
  * The correspondence between indexing and pointer arithmetic is very close. By definition, the value of a variable
  or expression of type array is the address of element zero of the array. Thus after the assignement `pa = &a[0];`
  `pa` and `a` have identical values. Since the name of an array is a synonym for the location of the initial element,
  the assignment `pa=&a[0];` can also be written as `pa=a;`.
  * Rather more surprising, at least at first sight, is the fact that a reference to `a[i]` can also be written as
  `*(a+1)`. In evaluating `a[i]`, C converts it to `*(a+i)` immediately; the two forms are equivalent.
  * Applying the operator `&` to both parts of this equivalence, it follows that `&a[i]` and `a+i` are also identical:
  `a+i` is the address of the `i-th` element beyond `a`.
  * As the other side of this coin, if `pa` is a pointer, expressions may use it with a subscript; `pa[i]` is identical
  to `*(pa + i)`. In short, an array-and-index expression is equivalent to one written as a pointer and offset.
  * There is one difference between an array name and a pointer that must be kept in mind. A pointer is a variable,
  so `pa=a` and `pa++` are legal. But an array name is not a variable; constructions like `a=pa` and `a++` are illegal.
  * When an array name is passed to a function, what is passed is the location of the initial element. Within the called
  function, this argument is a local variable, and so an array name parameter is a pointer, that is, a variable
  containing an address.
  * As formal parameters in a function definition, `char s[];` and `char *s;` are equivalent; we prefer tha latter 
  because it says more explicitly that the parameter is a pointer.
* Address Arithmetic
  * Pointers and integers are not interchangeable. Zero is the sole exception: the constant zero may be assigned to a
  pointer, and a pointer may be compared with the constant zero. The symbolic constant `NULL` is often used in place of
  zero, as a mnemonic to indicate more clearly that this is a special value for a pointer.
  * If `p` and `q` point to members of the same array, then relations like `==`, `!=`, `<`, `>=`, etc, work properly.
  For example, `p < q` is true if `p` points to an earlier member of the array than `q` does.
  * Any pointer can be meaningfully compared for equality and inequality with zero. But the behavior is undefined for
  arithmetic or comparisons with pointers that do not point to members of the same array. (There is one exception: the
  address of the first element past the end of an array can be used in pointer arithmetic.)
  * The construction `p + n` means the address of the `n-th` object beyond the one `p` currently points to. This is true
  regardless of the kind of object `p` points to; `n` is scaled according to the size of the objects `p` points to, which
  is determined by the declaration of `p`. If an `int` is four bytes, for example, the `int` will be scaled by four.
  * Pointer subtraction is also valid: if `p` and `q` point to elements of the same array, and `p < q`, then `q - p + 1`
  is the number of elements from `p` to `q` inclusive.
  * The valid pointer operations are assignment of pointers of the same type, adding or substracting a pointer and an
  integer, subtracting or comparing two pointers to members of the same array, and assigning or comparing to 0. All other
  pointer arithmetic is illegal. It is not legal to add 2 pointers, or to multiply or divide or shift or mask them, or
  to add `float` or `double` to them, or even, except for `void *`, to assign a pointer of one type to a pointer of another
  type without a cast.
* Character pointers and functions
  * There is an important difference between these definitions:
  ```c
  char amessage[] = "now is the time"; // an array
  char *pmessage = "now is the time"; // a pointer
  ```
  * `amessage` is an array, just big enough to hold the sequence of characters and `\0` that initializes it. Individual
  characters within the array may be changed but `amessage` will always refer to the same storage.
  * On the other hand, `pmessage` is a pointer, initialized to point to a string constant; the pointer may subsequently
  be modified to point elsewhere, but the result is undefined if you try to modify the string constants.
  * frequent in C programs
  ```c
  void strcpy(char *s, char *t){
    while(*s++ = *t++)
      ;
  }
  ```
  * Also, `amessage++` is not allowed and `amessage = pmessage` is also not allowed
  * Difference between `*(amessage++)` and `*(amessage + 1)`
    * `amessage++` increments the pointer to the next location which changes where the pointer is pointing to, which is not allowed for array types. `amessage + 1`
    however, points to the next element but it doesn't increment the pointer. Array name cannot be a modifiable value.
* Pointer Arrays; Pointers to Pointers
  * Since pointers are variables themselves, they can be stored in arrays just as other variables can.
* Multi-dimensional Arrays
  * If a two-dimensional array is to be passed to a function, the parameter declaration in the function must include the
  number of columns; the number rows is irrelevant, since what is passed  is, as before, a pointer to an array of rows, where
  each row is an array of 13 ints. Thus if the array `daytab` is to be passed to a function `f`, the declaration of `f` would
  be `f(int daytab[2][13]) { ... }`.
  * It could also be `f(int daytab[][13]) { ... }` since the number of rows is irrelevant
  * or it could be `f(int (*daytab)[13]) { ... }` which says that the parameter is a pointer to an array of 13 integers
  * **Only the first dimension (subscript) of an array is free; all the others have to specified.**
* Initialization of Pointer Arrays
```c
static char *name[] = {
  "Illegal month",
  "January", "February", "March", "April", "May", "June", "July", "August", "September", "October",
  "November", "December"
};
```
  * Since the size of the array `name` is not specified, the compiler counts the initializers and fills in the correct number.
* Pointers vs. Multi-dimensional Arrays
  * Given the definitions
  ```c
  int a[10][20];
  int *b[10];
  ```
  then `a[3][4]` and `b[3][4]` are both syntactically legal references to a single `int`. But `a` is a true two-dimensional array: 200 `int`-sized locations have been set aside, and the conventional rectangular subscript calculation `20xrow+col` is used to find the element `a[row][col]`.
  * For `b`, however, the definition only allocates 10 pointers and does not initialize them; initialization must be done
  explicitly, either statically or with code.
    * Assuming that each element of `b` does point to a twenty-element array, then there will be 200 `ints` set aside, plus
    ten cells for the pointers.
    * The important advantage of the pointer array is that the rows of the array may be of different lengths. That is, each
    element of b need not point to a twenty-element vector; some may point to two elements, some to fifty, and some to none at
    all.
  * The most frequent use of arrays of pointers is to store character strings of diverse lengths.

* Command-line Arguments
  * A commmon convention for C programs on UNIX systems is that an argument that begins with a minus sign introduces an
  optional flag or parameter. For example, in our `find_pattern_in_line.c` program. If we choose `-x` (for "except") to
  signal the inversion, and `-n` ("number") to request line numbering, then the command `find -x -n pattern` will print
  each line that doesn't match the pattern, preceded by its line number. 
  * Optional arguments should be permitted in any order, and the rest of the program should be independent of the number of
  arguments that were present.
  * Furthermore, it is convenient for users if option arguments can be combined, as in `find -nx pattern`
  * ===> Look at command_line_args.c, find_patter_in_line.c

* Pointer to functions
  * In C, a function itself is not a variable, but it is possible to define pointers to functions, which can be assigned, placed in arrays, passed
  to functions, returned by functions, and so on.
  * ====> Look at pointers_to_functions.c

## Structures
* A structure is a collection of one or more variables, possibly of different types, grouped together under a single name
for convenient handling. (Structures are called "records" in some languages, notably Pascal.) Structures help to organize
complicated data, particularly in large programs, because they permit a group of related variables to be treated as a unit
instead of as seprarate entities.
* Basics
  * ====> Look at structures_basics.c
* Structures and Functions
  * The only legal operations on a structure are copying it or assigning to it as a unit, taking its address with `&`, and accessing its members. Copy and
  assignment include passing arguments to functions and returning values from functions as well.
  * Structures may not be compared.
  * A structure may be initialized by a list of constant member values; an automatic structure may also be initialized by an assignment.
  * **structure parameters are passed by value like any others**
  * **If a large structure is to be passed to a function, it is generally more efficient to pass a pointer than to copy the whole structure.**
  * If `pp` points to a `point structure`, `*pp` is the structure, and `(*pp).x` and `(*pp).y` are the members.
  * Pointers to structures are so frequently used that an alternative notation is provided as a shorthand. If `p` is a pointer to a structure, then
  `p->member-of-structure` refers to the particular member.
  * The structure operators `.` and `->`, together with `()` for function calls and `[]` for subscripts, are at the top of the precedence hierarchy
  and thus bind very tightly. For example, given the declaration:
  ```c
  struct {
    int len;
    char *str;
  } *p;
  ``` 
  then `++p->len` increments len, not p, because the implied parenthesization is `++(p->len)`. Parenthesis can be used to alter the binding: 
  `(++p)->len` increments p before accessing len.
  * In the same way, `*p->str` fetches whatever str points to; `*p->str++` increments str after accessing whatever it points to (just like 
  `*s++`); `(*p->str)++` increments whatever str points to; and `*p++->str` increments p after accessing whatever str points to.
  * ====> Look at structures_basics.c
* Array of structures
  * The structure declaration
  ```c
  struct key {
    char *word;
    int count;
  } keytab[NKEYS];
  ```
  declares a structure type `key`, defines an array `keytab` of structures of this type, and sets aside storage for them. Each element of the
  array is a structure. This could also be written
  ```c
  struct key {
    char *word;
    int count;
  };
  struct key keytab[NKEYS];
  ```
  * The structure initialization is analogous to earlier ones--the definition is followed by a list of initializers enclosed in braces:
  ```c
  struct key {
    char *word;
    int count;
  } keytab[] = {
    "auto", 0,
    "break", 0
    /* ... */
  };
  ```
  The initializers are listed in pairs corresponding to the structure members. It would be more precise to enclose initializers for each "row"
  or structure in braces, as in `{"auto", 0}, ...` but the inner braces are not necessary when the initializers are simple variables or character
  strings, and when all are present.
  * The size of the array is the size of one entry times the number of entries, so the number of entries is just *size of keytab / size of struct
  key*.
    * C provides a compile-time unary operator called `sizeof` that can be used to compute the size of any object. The expressions
      * `sizeof` *object*
      * `sizeof(`*type name*`)`
    yield an integer equal to the size of the specified object or type in bytes. (Strictly, `sizeof` produces an unsigned integer value whose type,
    `size_t`, is defined in the header `<stddef.h>`.) An object can be a variable or array or structure. A type name can be the name of a basic type
    like `int` or `double`, or a derived type like a structure or pointer.
    * A `sizeof` can not be used in a `#if` line, because the preprocessor does not parse type names. But the expression in the `#define` is not 
    evaluated by the preprocessor, so the code here is legal.
* Pointers to Structures
  * The addition of two pointers is illegal. Subtraction is legal, however, so `high - low` is the number of elements.
  * Don't assume, however, that the size of the structure is the sum of the sizes of its members. Because of alignment requirements for different
  objects, there may be unnamed "holes" in a structure. Thus, for instance, if a char is 1 byte and an int is 4 bytes, the structure
  ```c
  struct {
    char c;
    int i;
  };
  ```
  might well require 8 bytes, not five. The `sizeof` operator returns the proper value.
* Self-referential Structures
  * Suppose we want to handle the more general problem of counting
  the occurrences of all the words in some input. Since the list of
  words isn't known in advance, we can't conveniently sort it and
  use a binary search. Yet we can't do a linear search for each word
  as it arrives, to see if it's already been seen; the program would
  take too long. (More precisely, its running time is likely to
  grow quadratically with the number of input words.) How can we
  organize the data cope efficiently with a list of arbitrary words?
  * We will use a data structure called a *binary tree*.
  * The tree containe one "node" per distinct word; each node
  contains 
    * a pointer to the text of the word
    * a count of the number of occurrences
    * a pointer to the left child node
    * a pointer to the right child node
  * No node may have more than two children; it might have only
  zero or one.
  * The nodes are maintained so that at any node the left subtree
  contains only words that are lexicographically less than the word
  at the node, and the right subtree contains only words that are
  greater.
  * To find out whether a new word is already in the tree, start
  at the root and compare the new word to the word stored at that
  node. If they match, the question is answered affirmatively. If
  the new word is less than the tree word, continue searching at
  the left child, otherwise at the right child. If there is no child
  in the required direction, the new word is not in the tree, and
  in fact the empty slot is the proper place to add the new word.
  This process is recursive, since the search from any node uses
  a search from one of its children.
  * Going back to the description of the node, it is conveniently
  represented as a structure with 4 components.
  ```c
  struct tnode { // the tree node
    char *word; // points to the text
    int count; // number of occurrences
    struct tnode *left; // left child
    struct tnode *right; // right child
  }
  ```
  * Occasionally, one needs a variation of self-referential
  structures: two structures that refer to each other The way to
  handle this is:
  ```c 
  struct t {
    //...
    struct s *p; // p points to an s
  }

  struct s {
    struct t *q; // q points to a t
  }
  ```
  * A practical note: if the tree becomes "unbalanced" because the
  words don't arrive in random order, the running time of the
  program can grow too much. As a worst case, if the words are
  already in order, this program does an expensive simulation of
  linear search. There are generalizations of the binary tree that
  do not suffer from this worst-case behavior.
  * Clearly it's desirable that there be only one storage allocator
  in a program, even though it allocates different kinds of objects.
  But if one allocator is to process requests for, say, pointers to
  chars and pointers to struct tnodes, two questions arise. First,
  how does it meet the requirement of most real machines that
  objects of certain types must satisfy alignment restrictions (for
  example, integers often must be located at even addresses)?
  Second, what declarations can cope with the fact that an allocator
  must necessarily return different kinds of pointers?
  * Alignment requirements can generally be satisfied easily, at
  the cost of some wasted space, by ensuring that the allocator
  always returns a pointer that meets all alignement restrictions.
  `malloc()` from `<stdlib.h>` guarantees the alignment 
  requirements.
  * The question of the type declaration for a function like
  `malloc()` is a vexing one for any language that takes its type-
  checking seriously. In C, the proper method is to declare that
  `malloc()` returns a pointer to `void`, then explicitly coerce
  the pointer into the desired type with a cast. `malloc` returns
  `NULL` if no space is available. Storage obtained by calling
  `malloc` may be freed for re-use by calling `free`.
* Table Lookup
