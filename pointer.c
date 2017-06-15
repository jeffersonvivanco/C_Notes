#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char str_a[20]; // A 20-element character array
  char *pointer; // A pointer, meant for a character array
  char *pointer2; // And yet another one

  strcpy(str_a, "Hello, world!\n");
  pointer = str_a; // set the first pointer to the start of the array
  printf(pointer);

  pointer2 = pointer + 2; // Set the second one 2 bytes further in
  printf(pointer2);
  strcpy(pointer2, "y you guys!\n"); //copy into that spot
  printf(pointer);
  
  return 0;
}
