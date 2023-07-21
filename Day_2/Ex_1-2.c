#include <stdio.h>

/*****************************************************************************************************/
/* FUNCTION NAME : main																			     																		 */
/*																								     																							 */																							     
/* INPUTS 	   :  1. argc -- the number of parameters provided to the main function				     			 */
/*       		  2. argv -- the pointer to the input string array of parameters     			     					 */
/*        																						     																					 */
/* RETURN 	   : = 0	-- Success																     																 */
/*		  	   : < 0	-- Failed																     																		 */
/*            																					     																				 */
/* NOTES 	   : Experiment to find out what happens when prints's argument string contains \c         */
/*****************************************************************************************************/
int main(int argc, char *argv[]) {
	printf("Hello World\c");
	return 0;
}
