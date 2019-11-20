#include <stdio.h>

/* echo command line arguments
 * @param argc: the number of command-line arguments the program was invoke
 with.
 * @paeam argv: is a pointer to an array of character strings that contain
 the arguments, one per string. By convention, argv[0] is the name of which
 the program was invoked, so argc is atleast 1.
*/
int main(int argc, char *argv[]) {
	
	int i;
	
	for (i = 1; i < argc; i++)
		printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
		
	printf("\n");
	return 0;
	
}
