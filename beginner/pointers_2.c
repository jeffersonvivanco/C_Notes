#include <stdio.h>

void test_pointer();
void test_pointer_2();

int main(){
	test_pointer_2();
}

void test_pointer(){
	
	char s_1[] = "Hello World!"; // char array that holds string
	char *s_1_p = &s_1[0]; // pointer that points to the first char of s_1[]

	printf("[Debug] string (array): {%s}\n", s_1);
	printf("[Debug] string (pointer): {%s}\n", s_1_p);
	
	printf("[Debug] first char of string pointer: {%c}\n", *s_1_p); 
	printf("[Debug] first char of string array: {%c}\n", *s_1);
	
}

void test_pointer_2(){
	
	char *s_1 = "Hello zalma";
	char s_1_array[] = "hello world";
	int index = 0;
	
	printf("\ns_1_array before copy is {%s}", s_1_array);
	
	// copying elements from s_1 (pointer) to s_1_array (char array)
	while ((s_1_array[index++] = *s_1++))
		;
		
	printf("\ns_1_array after copy is {%s}", s_1_array);
}
