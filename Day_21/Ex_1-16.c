#include <stdio.h>
#define MAXLINE 5 /* maximum input line length */
int getline(char line[], int maxline);
void copy(char to[], char from[]);

/*****************************************************************************************************/
/* FUNCTION NAME : main																			     																		 */
/*																								    																							 */																							     
/* INPUTS 	   	:  no  parameters 																																	 */
/*        																						    																					 */
/* RETURN 	    : = 0	-- Success																  																   */
/*		  	      : < 0	-- Failed															    																		 */
/*            																					    																				 */
/* NOTES 	      : print the longest input line											  															 */
/*****************************************************************************************************/
int main() {
int len; /* current line length */
int max; /* maximum length seen so far */
char line[MAXLINE]; /* current input line */
char longest[MAXLINE]; /* longest line saved here */
max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
	if (len > max) {
		max = len;
		copy(longest, line);
	}
	if (max > 0) /* there was a line */
		printf("%s", longest);
return 0;
}

/*****************************************************************************************************/
/* FUNCTION NAME : get_line																     	 																		 */
/*																								    																							 */																							     
/* INPUTS 	     :  1. s[] 	  -- store lines from input   								     											 */
/*				  				2. lim  	-- maximum length of line								 															 */
/*        																						    																					 */
/* RETURN 	     :  integer																		    																	 */
/* NOTES 	       :  read a line into s, return length							 	 																 */
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
	while(c != EOF && c != '\n') {
     ++i;
     c = getchar();
   	}  
return i;
}

/*****************************************************************************************************/
/* FUNCTION NAME : copy																	     	 																			 */
/*																								     																						 	 */																							     
/* INPUTS 	     :  1. to[] 	 -- character array to copy string from					     					    		 */
/*				  				2. from[]	 -- character array to copy string into						 										 */
/*        																						    																					 */
/* RETURN 	  	 :  integer																		     																	 */
/* NOTES 	  	 	 :  copy 'from' into 'to'; assume to is big enough							                     */
/*****************************************************************************************************/
void copy(char to[], char from[]) {
int i;
i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

