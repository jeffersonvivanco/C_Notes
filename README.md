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
 * this is where the assembled machine language instructions of the program are
   located. The execution of instructions in this segment is nonlinear, thanks to    the aforementioned high-level control structures and functions, which compile
   into branch, jump, and call instructions in assembly language. As a program
   executes, the EIP is set to the first instruction in the text segment. The
   processor then follows an execution loop that does the following:
   
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
      value
   2. the return address: is used to restore EIP to the next instruction found
      after the function call. This restores the functional context of the
      previous stack frame.

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
  * jeff$ $(perl -e 'print "uname";')
* Command substitution and Perl can be used in combination to quickly generate overflow buffers on
  the fly.
* You can use this technique to easily test a program with buffers of precise lengths.
* This technique can be applied to overwrite the return address in a program with an exact value.

