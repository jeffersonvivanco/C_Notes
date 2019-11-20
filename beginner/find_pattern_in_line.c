#include <stdio.h>
#include <string.h>

#define MAXLINE 1000 // max input line length

int getline2(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

/*find: print lines that match pattern from 1st arg*/
int main(int argc, char *argv[]) {
	char line[MAXLINE];
	int lineno = 0;
	
	int c, except = 0, number = 0, found = 0;
	
	/*
	 * argc is decremented and argv is incremented before each optioal
	 argument. At the end of the loop, if there are no errors, argc tells
	 how many arguments remain unprocessed and argv points to the first of
	 these.
	 * */
	while (--argc > 0 && (*++argv)[0] == '-')
		while ((c = *++argv[0]))
			switch (c) {
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("find: illegal option %c\n", c);
					argc = 0;
					found = -1;
					break;
			}
			
	printf("[Debug] argc {%d}, argv[1] {%s}\n", argc, argv[1]);

	if (argc != 1) printf("Usage: find -x -n pattern\n");
	else 
		while(getline2(line, MAXLINE) > 0){
			lineno++;
			/*
			 * strstr(s, t) from string.h returns a pointer to the first occurrence
			 of the string t in the string s, or NULL if there is none.
			 * */
			if ((strstr(line, *argv) != NULL) != except){
				if (number) printf("%1d: ", lineno);
				printf("%s", line);
				found ++;
			}
		}
	return found;
}

// getline2: get line into s, return length
int getline2(char s[], int lim) {
	int c, i;
	
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n') s[i++] = c;
	
	if (c == '\n') s[i++] = c;
	
	s[i] = '\0';

	return i;
}

// strindex: return index of t in s, -1 if none
int strindex(char s[], char t[]){
	int i, j, k;
	
	for (i = 0; s[i] != '\0'; i++){
		for (j = i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++);
		
		if (k > 0 && t[k] == '\0') return i;
	}
	
	return -1;
}
