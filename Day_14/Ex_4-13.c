#include <stdio.h>
#include<string.h>
#define SIZE 100
/************************************************************************************/
/* FUNCTION NAME : reverse														  	                          */
/*																					                                        */																							     
/* INPUTS 	   :  1. s1    -- the character array to reverse						            */
/*       		      2. index -- the index from where the recursion occurs			       	*/
/*				        3. size  -- the size of the array									                */
/*        																			                                    */
/* RETURN 	   : nothing															                              */
/*            																		                                  */
/* NOTES 	     : reverse the given array using recursion						                */
/************************************************************************************/
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

int main() {
    char str[SIZE];
    printf("Enter a string to reverse: ");
    fgets(str, sizeof(str), stdin);
    reverse(str, 0, strlen(str) - 1);
    printf("The string after reverse is: %s", str);
    return 0;
}

