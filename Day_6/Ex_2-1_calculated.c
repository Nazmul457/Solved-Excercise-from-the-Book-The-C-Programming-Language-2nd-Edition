#include <stdio.h>
#include <math.h>
#include <limits.h>

/*****************************************************************************************************/
/* FUNCTION NAME : main																 			                                         */
/*																								                                                   */																							     
/* INPUTS 	   :  nothing																			                                       */
/*        																						     																					 */
/* RETURN 	   : = 0	-- Success                                                                     */
/*				 			< 0	-- Failed																                                         */
/*            																					                                             */
/* NOTES 	   : printing appropriate values of char, short, int, and long variables,                  */
/*				 both signed and unsigned by direct computation										                         */
/*****************************************************************************************************/
int main(){
	
	printf("------------------------- INTEGER ---------------------\n");
	printf("Integer unsigned maximum value: %u\n", (unsigned)(pow(2, 32)-1));
	printf("Integer unsigned minimum value: %u\n", (unsigned)0);
	printf("Integer signed maximum value: %d\n", (signed)(pow(2, 31)-1));
	printf("Integer signed minimum value: %d\n", (signed)(-pow(2, 31)));
		
	printf("---------------------- SHORT INTEGER --------------------\n");
	printf("Short Integer unsigned maximum value: %u\n", (unsigned)(pow(2, 16)-1));
	printf("Short Integer unsigned minimum value: %d\n", (unsigned)0);
	printf("Short Integer signed maximum value: %d\n", (signed)(pow(2, 16)-1));
	printf("Short Integer signed minimum value: %d\n", (signed)(-pow(2, 16)));
	
	printf("------------------------ LONG INTEGER ------------------\n");
	printf("Long Integer unsigned maximum value: %lu\n", (unsigned long)(pow(2, 64)-1));
	printf("Long Integer unsigned minimum value: %lu\n", (unsigned long)0);
	printf("Long Integer signed maximum value: %ld\n", (signed long)(pow(2, 64)-1));
	printf("Long Integer signed minimum value: %ld\n", (signed long)(-pow(2, 64)));
	
	printf("--------------------- LONG LONG INTEGER ----------------------\n");
	printf("Long Long Integer unsigned maximum value: %llu\n", (unsigned long long)(pow(2, 64)-1));
	printf("Long Long Integer unsigned minimum value: %llu\n", (unsigned long long)0);
	printf("Long Long Integer signed maximum value: %lld\n", (signed long long)(pow(2, 64)-1));
	printf("Long Long Integer signed minimum value: %lld\n", (signed long long)(-pow(2, 64)-1));
	
	printf("------------------------- CHARACTER -----------------------\n");
	printf("Character unsigned maximum value: %d\n", (unsigned)(pow(2, 8)-1));
	printf("Character unsigned minimum value: %d\n", (unsigned)0);
	printf("Character signed maximum value: %d\n", (signed)(pow(2, 7)-1));
	printf("Character signed minimum value: %d\n", (signed)(-pow(2, 7)));
	
	return 0;
	
}
