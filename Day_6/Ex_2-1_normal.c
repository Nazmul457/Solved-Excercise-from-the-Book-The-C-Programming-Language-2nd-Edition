#include <stdio.h>
#include <limits.h>

/*****************************************************************************************************/
/* FUNCTION NAME : main																			                                         */
/*																								                                                   */																							     
/* INPUTS 	   :  nothing																			                                       */
/*        																						                                               */
/* RETURN 	   : = 0	-- Success                                                                     */
/*				       < 0	-- Failed																                                       */
/*            																					                                             */
/* NOTES 	   : printing appropriate values of char, short, int, and long variables,                  */
/*				 both signed and unsigned from standard headers										                         */
/*****************************************************************************************************/
int main(void)
{
  printf("------------------------ CHARACTER ----------------------\n");
  printf("bits: %d\n", CHAR_BIT);
  printf("unsigned char max: %d\n", UCHAR_MAX);
  printf("signed char min: %d\n", SCHAR_MIN);
  printf("signed char max: %d\n", SCHAR_MAX);
  printf("\n");

  printf("------------------------- INTEGER -----------------------\n");
  printf("unsigned int max: %u\n", UINT_MAX);
  printf("signed int min: %d\n", INT_MIN);
  printf("signed int max: %d\n", INT_MAX);
  printf("\n");

  printf("---------------------- SHORT INTEGER --------------------\n");
  printf("unsigned short int max: %u\n", USHRT_MAX);
  printf("signed short int min: %d\n", SHRT_MIN);
  printf("signed short int max: %d\n", SHRT_MAX);
  printf("\n");

  printf("------------------------ LONG INTEGER -------------------\n");
  printf("unsigned long int max: %lu\n", ULONG_MAX);
  printf("signed long int min: %ld\n", LONG_MIN);
  printf("signed long int max: %ld\n", LONG_MAX);
  printf("\n");

  printf("-------------------- LONG LONG INTEGER -------------------\n");
  printf("unsigned long long int max: %llu\n", ULLONG_MAX);
  printf("signed long long int min: %lld\n", LLONG_MIN);
  printf("signed long long int max: %lld\n", LLONG_MAX);
  printf("\n");

  return 0;
}
