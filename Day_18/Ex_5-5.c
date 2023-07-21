#include <stdio.h>
#include <string.h>

/*****************************************************************************************************/
/* FUNCTION NAME : my_strncpy																     	                                   */
/*																								                                                   */																							     
/* INPUTS 	   :  1. *dest -- pointer to the destination string to copy in						               */
/*       		      2. *src -- pointer to the source string to copy 						                       */
/*				        3. n   -- number of elements to copy from source to destination 		               */
/*        																						                                               */
/* RETURN 	   :  pointer to a character														                                 */
/* NOTES 	   :  copy n elements from source string to destination string 						 	               */
/*****************************************************************************************************/
char* my_strncpy(char *dest, const char *src, size_t n)
{
    char *dest_start = dest;
    size_t i;

    for (i = 0; i < n && *src != '\0'; i++) {
        *dest++ = *src++;
    }

    for (; i < n; i++) {
        *dest++ = '\0';
    }

    return dest_start;
}

/*****************************************************************************************************/
/* FUNCTION NAME : my_strncat																     	                                   */
/*																								                                                   */																							     
/* INPUTS 	   :  1. *dest -- pointer to the destination string to concat with					             */
/*       		      2. *src -- pointer to the source string to concat		               							   */
/*				        3. n   -- number of elements to concat by source with destination					         */
/*        																						                                               */
/* RETURN 	   :  pointer to a character														                                 */
/* NOTES 	     :  copy n elements from source string to destination string 					 	               */
/*****************************************************************************************************/
char* my_strncat(char *dest, const char *src, size_t n)
{
    char *dest_start = dest;
    
    while (*dest != '\0') {
        dest++;
    }
    
    size_t i;
    for (i = 0; i < n && *src != '\0'; i++) {
        *dest++ = *src++;
    }
    
    *dest = '\0';
    
    return dest_start;
}

/*****************************************************************************************************/
/* FUNCTION NAME : my_strncmp																     	                                   */
/*																								                                                   */																							     
/* INPUTS 	   :  1. *s1 -- pointer to the 1st string to compare with 2nd string				             */
/*       		      2. *s2 -- pointer to the 2nd string to compare with 1st string	          				 */
/*				        3. n   -- number of elements of both strings to compare				                     */
/*        																						                                               */
/* RETURN 	   :  integer																		                                         */
/* NOTES 	     :  compare n elements of both 1st and 2nd string		 						 	                     */
/*****************************************************************************************************/
int my_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;
    for (i = 0; i < n; i++) {
        if (*s1 != *s2) {
            return (*s1 - *s2);
        }
        else if (*s1 == '\0') {
            return 0;
        }     
        s1++;
        s2++;
    }
    
    return 0;
}

/*****************************************************************************************************/
/* FUNCTION NAME : main																			                                         */
/*																								                                                   */																							     
/* INPUTS 	   :  no parameters																	                                     */
/*        																						                                               */
/* RETURN 	   : = 0	-- Success	                                 															     */
/*		  	     : < 0	-- Failed																                                       */
/*            																					                                             */
/* NOTES 	   :  invoking all other functions with necessary parameters						 	                 */
/*****************************************************************************************************/
int main() {
    char source[] = "Hello, world!";
    char destination[10];
		    
    my_strncpy(destination, source, 5);
    destination[sizeof(destination) - 1] = '\0';
    printf("Original String: %s\n", source);
	printf("The function 'strncpy' Invoked!\n");
	printf("Result: %s\n\n", destination);
	
	char source1[] = "Hello, ";
    char destination1[] = "world!";
    printf("String1 = %s String2 = %s\n", source1, destination1);
	my_strncat(destination1, source1, strlen(source1));
	printf("The function 'strncat' Invoked!\n");
	printf("Result: %s\n\n", destination1);
	
	char str1[] = "Hello";
    char str2[] = "Hell";
    printf("str1 = %s, str2 = %s\n", str1, str2);
    printf("The function 'strncat' Invoked!\n");
	int result = my_strncmp(str1, str2, 5);
    if (result < 0) {
        printf("str1 is less than str2\n");
    }
    else if (result > 0) {
        printf("str1 is greater than str2\n");
    }
    else {
        printf("str1 is equal to str2\n");
    }
	
    return 0;
}

