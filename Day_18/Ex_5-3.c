#include <stdio.h>

/*****************************************************************************/
/* FUNCTION NAME : my_strcat												                         */
/*																			                                     */																							     
/* INPUTS 	   :  1. *s -- pointer to the string to concat with				       */
/*       		      2. *t -- pointer to the string to append		               */
/*        																	                                 */
/* RETURN 	   : nothing													                           */
/*            																                               */
/* NOTES 	   : concat s with t											                         */
/*****************************************************************************/
void my_strcat(char *s, const char *t) {
	while (*s != '\0') {
		s++;
	}
	
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}

int main() {
    char s[100] = "Hello, ";
    char t[] = "world!";
    
    printf("Before concatenation: %s\n", s);
    my_strcat(s, t);
    printf("After concatenation: %s\n", s);
    
    return 0;
}
