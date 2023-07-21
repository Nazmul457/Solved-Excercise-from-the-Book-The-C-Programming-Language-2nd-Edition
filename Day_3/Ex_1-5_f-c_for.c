#include <stdio.h>

/*****************************************************************************************************/
/* FUNCTION NAME : main																			     																		 */
/*																								                                                   */																							     
/* INPUTS 	   :  1. argc -- the number of parameters provided to the main function				           */
/*       		      2. argv -- the pointer to the input string array of parameters     			           */
/*        																						                                               */
/* RETURN 	   : = 0	-- Success																                                     */
/*		  	     : < 0	-- Failed																                                       */
/*            																					                                             */
/* NOTES 	   : print Fahrenheit-Celsius table for Fahrenheit = 300, 280, ... 0 using for loop	       */
/*****************************************************************************************************/
int main(int argc, char *argv[]) {
	int fahr;
	
  	printf("Fahrenheit\tCelsius\n");
  	for(fahr=300; fahr>=0; fahr-=20) {
  		printf("%3d \t\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32));
	  }
  	return 0;
}

