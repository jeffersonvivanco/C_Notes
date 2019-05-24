#include <stdio.h>


#define INTEGER_CONSTANT 1234		// Integer constant

#define LONG_INTEGER_CONSTANT 1234l // long int constant

#define UNSIGNED_CONSTANT 12u 		// unsigned constant

#define UNSIGNED_LONG 1234ul		// unsigned long constant

/*
 * Floating point constants contain a decimal point (123.4) or an exponent
 (1e-2) or both; their type is double, unless suffixed.
 * The suffixes f indicate a float constant; l indicates a long double
 * 
 * The value of an integer can be specified in octal or hexadecimal instead of
 decimal. A leading zero on an integer constant means octal; a leading 0x means
 hexadecimal. For example, decimal 31 can be written as 037 in octal and 0x1f
 in hex.
 * Octal and hexadecimal constants may also be followed by L to make them long
 and U to make them unsigned.
 */
 

int main(){
	long long_number = 1234l;
	long_number = 123l;
	printf("%ld", long_number);
	return 0;
}
