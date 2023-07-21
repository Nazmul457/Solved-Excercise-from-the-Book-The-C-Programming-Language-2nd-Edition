#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/*****************************************************************************************************/
/* FUNCTION NAME : main																			     																		 */
/*																								     																							 */																							     
/* INPUTS 	   :  1. argc -- the number of parameters provided to the main function				           */
/*       		      2. argv -- the pointer to the input string array of parameters 			               */
/*        																						                                               */
/* RETURN 	   : = 0	-- Success																     																 */
/*		  	     : < 0	-- Failed															     																		 */
/*            																																									     */
/* NOTES 	   : testing a word count program that counts lines, words, and characters in input     	 */
/*****************************************************************************************************/
int main(int argc, char *argv[]) {
	int c, nl, nw, nc, state;
	state = OUT;
	nl = nw = nc = 0;
	
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}	
	printf("New-Line:%d New-Word:%d New-Charcter:%d\n", nl, nw, nc);
	return 0;
}
