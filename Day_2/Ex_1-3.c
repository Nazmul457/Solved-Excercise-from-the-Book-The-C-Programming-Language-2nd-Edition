#include <stdio.h>

/*****************************************************************************************************/
/* FUNCTION NAME : main																			     																		 */
/*																								     																							 */																							     
/* INPUTS 	   :  1. argc -- the number of parameters provided to the main function				     			 */
/*       		  	  2. argv -- the pointer to the input string array of parameters 			     					 */
/*        																						     																					 */
/* RETURN 	   : = 0	-- Success																     																 */
/*		  	   	 : < 0	-- Failed																     																	 */
/*            																					     																				 */
/* NOTES 	   : print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300       				     					 */
/*****************************************************************************************************/
int main(int argc, char *argv[]) {
	float fahr, celsius;
	float lower, upper, step;
	
	lower = 0; /* lower limit of temperature scale */
	upper = 300; /* upper limit */
	step = 20; /* step size */
	
	fahr = lower;
	printf("Fahrenheit\tCelsius\n");
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f\t\t%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}

