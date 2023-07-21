#include <stdio.h>
#include<string.h>

/************************************************************************************/
/* MACRO NAME : swap															  	                              */
/*																				                                         	*/																							     
/* ARGUEMENTS :   1. type   -- data types											                      */
/*       		      2.   x 	-- first value to swap 			   				                    */
/*				        3.   y  	-- second value to swap	 			                    			*/
/*        																			                                    */
/* RETURN 	   : nothing															                              */
/*            																		                                  */
/* NOTES 	   : swaping two values of any datatypes using macro definition			      */
/************************************************************************************/
#define swap(type, x, y) {type temp = x; x=y; y=temp;}

int main() {
	int a = 5, b = 6;
	printf("Swaping Two Intgers: %d %d\n", a, b);
	swap(int, a, b);
	printf("Values after swapping: %d %d\n", a, b);
	
	float x = 5.5, y = 6.6;
	printf("Swaping Two Floats: %.2f %.2f\n", x, y);
	swap(float, x, y);
	printf("Values after swapping: %.2f %.2f\n", x, y);
	
	char p = 'A', q = 'B';
	printf("Swaping Two Characters: %c %c\n", p, q);
	swap(char, p, q);
	printf("Values after swapping: %c %c\n", p, q);
	return 0;
}
