#include <stdio.h>

#define SIZE_OF_ARRAY 6

void reverse();

int main() {
	
	char s[SIZE_OF_ARRAY] = "Hello\0";
	printf("word: %s\n", s);
	reverse(s);
	printf("word reversed: %s\n", s);
}

void reverse(char *s){

	int start, end;
	for (start = 0, end = SIZE_OF_ARRAY - 2; start < end; start++, end--){
		char temp = s[end];
		s[end] = s[start];
		s[start] = temp;
	}
}
