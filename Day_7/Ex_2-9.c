#include <stdio.h>

/********************************************************************************************************/
/* FUNCTION NAME : bitcount																	    	 	                                    */
/*																								     	                                                */																							     
/* INPUTS 	   :  1. x -- The number to count the bits												 	                        */															
/*        																						     	                                            */
/* RETURN 	   : integer																		     	                                      */
/*            																					     	                                          */
/* NOTES 	   : a faster version of bitcount function													                          */
/********************************************************************************************************/
int bitcount(unsigned int x) {
    int count = 0;
    while (x != 0) {
        x &= (x - 1);
        count++;
    }
    return count;
}

int main() {
    unsigned int input;

    // Get input from the user
    printf("Enter a positive integer: ");
    scanf("%u", &input);

    // Compute the bit count using the bitcount function
    int result = bitcount(input);

    // Display the input and the computed bit count
    printf("Input: %u\n", input);
    printf("Bit Count: %d\n", result);

    return 0;
}

