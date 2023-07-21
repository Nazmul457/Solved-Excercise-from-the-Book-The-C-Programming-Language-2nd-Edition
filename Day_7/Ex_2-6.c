#include <stdio.h>

/*****************************************************************************************************/
/* FUNCTION NAME : binaryString																    	                                 */
/*																								                                                   */																							     
/* INPUTS 	   :  1. num   -- the value to search													                           */
/*       		      2. bits -- the array in which the binary search occurs							               */
/*				  													 								                                               */
/*        																						                                               */
/* RETURN 	   : nothing	  																	                                       */
/*            																					                                             */
/* NOTES 	   :  converts integer to binary		 											 	                               */
/*****************************************************************************************************/
void binaryString(unsigned int num, int bits) {
	int i;
    for (i = bits - 1; i >= 0; i--) {
        unsigned int mask = 1u << i;
        printf("%d", (num & mask) ? 1 : 0);
    }
}

/*****************************************************************************************************/
/* FUNCTION NAME : setbits																	    	                                   */
/*																								                                                   */																							     
/* INPUTS 	   :  1. x -- The number to set bits into												                         */
/*       		  		2. p -- Enter the value of position                    							               */
/*				  			3. n -- Enter the number of bits to set											                       */
/*				  			4. y -- Enter the value of bits to set											                       */
/*				  													 								                                               */
/*        																						                                               */
/* RETURN 	   : unsigned integer																                                     */
/*            																					                                             */
/* NOTES 	     : function setbits(x,p,n,y) that returns x with the n bits that begin at position     */
/*				       p set to the rightmost n bits of y, leaving the other bits unchanged. 		 	 	       */
/*****************************************************************************************************/
unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {
    unsigned int mask = (1 << n) - 1; //create a mask of the desired size
    mask = mask << (p - n + 1);  //Shifting the mask to the correct position
    
    x = x & ~mask; //Clearing the bits in x that will be replaced
    
    unsigned int y_bits = y & ((1 << n) - 1); //Get the rightmost n bits of y
    y_bits = y_bits << (p - n + 1); //Shift the bits of y to the correct position
    
    unsigned int result = x | y_bits; //combine the modified x and y_bits
    
    return result;
}


/*****************************************************************************************************/
/* FUNCTION NAME : main																		    	 */
/*																								     */																							     
/* INPUTS 	   :  1. num   -- the value to search													 */
/*       		  2. bits -- the array in which the binary search occurs							 */
/*				  													 								 */
/*        																						     */
/* RETURN 	   : =0 : success  																	     */
/*            	 <0 : failed																	     */
/* NOTES 	   :  function to invoke other functions with input output							 	 */
/*****************************************************************************************************/
int main() {
    unsigned int x, y;
    int p, n;
    
    // Get input for Test Case 1
    printf("Test Case 1:\n");
    printf("Enter the number to set bits into: ");
    scanf("%u", &x);
    
    printf("Binary number: ");
    binaryString(x, 8 * sizeof(x));
    printf("\n\n");
    
    printf("Enter the value of position: ");
    scanf("%d", &p);
    printf("Enter the number of bits to set: ");
    scanf("%d", &n);
    printf("Enter the value of bits to set: ");
    scanf("%u", &y);
    
    unsigned int result1 = setbits(x, p, n, y);
    
    printf("Result (Decimal): %u\n", result1);
    
	printf("Result (Binary): ");
    binaryString(result1, 8 * sizeof(result1));
    printf("\n\n");
    
    // Get input for Test Case 2
    printf("Test Case 2:\n");
    printf("Enter the number to set bits into: ");
    scanf("%u", &x);
    printf("Enter the value of position: ");
    scanf("%d", &p);
    printf("Enter the number of bits to set: ");
    scanf("%d", &n);
    printf("Enter the value of bits to set: ");
    scanf("%u", &y);
    
    unsigned int result2 = setbits(x, p, n, y);
    
    printf("Result (Decimal): %u\n", result2);
    printf("Result (Binary): ");
    binaryString(result2, 8 * sizeof(result2));
    printf("\n\n");
    
    return 0;
}

