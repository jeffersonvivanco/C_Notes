#include <stdio.h>

int main(int argc, char const *argv[]) {
  int i;

  char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
  int int_array[5] = {1, 2, 3, 4, 5};

  char *char_pointer;
  int *int_pointer;

  char_pointer = (char *) int_array; // Typecast into the pointer's datatype
  int_pointer = (int *) char_array;

  for ( i = 0; i < 5; i++) { // Iterate through the int array using the int pointer
    printf("[integer pointer] points to %p, which contains the char '%c'\n", int_pointer, *int_pointer);
    int_pointer = (int *)((char *) int_pointer + 1);
  }

  for (i = 0; i < 5; i++) { // Iterate through the char array with the char pointer
    printf("[char pointer] points to %p, which contains the integer %d\n", char_pointer, *char_pointer);
    char_pointer = (char *)((int *) char_pointer + 1);
  }
  return 0;
}