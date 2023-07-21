#include <stdio.h>

/*****************************************************************************************************/
/* FUNCTION NAME : binaryString																    	                                 */
/*																								                                                   */																							     
/* INPUTS 	   :  1. num   -- the value to search													                           */
/*       		  2. bits -- the array in which the binary search occurs							                   */
/*				  													 								        																			 */
/*        																						     																					 */
/* RETURN 	   : nothing	  																	     																	 */
/*            																					     																				 */
/* NOTES 	   :  converts integer to binary		 											 	 															 */
/*****************************************************************************************************/
void binaryString(unsigned int num, int bits) {
	int i;
    for (i = bits - 1; i >= 0; i--) {
        unsigned int mask = 1u << i;
        printf("%d", (num & mask) ? 1 : 0);
    }
}

/*****************************************************************************************************/
/* FUNCTION NAME : invert																	    	 																		 */
/*																								     																							 */																							     
/* INPUTS 	   :  1. x -- The number to invert bits into																						 */
/*       		      2. p -- the value of position          		          															 */
/*				        3. n -- the number of bits to invert												 											 */
/*        																						     																					 */
/* RETURN 	   : unsigned integer																                                     */
/*            																					                                             */
/* NOTES 	   : setbits(x,p,n,y) that returns x with the n bits that begin at position 	 		         */
/*				 p set to the rightmost n bits of y, leaving the other bits unchanged. 		 	 	             */
/*****************************************************************************************************/
unsigned int invert(unsigned int x, int p, int n) {
    unsigned int mask = (1 << n) - 1; //create a mask of the desired size
    mask = mask << (p - n + 1);  //Shifting the mask to the correct position
    
    unsigned int result = x ^ mask; //combine x and the modified mask
    
    return result;
}

int main() {
    unsigned int x;
    int p, n;
    
    // Get input for Test Case 1
    printf("Test Case 1:\n");
    printf("Enter the number to invert: ");
    scanf("%u", &x);
    
    printf("Binary number: ");
    binaryString(x, 8 * sizeof(x));
    printf("\n\n");
    
    printf("Enter the value of position: ");
    scanf("%d", &p);
    printf("Enter the number of bits to invert: ");
    scanf("%d", &n);
    
    unsigned int result1 = invert(x, p, n);
    
    printf("Result (Decimal): %u\n", result1);
    
	printf("Result (Binary): ");
    binaryString(result1, 8 * sizeof(result1));
    printf("\n\n");
    
    // Get input for Test Case 2
    printf("Test Case 2:\n");
    printf("Enter the number to invert: ");
    scanf("%u", &x);
    printf("Enter the value of position: ");
    scanf("%d", &p);
    printf("Enter the number of bits invert: ");
    scanf("%d", &n);
    
    unsigned int result2 = invert(x, p, n);
    
    printf("Result (Decimal): %u\n", result2);
    printf("Result (Binary): ");
    binaryString(result2, 8 * sizeof(result2));
    printf("\n\n");
    
    return 0;
}

