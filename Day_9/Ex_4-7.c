#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE];  // Buffer to hold characters
int bufp = 0;       // Next free position in buffer

int getch(void);
void ungetch(int c);
void ungets(char s[]);

/****************************************************************************************************************/
/* FUNCTION NAME : main																			     			                                          */
/*																								     			                                                    */																							     
/* INPUTS 	   :  none															    			    			                                        */
/*        																						     			                                                */
/* RETURN 	   : = 0	-- Success	                                       															     			*/
/*		  	     : < 0	-- Failed																     		                                        	*/
/*            																					     	                                               		*/
/* NOTES 	   :  driver function to invoke all other function to implement a routine ungets(s) that will 	    	*/
/*				      push back an entire string onto the input												                                */
/****************************************************************************************************************/
int main(void) {
    char a[] = "Hello, world!";  
    ungets(a); // Push the string "Hello, world!" back onto the input
	printf("%s", buf);
    return 0;
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
    return;
}

/*********************************************************************************************/
/* FUNCTION NAME : ungets																	 */
/*																							 */																							     
/* INPUTS 	   :  s[] -- string to push back									    		 */
/*        																					 */
/* RETURN 	   : nothing																	 */
/*            																				 */
/* NOTES 	   : routine ungets(s) that will push back an entire string onto the input.		 */
/*********************************************************************************************/
void ungets(char s[]) {
    int i = strlen(s)-1;

    while (i >=0) {
        ungetch(s[i]);
        --i;
    }
    return;
}
