#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100

/*****************************************************************************************************/
/* FUNCTION NAME : reverse																		                                       */
/*																								                                                   */																							     
/* INPUTS 	   :  1. s1    -- the array to reverse												                           */
/*       		      2. index -- the array in which the binary search occurs														 */
/*				        3. size  -- the size of the s1 array																							 */
/*        																						     																					 */
/* RETURN 	   : nothing																		                                         */
/*            																					                                             */
/* NOTES 	   : reverse the given array														 	                                 */
/*****************************************************************************************************/
void reverse_str(char s1[], int index, int size)
{
  char temp;

  temp = s1[index];
  s1[index] = s1[size - index];
  s1[size - index] = temp;

  if (index == size / 2)
  {
    return;
  }

  reverse_str(s1, index + 1, size);
}

/*****************************************************************************************************/
/* FUNCTION NAME : itob																		     	                                     */
/*																								                                                   */																							     
/* INPUTS 	   :  1. n   -- the value to convert												                             */
/*       		      2. s[] -- the array to store the converted character								               */
/*				        3. b   -- the base value to convert in											                       */
/*        																						                                               */
/* RETURN 	   :  nothing																		                                         */
/* NOTES 	   :  integer number to any base number conversion function 		 	 				                 */
/*****************************************************************************************************/
void itob(int n, char s[], int b) {
    int i, sign;
    sign = n;
    i = 0;
    do {
		int digit = abs(n%b);
		if(digit<10)
			s[i++] = digit + '0';
		else
			s[i++] = digit - 10 + 'A'; 
    } while (n /= b); 
    if (sign < 0)
        s[i++] = '-';    
    s[i] = '\0';
    int str_length = strlen(s);
    reverse_str(s, 0, str_length-1);
}

/*****************************************************************************************************/
/* FUNCTION NAME : main																			     																		 */
/*																								                                                   */																							     
/* INPUTS 	   :  no parameters																	                                     */
/*        																						                                               */
/* RETURN 	   : = 0	-- Success																                                     */
/*		  	     : < 0	-- Failed																     																	 */
/*            																					                                             */
/* NOTES 	   :  invoking the other functions with necessary parameters						 	                 */
/*****************************************************************************************************/
int main(void)
{
 	int n, b;
  	printf("Enter the value to convert: \n");
  	scanf("%d", &n);
  	printf("Enter the base: \n");
  	scanf("%d", &b);
  	char s[MAXLEN];
  	itob(n, s, b);
  	printf("The Converted Number is: %s\n", s);
}
