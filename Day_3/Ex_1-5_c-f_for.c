#include <stdio.h>

/*****************************************************************************************************/
/* FUNCTION NAME : main																			                                         */
/*																								     																							 */																							     
/* INPUTS 	   :  1. argc -- the number of parameters provided to the main function				           */
/*       		  2. argv -- the pointer to the input string array of parameters     			               */
/*        																						                                               */
/* RETURN 	   : = 0	-- Success																                                     */
/*		  	   : < 0	-- Failed																                                         */
/*            																					                                             */
/* NOTES 	   : print Celsius-Fahrenheit table for celsius = 300, 280, ... 0 using for loop	         */
/*****************************************************************************************************/
int main(int argc, char *argv[]) {
	int celsius;
	
  	printf("Celsius\tFahrenheit\n");
  	for(celsius=300; celsius>=0; celsius-=20) {
  		printf("%3d \t%6.1f\n", celsius, (9.0/5.0)*celsius+32);
	  }
  	return 0;
}

