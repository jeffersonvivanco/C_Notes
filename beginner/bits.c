#include <stdio.h>

/*
 * Returns the (right adjusted) n-bit field of x that begins at position p 
 */
unsigned getbits(unsigned, int, int);

int main() {
	// 10 in bits is: 0...01010
	// 3 in bits is: 0...0110
	printf("%d",getbits(10, 4, 3));
}

unsigned getbits(unsigned x, int p, int n){
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

