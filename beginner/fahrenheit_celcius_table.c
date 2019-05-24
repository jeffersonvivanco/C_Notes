#include <stdio.h>

/*
 * print fahrenheit-celcius table
 * for fahr = 0, 20, ... 300
 */
 
 int main(){
	 float fahr, celcius;
	 int lower, upper, step;
	 
	 lower = 0; // lower limit of temp table
	 upper = 300; // upper limit of temp table
	 step = 20; // step size
	 
	 fahr = lower;
	 // heading
	 printf("%3s %6s\n", "Fahr", "Celcius");
	 while(fahr <= upper){
		 celcius = (5.0/9.0) * (fahr-32.0);
		 printf("%3.0f\t%6.1f\n", fahr, celcius); // adding a width to right justify the numbers
		 fahr += step;
	 }
 }



