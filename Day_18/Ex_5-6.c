#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NUMBER '0'
#define MAX_INPUT_SIZE 100

/********************************************************************************************/
/* FUNCTION NAME : my_getline																                                */
/*								                                            															*/																							     
/* INPUTS 	   :  1. *s  -- pointer to the source string to be match from				          	*/
/*       		      2. lim -- maximum size of character array where the input line is stored	*/
/*        																					                                        */
/* RETURN 	   : integer																	                                  */
/*            																				                                      */
/* NOTES 	   : get line into s, return length		       				    				                  */
/********************************************************************************************/
int my_getline(char *s, int lim) {
    int c;
    char *s_start = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        *s++ = c;
    }

    if (c == '\n') {
        *s++ = c;
    }

    *s = '\0';

    return s - s_start;
}

/********************************************************************************************/
/* FUNCTION NAME : my_atoi																	                                */
/*																							                                            */																							     
/* INPUTS 	   :  1. *s  -- pointer to the source string to convert							            */
/*        																					                                        */
/* RETURN 	   : integer																	                                  */
/*            																				                                      */
/* NOTES 	   : convert s to integer				       				    				                        */
/********************************************************************************************/
int my_atoi(const char *s)
{
    int n = 0;
    int sign = 1;

    while (isspace(*s))
        s++;

    if (*s == '-' || *s == '+') {
        if (*s == '-')
            sign = -1;
        s++;
    }

    while (isdigit(*s)) {
        n = n * 10 + (*s - '0');
        s++;
    }

    return sign * n;
}

/********************************************************************************************/
/* FUNCTION NAME : reverse																	                                */
/*																							                                            */																							     
/* INPUTS 	   :  1. *s  -- pointer to the source string to reverse							            */
/*        																					                                        */
/* RETURN 	   : nothing																	                                  */
/*            																				                                      */
/* NOTES 	   : reverse the given string			       				    				                      */
/********************************************************************************************/
void reverse(char *s)
{
    char *start = s;
    char *end = s + strlen(s) - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

/********************************************************************************************/
/* FUNCTION NAME : my_itoa																	                                */
/*																							                                            */																							     
/* INPUTS 	   :  	1.  n   -- number to convert into character string 						          */
/*					        2. *s  -- pointer to the char string to store the converted number		  */
/*        																					                                        */
/* RETURN 	   : nothing																                                   	*/
/*            																				                                      */
/* NOTES 	     : converts a number to a character string  				    				              */
/********************************************************************************************/
void my_itoa(int n, char *s)
{
    int sign = 1;

    if (n < 0) {
        sign = -1;
        n = -n;
    }

    char *ptr = s;

    do {
        *ptr++ = n % 10 + '0';
        n /= 10;
    } while (n > 0);

    if (sign == -1) {
        *ptr++ = '-';
    }

    *ptr = '\0';

    reverse(s);
}

/********************************************************************************************/
/* FUNCTION NAME : my_strindex																                              */
/*																							                                            */																							     
/* INPUTS 	   :  1. *s -- pointer to the source string to be match from					          */
/*       		      2. *t -- pointer to the string that to be matched from the source string	*/
/*        									                 		                        										*/
/* RETURN 	   : integer																	                                  */
/*            																				                                      */
/* NOTES 	   : find the position of t in s		       				    				                    */
/********************************************************************************************/
int my_strindex(char *s, char *t)
{
    char *s_ptr, *t_ptr, *start;
    
    for (s_ptr = s; *s_ptr != '\0'; s_ptr++) {
        start = s_ptr;
        t_ptr = t;

        while (*t_ptr != '\0' && *s_ptr == *t_ptr) {
            s_ptr++;
            t_ptr++;
        }

        if (*t_ptr == '\0')
            return start - s;
        
        s_ptr = start;
    }

    return -1;
}

/********************************************************************************************************/
/* FUNCTION NAME : my_getop																				*/
/*																								     	*/																							     
/* INPUTS 	   :  1. *s[] -- pointer to the source string						     					*/	     			    
/*        																						     	*/
/* RETURN 	   : integer																	     		*/
/*            																					     	*/
/* NOTES 	   : get operator or numeric operand														*/
/********************************************************************************************************/
int my_getop(char *s) {
    int i, c;

    while ((*s = c = getchar()) == ' ' || c == '\t')
        ;

    *(s + 1) = '\0';

    if (!isdigit(c) && c != '.')
        return c; /* not a number */

    if (isdigit(c)) {
        while (isdigit(*(++s) = c = getchar()))
            ;
    }

    if (c == '.') {
        while (isdigit(*(++s) = c = getchar()))
            ;
    }

    *s = '\0';

    if (c != EOF)
        ungetc(c, stdin);

    return NUMBER;
}

/*****************************************************************************************************/
/* FUNCTION NAME : main																			     */
/*																								     */																							     
/* INPUTS 	   :  no parameters																	     */
/*        																						     */
/* RETURN 	   : = 0	-- Success																     */
/*		  	   : < 0	-- Failed																     */
/*            																					     */
/* NOTES 	   :  invoking all other functions with necessary parameters						 	 */
/*****************************************************************************************************/
int main() {
    char line[100];
    int length;

    printf("Enter a line of text: ");
    length = my_getline(line, sizeof(line));
	printf("The function 'getline' Invoked!\n");
    printf("Line: %s", line);
    printf("Length: %d\n\n", length);
    
    const char *str = "   -12345";
    printf("Input for 'atoi' function: %s\n", str);
    int result = my_atoi(str);
    printf("The function 'atoi' Invoked!\n");
    printf("Result: %d\n\n", result);
    
    int num = -12345;
    char str1[20];
    printf("Input for 'itoa' function: %d\n", num);
    my_itoa(num, str1);
	printf("The function 'itoa' Invoked!\n");
    printf("Result: %s\n\n", str1);
    
    char s[] = "Hello, world!";
    char t[] = "world";
    printf("Source string: %s\n", s);
    printf("Substring: %s\n", t);
    printf("The function 'strindex' Invoked!\n");
	int index = my_strindex(s, t);
    if (index != -1) {
        printf("Substring found at index: %d\n", index);
    } 
	else {
        printf("Substring not found\n");
    }
    
    char input[100];
	printf("The function 'getop' Invoked!\n");
    printf("Enter an expression: ");
    while (my_getop(input) != EOF) {
        printf("Operand or operator: ");
		printf("%s", input);
        printf("\n");
    }
	return 0;
}

