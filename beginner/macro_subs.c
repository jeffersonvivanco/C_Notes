#include <stdio.h>

#define NUMBER 1

#if NUMBER
	#define MESSAGE "true"
#else
	#define MESSAGE "false"
#endif
	
int main(){
	printf("%s", MESSAGE);
}
