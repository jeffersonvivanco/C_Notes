# C_Notes

These are my notes on C. My notes compose of short C programs that explain
the concepts of C. Please use a linux distro to run these short programs. 
(I recommend Kali Linux.)

Use the -g option when compiling to be able to debug it later using gdb.
If you don't have gdb, install by running -> apt install gdb.

##gdb notes
Run it with -q to supress the welcome banner.

Commands:

* list: shows you the code, use list again to see remaining code.
* break: sets up a breakpoint, ex: break 9, sets a breakpoint at line 9
* run: runs the code, ex: run AAAA, runs the code with a command line argument of AAA
* x/s: examines a variable or data structure, x is for examines and s is for string, 
* print: prints, can do arithmetic as well

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
 * not a fixed size, can grow larger or smaller
5. stack
