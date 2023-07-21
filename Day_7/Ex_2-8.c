#include <stdio.h>
/********************************************************************************************************/
/* FUNCTION NAME : rightrot																	    	 	                                    */
/*																								     	                                                */																							     
/* INPUTS 	   :  1. x -- The number to rotate bits into											 	                        */
/*       		      2. n -- number of positions                             														 	*/
/*        																						     	                                            */
/* RETURN 	   : unsigned integer																     	                                  */
/*            																					     	                                          */
/* NOTES 	   : rightrot(x,n) returns the value of the integer x rotated to the right by n positions.	  */
/********************************************************************************************************/
unsigned int rightrot(unsigned int x, int n) {
    unsigned int rightmost_bits = x & ((1 << n) - 1);
    unsigned int remaining_bits = x >> n;
    unsigned int result = rightmost_bits << (sizeof(x) * 8 - n) | remaining_bits;
    return result;
}

int main() {
    unsigned int x;
    int n;

    printf("Enter the number to rotate: ");
    scanf("%u", &x);
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &n);

    unsigned int result = rightrot(x, n);

    printf("Original number: %u\n", x);
    printf("Rotated number: %u\n", result);

    return 0;
}

