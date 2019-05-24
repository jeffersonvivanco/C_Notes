#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size  */ 

void copy(char to[], char from[]);

int main() {
	FILE *fp;
	fp = fopen("hello.txt", "r");
	
	int c;
	int curr_max = 0;
	char curr_max_line[MAXLINE];
	char temp_line[MAXLINE];
	int temp = 0;
	
	while((c = getc(fp)) != EOF) {
		if (c == '\n') {
			temp_line[temp] = '\0';
			if (temp > curr_max) {
				curr_max = temp;
				copy(curr_max_line, temp_line);
			}
			temp = 0;
			temp_line[0] = '\0';
		} else {
			temp_line[temp] = c;
			temp++;
		}
	}
	
	if (temp > curr_max){
		temp_line[temp] = '\0';
		curr_max = temp;
		copy(curr_max_line, temp_line);
		temp = 0;
		temp_line[0] = '\0';
	}
	
	printf("The longest line is %s", curr_max_line);
}

void copy(char to[], char from[]) {
	to[0] = '\0';
	int i = 0;
	while(from[i] != '\0'){
		to[i] = from[i];
		i++;
	}
	to[i] = '\0';
}
