#include <stdio.h>

void swap(int*, int*);

int main(){
	int x = 1;
	int *ip; // ip is a pointer to an int
	
	ip = &x; // ip now points to the address of x
	
	printf("Address of x is {%p}, and the value is {%i}", ip, *ip); // *ip gets the object the pointer points to, which is x
	
	*ip = *ip + 10;
	printf("\nval of x is {%i} and value of ip is {%i}", x, *ip);
	
	int *iq; // another pointer
	iq = ip; // pointing iq to whatever ip pointed
	
	printf("\nval of iq is {%i}", *iq);
	
	// swapping values, pass by reference
	int a = 5, b = 15;
	printf("\nval of a is {%i}, val of b is {%i}, swapping ...", a, b);
	swap(&a, &b);
	printf("\nval of a is {%i}, val of b is {%i}", a, b);
}


void swap(int *a, int *b){
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
	getchar
	
}
