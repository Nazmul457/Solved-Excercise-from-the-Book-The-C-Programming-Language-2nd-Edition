#include <stdio.h>

/*****************************************************************************************************/
/* FUNCTION NAME : main																			     																		 */
/*																								     																							 */																							     
/* INPUTS 	   :  1. argc -- the number of parameters provided to the main function				     			 */
/*       		  		2. argv -- the pointer to the input string array of parameters 			     					 */
/*        																						     																					 */
/* RETURN 	   : = 0	-- Success																     																 */
/*		  	   	 : < 0	-- Failed																     																	 */
/*            																					     																				 */
/* NOTES 	   : print Celsius-Fahrenheit table for celsius = 0, 20, ... 300       				     				 */
/*****************************************************************************************************/
int main(int argc, char *argv[]) {
	float celsius, fahr;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;
	
	celsius = lower;
  	printf("Celsius\tFahrenheit\n");
  	while (celsius <= upper) {
    	fahr = (9.0 / 5.0) * celsius + 32.0f;
    	printf("%3.0f\t%6.1f\n", celsius, fahr);
    	celsius = celsius + step;
  	}
  	return 0;
}
