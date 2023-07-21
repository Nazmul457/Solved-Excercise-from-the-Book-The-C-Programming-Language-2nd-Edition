#include <stdio.h>
#define OUT 0
#define IN 1

/*****************************************************************************************************/
/* FUNCTION NAME : main																			     																		 */
/*																								     																							 */																							     
/* INPUTS 	   :  1. argc -- the number of parameters provided to the main function				     		   */
/*       		      2. argv -- the pointer to the input string array of parameters 			               */
/*        																																											     */
/* RETURN 	   : = 0	-- Success																																     */
/*		  	     : < 0	-- Failed																     																	 */
/*            																					                                             */
/* NOTES 	   : program to print its input one word per line	 			 	 				 	                       */
/*****************************************************************************************************/
int main(int argc, char *argv[]) {
	int c;
	int state;

  	state = OUT;
  	while ((c = getchar()) != EOF) {
    	if (c != ' ' && c != '\t' && c != '\n') {
      		putchar(c);
      		state = IN;
    	}
	    else if (state) {
	      	putchar('\n');
	      	state = OUT;
	    }
  	}
  return 0;
}
