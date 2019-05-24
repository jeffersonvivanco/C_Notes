#include <stdio.h>

void line_counting();
void copy_input();
void word_counting();
// count digits, white space, others
void count_digits_white_space();

int main(){
	// call a function
	
}

void line_counting(){
	int lines = 0;
	int c;
	while((c = getchar()) != EOF){
		if (c == '\n'){
			lines ++;
		}
	}
	
	printf("lines = %d", lines);
}

void copy_input(){
	int c;
	
	while ((c = getchar()) != EOF){
		putchar(c);
	}
}

void word_counting(){
	int c, words = 0;
	
	while((c = getchar()) != EOF){
		if (c == '\t' || c == '\n' || c == ' '){
			words++;
		}
	}
	
	printf("words %d", words);
}

void count_digits_white_space(){
	int c, i, nwhite, nother;
	int ndigit[10];
	
	nwhite = nother = 0;
	for (i = 0; i < 10; ++i){
		ndigit[i] = 0;
	}
	
	while((c = getchar()) != EOF){
		if (c >= '0' && c <= '9') ++ndigit[c-'0'];
		else if (c == ' ' || c == '\n' || c == '\t') ++nwhite;
		else ++nother;
	}
	
	printf("digits = ");
	for (i =0; i < 10; ++i) printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d", nwhite, nother);
}
