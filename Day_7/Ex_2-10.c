#include <stdio.h>

/********************************************************************************************************/
/* FUNCTION NAME : lower																	    	 	                                      */
/*																								     	                                                */																							     
/* INPUTS 	   :  1. c -- character to convert into lowercase										 	                      */															
/*        																						     	                                            */
/* RETURN 	   : integer																		     	                                      */
/*            																					     	                                          */
/* NOTES 	   : converts upper case letters to lower case, with a conditional 							              */
/*				 expression instead of if-else															                                  */
/********************************************************************************************************/
int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

int main() {
    char input;
    printf("Enter a character: ");
    scanf(" %c", &input);

    char converted = lower(input);

    printf("Original character: %c\n", input);
    printf("Converted character: %c\n", converted);

    return 0;
}
