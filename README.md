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

## gdb notes
Run it with -q to supress the welcome banner.

Commands:

* list: shows you the code, use list again to see remaining code.
* break: sets up a breakpoint, ex: break 9, sets a breakpoint at line 9
* run: runs the code, ex: run AAAA, runs the code with a command line argument of AAA
* x/s: examines a variable or data structure, x is for examines and s is for string, 
* print: prints, can do arithmetic as well
* disass: disassembles a function ex -> disass main
* cont: continues to run the program

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
