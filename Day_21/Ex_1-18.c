#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 /* maximum input line length */
int getline(char line[], int maxline);
void copy(char to[], char from[]);

/*****************************************************************************************************/
/* FUNCTION NAME : main																			     												*/
/*																								     */																							     
/* INPUTS 	   :  no  parameters 																	 */
/*        																						     */
/* RETURN 	   : = 0	-- Success																     */
/*		  	   : < 0	-- Failed																     */
/*            																					     */
/* NOTES 	   : print the longest input line													  	 */
/*****************************************************************************************************/
int main() {
int len; /* current line length */
char line[MAXLINE]; /* current input line */
char longest[MAXLINE]; /* longest line saved here */
while ((len = getline(line, MAXLINE)) > 0) {
 		int n;
        n = strlen(line);
        printf("Length before omitting spaces is : %d\n", n-1);
        for (n = strlen(line)-1; n >= 0; n--)
			if (line[n] != ' ' && line[n] != '\t' && line[n] != '\n')
			break;
		line[n+1] = '\0';
        if (line[0] == '\n')
        ;
 		n = strlen(line);
        printf("Length after omitting spaces is : %d\n", n);
    }
    return 0;
}

/*****************************************************************************************************/
/* FUNCTION NAME : get_line																     	 	 */
/*																								     */																							     
/* INPUTS 	   :  1. s[] 	   	  -- store lines from input									     	 */
/*				  2. lim  		  -- maximum length of line										 	 */
/*        																						     */
/* RETURN 	   :  integer																		     */
/* NOTES 	   :  read a line into s, return length							 	 					 */
/*****************************************************************************************************/
int getline(char s[],int lim) {
	int c, i;
	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
return i;
}

/*****************************************************************************************************/
/* FUNCTION NAME : fields_compare														     	 	 */
/*																								     */																							     
/* INPUTS 	   :  1. *s1   	  -- pointer to 1st character of string 1							     */
/*				  2. *s2   	  -- pointer to 2nd character of string 2								 */
/*        																						     */
/* RETURN 	   :  integer																		     */
/* NOTES 	   :  Compares two strings based on specified fields and options.		 	 			 */
/*****************************************************************************************************/
void copy(char to[], char from[]) {
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

