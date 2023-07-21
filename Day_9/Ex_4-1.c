#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; /* pattern to search for */

/********************************************************************************************************/
/* FUNCTION NAME : strindex																				                                      */
/*																								     	                                                */																							     
/* INPUTS 	   :  1. s[] -- the source string to be match from									     	                  */
/*       		      2. t[] -- the string that to be matched from the source s[]	     			    	          */
/*        																						     	                                            */
/* RETURN 	   : integer																		     	                                      */
/*            																					     	                                          */
/* NOTES 	   : find the position of the rightmost occurrence of t in s		       				                */
/********************************************************************************************************/
int strindex(char s[], char t[])
{
    int i, j, k;
    int rightmost = -1;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);

        if (k > 0 && t[k] == '\0')
            rightmost = i;
    }

    return rightmost;
}

/******************************************************************************************/
/* FUNCTION NAME : main																	                                  */
/*																						                                            */																							     
/* INPUTS 	   :  nothing														    	                                */
/*        																				                                        */
/* RETURN 	   : = 0	-- Success														                              */
/*		  	     : < 0	-- Failed													                                  */
/*            																		                                        */
/* NOTES 	   : print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300       	          */
/******************************************************************************************/
int main()
{
    char line[MAXLINE];
    int position;
	printf("The string to be matched is: '%s'\n", pattern);
    while (getline(line, MAXLINE) > 0)
    {
        position = strindex(line, pattern);

        if (position >= 0)
            printf("Rightmost occurrence found at position: %d\n", position);
        else
            printf("Pattern not found.\n");
    }

    return 0;
}

int getline(char s[], int lim)
{
    int c, i;
    i = 0;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

