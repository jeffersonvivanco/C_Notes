#include <stdio.h>
#include <string.h>

int mystrcmp(char *str1, char *str2);

int main() {
	
	int i = 0;
	int y, x = 0;
	
	/*
	 * i is evaluated then incremented
	 * ex: when i = 9, it will get evaluated and then incremented to 10
	 * Below prints from 1 to 10
	 * */
	while (i++ < 10) {
		
		printf("\n[Debug] i++ %i", i);
		
	}
	
	i = 0;
	
	/*
	 * i is incremented then is evaluated!!
	 * ex: when i = 9, it will incremented to 10 and then evaluated
	 * Below prints from 1 to 9
	 * */
	while (++i < 10) { 
		
		printf("\n[Debug] ++i %i", i);
		
	}
	
	while (x < 10){
		
		printf("\n[Debug] x++ %i", x);
		/*
		 * x is incremented
		 * x++ or ++x makes no difference
		 * it only gets incremented and evaluated in the while loop
		 * */
		x++;
		
	}
	
	/*
	 * Does not matter whether is y++ or ++y it only gets incremented
	 * Note: y++ < 10 will get evaluated then incremented
	 * and ++y < 10 will get incremented and then evaluated
	 * */
	for (y = 0; y < 10; y++) {
		
		printf("\n[Debug] y++ %i", y);
		
	}
	
	// comparing strings
	char a_str_1[6] = "Hello";
	char a_str_2[6] = "Hello";
	char *a_str_p1 = &a_str_1[0];
	int cmp_result = strcmp(a_str_p1, a_str_2);
	printf("\nstr1: {%s}, str2: {%s}, cmp_result: {%i}",a_str_p1, a_str_2, cmp_result);
}

int mystrcmp(char *str1, char *str2) {
	
	
	if (strlen(str1) != strlen(str2)) {
		return 0;
	}
	
	while (*str1 == *str2) {
		str1++;
		str2++;
		if (*str1 == '\0') {
			break;
		}
	}
	
	return *str1 == '\0' ? 1 : 0;
	
}


