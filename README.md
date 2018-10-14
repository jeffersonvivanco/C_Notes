# C_Notes

These are my notes on C. My notes compose of short C programs that explain
the concepts of C. Please use a linux distro to run these short programs. 
(I recommend Kali Linux.)

Use the -g option when compiling to be able to debug it later using gdb.
If you don't have gdb, install by running -> apt install gdb.

* The GNU development tools include a program called objdump, which can be used to
examine compiled binaries. ex: objdump -D a.out | grep -A20 main.:. In the example,
we use grep to only print out the first 20 lines after the general expression main:.
* objdump displays the binaries in hexadecimal bytes and in assembly language. There are
two types of assembly languages, AT&T and Intel, default is AT&T, but Intel is so much
easier to read. To change it to Intel add -M intel to objdump.
* The GNU development tools also include a debugger called GDB. Debuggers are used by
programmers to step through compiled programs, examine program memory, and view processor
registers.

## language specific
* sizes
 * signed & unsigned integers: 4 bytes
 * short int: 2 bytes
 * long int: 4 bytes
 * long long int: 8 bytes
 * float: 4 bytes
 * char: 1 byte
 * 
* signed, unsigned, long, short
 * default is signed which means they can be both negative and positive
  * A 32 bit signed integer is still just 32 bits, which means it can only be in one of 2^32 possiblw
    bit combinations. This allows 32 bit signed integers to range from -2,147,483,648 to 2,147,483,647.
    Essentially one of the bits is a flag marking the value positive or negative.
  * Positively signed values look the same as unsigned values, but negative numbers are stored differently
    using a method called two's complement.
  * Two's complement represents negative numbers in a form suited for binary adders--when a negative value
    in two's complement is added to a positive number of the same magnitude, the result will be 0. This is
    done by first writing the positive number in binary, then inverting all the bits, and finally adding 1.
    It sounds strange but it works and allows negative numbers to be added in combination with positive numbers
    using simple binary adders.
 * unsigned: dont allow negative values
  * Since it's all just memory in the end, all numerical values must be stored in binary, and unsigned
    values make the most sense in binary.
  * A 32-bit unsigned integer can contain values from 0 (all binary 0s) to 4,294,967,295 (all binary 1s)
* pointers
 * pointers in C can be defined and used like any other variable type. 
 * size depends
  * on a x86 architecture where memory uses 32-bit addressing, pointers are also 32 bit in size. (4 bytes).
  * my machine, the memory uses 64-bit addressing, so when I call sizeof on a pointer it says 8 bytes.

 * Pointers are defined by prepending an asterisk ( * ) to the variable name. Instead of defining a variable of
   that type, a pointer is defined as something that points to data of that type (a memory address is stored that
   points to data of that type).
 * In order to see the actual data stored in the pointer variable, you must use the address-of-operator. The
   address-of-operator is an unary operator, which simply means it operates on a single argument. This operator is
   just an ampersand (&) prepended to a variable name. When it's used, the address of that variable is returned, instead
   of the variable itself. This operator exists both in GDB and in the C programming language. 
 * An additional unary operator called the dereference operator exist for use with pointers. This operator will return
   the data found in the address the pointer is pointing to, instead of the address itself. It takes the form of an
   asterisk in front of the variable name, similar to the declaration of a pointer. This operator exists both in GDB
   and in C.
* format strings
 * printf() uses format parameters to format the strings
 * Each format parameter begins with a percent sign and uses a single-character short hand very similar to formatting
   characters used by GDB's examine command.
 * Parameters that receive their data as values
  * %d : decimal
  * %u : Unsigned decimal
  * %x : hexadecimal 
 * Parameters that expect pointers
  * %s : string
  * %n : number of bytes written so far
  * %p : outputs memory address (meant for pointers) equivalent to 0x%08x
* input
 * scanf() works like printf() but it instead is used for input
 * scanf expects all arguments to be pointers
* typecasting
 * is simply a way to temporarily change a variable's data type, despit how it was originally defined
 * ex: (float)a
* convert
 * atoi() : converts character to integer
* variable scoping
 * Each function has it's own set of variables, which are independent of everything else. In fact, multiple calls to the same
   function all have their own contexts.
 * variables can also have a global scope, which means they will persist across all functions. Variables are global
   if they are defined at the beginning of the code, outside of any functions.
 * variables can also be defined as static variables by prepending the keyword static to the variable definition. Similar to
   global variables, a static variable remains intact between function calls; however, static variables are also akin to local
   variables since they remain local within a particular function context. One different and unique feature of static variables
   is that they are only initialized once.
* file access
 * 2 primary ways to access files in C: file descriptors and file streams, ex: look at simplenote.c
 * file descriptors are more low level
  * a file descriptor is a number that is used to reference open files
 * 4 common functions that use file descriptors are open(), close(), read(), and write(). All of these functions will return
   -1 is there is an error. 
 * The open() function opens a file for reading and/or writing and returns a file descriptor. The returned file descriptor
   is just an integer value, but it is unique among open files. The file descriptor is passed as an argument to the other
   functions like a pointer to the opened file. 
 * For the close() function, the file descriptor is the only argument. 
 * The read and write functions' arguments are the file descriptor, a pointer to the data to read or write, and the number
   of bytes to read or write from that location.
 * The arguments to the open() are a pointer to the filename to open and a series of predefined flags that specify the
   access mode.
 * The first set of flags is found in fcntl.h and is used to set the access mode. The access mode must use at least one of the
   following three flags:
  1. O_RDONLY - open file for read only access
  2. O_WRONLY - open file for write only access
  3. O_RDWR - open file for both write and read access.
 * These flags can be combined with several other optional flags using the bitwise OR operator. A few of the more common and
   useful of these flags are as follows:
  1. O_APPEND - write data at the end of the file
  2. O_TRUNC - if the file already exists, truncate the file to 0 length
  3. O_CREAT - create the file if it doesn't exist
 * If the O_CREAT flag is used in access mode for the open() function, an additional argument is needed to define the file permissions
   of the newly created file. This argument uses bit flags defined in sys/stat.h, which can be combined with each other using bitwise
   OR logic.
  1. S_IRUSR - give the file read permission for the user (owner)
  2. S_IWUSR - give the file write permission for the user (owner)
  3. S_IXUSR - give the file execute permission for the user (owner)
  4. S_IRGRP - give the file read permission for the group
  5. S_IWGRP - give the file write permission for the group
  6. S_IXGRP - give the file execute permission for the group
  7. S_IROTH - give the file read permission for anyone
  8. S_IWOTH - give the file write permission for anyone
  9. S_IXOTH - give the file execute permission for anyone
* common errors
 * segmentation fault: when a program attempts to access an address that is out of bound so it crashes and dies
* user ids
 * Every user on a Unix system has a unique user ID number. This user ID can be displayed using the id command.
 * The root user with user ID 0 is like the admin, which has full access to the system.
 * The su command can be used to switch to a different user, and if this command is run as root, it can be done
   without a password.
 * The sudo command allows a single command to be run as the root user.
 * The command chsh allows any user to change his or her own login shell.
 * Ex: The program needs to be able to make changes to the /etc/passwd file, but only on the line that pertains to the current
   user's account. The solution to this problem in unix is the setuid permission. This is an additional file permission bit that
   can be set using chmod. When a program with this flag is executed, it runs as the user id of the file's owner.
 * This means that a running program has both a real user ID and an effective user ID. These IDs can be retrieved using the
   functions getuid() and geteuid().
 * The chown command can be used to change the owner and group of a file
 * The chmod u+s command turns on the setuid permission.

## registers
* The first four registers (EAX, ECX, EDX, and EBX) are known as general purpose registers.
These are called accumulator, Counter, Data, and Base registers, respectively. They mainly
act as temporary variables for the CPU when it is executing machine instructions.
* The second four registers (ESP, EBP, ESI, and EDI) are also general purpose registers,
but they are sometimes known as pointers and indexes. These stand for Stack Pointer, Base Pointer, 
Source Index, and Destination Index, respectively. The first two registers are called pointers
because they store 32-bit addresses, which essentially point to that location in memory. These
registers are fairly important to program execution and memory management. The last two registers
are also technically pointers, which are commonly used to point to the source and destination when
data needs to be read from or written to. There are load and store instructions that use these
registers, but for the most part, these registers can be thought of as just simple general purpose
registers.
* The EIP register is the Instruction Pointer register, which points to the current instruction the
processor is reading.
* The remaining EFLAGS register actually consists of several bit flags that are used for comparisons
and memory segmentations. The actual memory is split into several different segments, and these
registers keep track of that. For the most part, these registers can be ignored since they rarely
need to be accessed directly.

## gdb notes
* Run it with -q to supress the welcome banner.
* The x86 processor values are stored in little indian byte order, which means the least significant
byte is stored first.
* man ascii - to look up ascii values

### Understanding Assembly
* The assembly instructions in Intel syntax generally follow this style
	operation <destination>, <source>
* The destination and source values will either be a register, a memory address, or a value.
* The operations are usually intuitive mnemonics: The mov operation will move a value from the source
to the destination, sub will subtract, inc will increment, and so forth.
* There are also operations that are used to control the flow of execution. The cmp operation is used to
compare values, and basically any operation beginning with j is used to jump to a different part of code.
* The lea instruction is an acronym for Load Effective Address




Commands:

* list: shows you the code, use list again to see remaining code.
* break: sets up a breakpoint, ex: break 9, sets a breakpoint at line 9
* run: runs the code, ex: run AAAA, runs the code with a command line argument of AAA
* x/s: examines a certain address of memory, x is short for examine, s is for string, 
	*  s is the display format. It is optionally preceded by a count of how many units to examine.
	   Some common format letters are as follows.
		1. o: Display in octal
		2. x: Display in hexadecimal
		3. u: Display in unsigned, standard base-10 decimal
		4. t: Display in binary
		5. s: Display an entire string of character data
		6. i: Display the memory as disassembled assembly language instructions
		7. c: Can be used to look up a byte in the ascii table
		8. d: Display as decimal.
	* The default size of a single unit is a four-byte word unit called a word. The size of the display units
	  for the examine command can be changed by adding a size letter to the end of the format letter. The valid size
	  letters are as follows:
		1. b: A single byte
		2. h: A halfword, which is 2 bytes in size
		3. w: A word, which is 4 bytes in size
		4. g: A giant, which is 8 bytes in size.
	* This is slightly confusing, because sometimes the term word also refers to 2-byte values. In this case
	  a double word or DWORD refers to a 4-byte value
* print: prints, can do arithmetic as well
* disass: disassembles a function ex -> disass main
* cont: continues to run the program
* info registers: will info about the processor's registers
* set dis intel: sets the disassembly syntax to intel (easier to read)
* info register registerName : info about that register
* nexti: execute current instruction, 


### Memory Segmentation
A compiled program's memory is divided into five segments
1. text
 * also called the code segment
 * this is where the assembled machine language instructions of the program are  located. The execution 
   of instructions in this segment is nonlinear, thanks to the aforementioned high-level control structures
   and functions, which compile into branch, jump, and call instructions in assembly language. As a program
   executes, the EIP is set to the first instruction in the text segment. The  processor then follows an execution 
   loop that does the following:
   1. Reads the instruction that EIP is pointing to
   2. Adds the byte length of the instruction to EIP
   3. Executes the instruction that was read in step 1
   4. Goes back to step 1
2. data
 * the data segment is filled with the initialized global and static variables
3. bss
 * the bss segment is filled with  uninitialized variables
4. heap
 * the heap segment is a segment of memory a programmer can directly control.
 * blocks of memory in this segment can be allocated and used for whatever the
   programmer might need.
 * not a fixed size, can grow larger or smaller as needed
 * all of the memory within the heap is managed by allocator and deallocator
   algorithms
 * the growth of the heap moves downward toward higher memory addresses
5. stack
 * the stack segment also has variable size and is used as a temporary scratch
   pad to store local function variables and context during function calls.
 * this is what GDB's backtrace command looks at.
 * when a program calls a function, that function will have its own set of
   passed variables, and the function's code will be at a different memory
   location in the text (or code) segment. Since the context and the EIP must
   change when a function is called, the stack is used to remember all of the
   passed variables, the location the EIP should return to after the function
   is finished, and all the local variables used by that function.
 * all of this information is stored together on the stack in what is
   collectively called a stack frame. The stack contains many stack frames.
 * in general compsci terms, a stack is an abstract data structure that is used
   frequently. It has first-in, last-out (FILO) ordering.
 * opposite to the dynamic growth of the heap, as the stack changes in size, it
   grows upward in a visual listing of memory, toward lower memory addresses.
 * the FILO nature of a stack might seem odd, but since the stack is used to
   store context, it's very useful. When a function is called, several things 
   are pushed to the stack together in a stack frame. The EBP register
   sometimes called the frame pointer (FP) or local base (LB) pointer--is used
   to reference local function variables in the current stack frame. Each stack
   frame contains the parameters to the function, its local variables, and two
   pointers that are necessary to put things back the way they were:
   1. the saved frame pointer (SFP): is used to restore EBP to its previous 
      value. If the program is compiled with the flag -fomit-frame-pointer for
      optimization, the frame pointer won't be used in the stack of the frame.
   2. the return address: is used to restore EIP to the next instruction found
      after the function call. This restores the functional context of the
      previous stack frame. If you disassemble main, the next instruction's
      address after the function call is the return address. When the function
      finishes, the leave and ret instructions remove the stack frame and set the
      execution pointer register (EIP) to the saved return address in the stack
      frame.

### Generalized Exploit Techniques
* Buffer Overflows
 1. While C's simplicity increases the programmer's control and efficiency of the 
    resulting programs, it can also result in programs that are vulnerable to buffer
    overflows and memory leaks if the programmer isn't careful. This means that once
    a variable is allocated memory, there are no built-in safe guards to ensure that 
    the contents of a variable fit into the allocated memory space. If a programmer wants
    to put ten bytes of data into a buffer that had only been allocated eight bytes of
    space, that type of action is allowed, even though it will most likely cause the
    program to crash. This is known as a buffer overrun or buffer overflow, since the
    extra two bytes of data will overflow and spill out of the allocated memory, overwriting
    whatever happens to come next.

### Experimenting with BASH
The BASH shell and Perl are common on most machines and are all that is needed to experiment
with exploitation.

* Perl: is an interpreted programming language with a print command that happens to be particularly
suited to generating long sequences of characters. Perl can be used to execute instructions on the
command line by using the -e switch like this.
 * ex:jeff$ perl -e 'print "A" x 20;'
 * This command prints A 20 times
 * Any character, such as a nonprintable character, can also be printed by using, \x##, where ##
   is the hexadecimal value of the character.
 * In addition, string concatenation can be done in Perl with a period. This can be useful when
   stringing multiple addresses together.
* An entire shell command can be executed like a function, returning its output in place. This is done
  by surrounding the command with parentheses and prefixing a dollar sign.
  * jeff$ u$(perl -e 'print "na";')me
  * This exact command-substitution effect can be accomplished with grave accent marks.(`)
  * jeff$ u`perl -e 'print "na";`me
* Command substitution and Perl can be used in combination to quickly generate overflow buffers on
  the fly.
* You can use this technique to easily test a program with buffers of precise lengths.
* This technique can be applied to overwrite the return address in a program with an exact value.
* shellcode: instructions that tell the program to restore privilages and open a shell prompt.

### Using the Environment
* Sometimes a buffer is too small to hold even shellcode.
* Environment variables are used by the user shell for a variety of things, but what they are used for isn't
as important as the fact they are located on the stack and can be set from the shell.
  * ex: setting an env variable called MYVAR to the string test -> export MYVAR=test
