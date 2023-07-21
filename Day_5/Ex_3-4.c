#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define MAXLEN 1000

/*****************************************************************************************************/
/* FUNCTION NAME : reverse																		                                       */
/*																								                                                   */																							     
/* INPUTS 	   :  1. s1    -- the array to reverse												                           */
/*       		      2. index -- the array in which the binary search occurs							               */
/*				        3. size  -- the size of the array													                         */
/*        																						                                               */
/* RETURN 	   : nothing																		                                         */
/*            																					                                             */
/* NOTES 	   :  reverse the given array														 	                                 */
/*****************************************************************************************************/
void reverse(char s1[], int index, int size) {
	char temp;
  	temp = s1[index];
  	s1[index] = s1[size - index];
  	s1[size - index] = temp;

  	if (index == size / 2) {
    	return;
  	}
  	reverse(s1, index + 1, size);
}

/*****************************************************************************************************/
/* FUNCTION NAME : i_to_a																		                                         */
/*																								                                                   */																							     
/* INPUTS 	   :  1. n   -- the value to convert												                             */
/*       		      2. s[] -- the array to store the converted character              								 */
/*        																						                                               */
/* RETURN 	   :  nothing	                                    																	     */
/* NOTES 	   :  integer to character conversion function handling the smallest negetive number 	     */
/*****************************************************************************************************/
void i_to_a(int n, char s[]) {
    int i, sign;
    sign = n;
    i = 0;
    do { 
        s[i++] = abs(n % 10) + '0';
    } while (n /= 10); 
    if (sign < 0)
        s[i++] = '-';    
    s[i] = '\0';
    int str_length = strlen(s);
    reverse(s, 0, str_length-1);
}

/*****************************************************************************************************/
/* FUNCTION NAME : main																			                                         */
/*																								                                                   */																							     
/* INPUTS 	   :  no parameters																	                                     */
/*        																						                                               */
/* RETURN 	   : = 0	-- Success																                                     */
/*		  	     : < 0	-- Failed															                                         */
/*            																					                                             */
/* NOTES 	     : invoking the other functions with necessary parameters						 	                 */
/*****************************************************************************************************/
int main(void) {
  	int n;
  	printf("Enter the integer to convert: ");
  	scanf("%d", &n);
  	char s[MAXLEN];
  	i_to_a(n, s);
  	printf("The Converted String from Integer is: %s\n", s);
return 0;
}

