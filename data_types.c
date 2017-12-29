#include <stdio.h>

int main(int argc, char *argv[]){
	int myint = 5;
	char myc = 'c';
	char *char_pointer = "Hello World";

	printf("Size of int in C is %i bytes\n", sizeof(myint));
	printf("Size of char in C is %i bytes\n", sizeof(myc));
	printf("Size of a char pointer is %i bytes\n", sizeof(char_pointer));
}
