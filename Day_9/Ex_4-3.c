#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 /* maximum depth of val stack */
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);


int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}


/* pop: pop and return top value from stack */
double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getch(void);
void ungetch(int);

/********************************************************************************************************/
/* FUNCTION NAME : getop																				                                        */
/*																								     	                                                */																							     
/* INPUTS 	   :  1. s[] -- the source string									     					                            */	     			    
/*        																						     	                                            */
/* RETURN 	   : integer																	     		                                      */
/*            																					     	                                          */
/* NOTES 	   : get operator or numeric operand														                              */
/********************************************************************************************************/
int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t') 
        ;

    s[1] = '\0'; /*ensures that s initially holds the first non-whitespace character*/

    if (!isdigit(c) && c != '.' && c != '-') 
        return c;	/*This covers cases where the character represents an operator or an invalid input*/

    if (c == '-') {
        int next = getch(); /*get the next character*/

        if (isdigit(next) || next == '.') {  /*next char of after '-' is digit or '.' is checked*/
            s[1] = next;  	/*Store the numeric value in the array*/
            i = 1;

            while (isdigit(s[++i] = c = getch()))
                ;

            if (c == '.') {
                while (isdigit(s[++i] = c = getch()))
                    ;
            }

            s[i] = '\0';

            if (c != EOF)
                ungetch(c);

            return NUMBER;
        } else {
            if (next != EOF)
                ungetch(next);  /*Push back the non-digit character*/

            return c;  /*Return '-' as an operator*/
        }
    }

    i = 0;

    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()))
            ;

        if (c == '.') {
            while (isdigit(s[++i] = c = getch()))
                ;
        }

        s[i] = '\0';

        if (c != EOF)
            ungetch(c);

        return NUMBER;
    }

    return c;  /*Return the non-digit character as an operator*/
}

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) {   /* get a (possibly pushed-back) character */
	return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int c) { /* push character back on input */
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}


/*****************************************************************************************************/
/* FUNCTION NAME : main																			                                         */
/*																								                                                   */																							     
/* INPUTS 	   :  none															    			                                       */
/*        																						                                               */
/* RETURN 	   : = 0	-- Success																                                     */
/*		  	     : < 0	-- Failed																                                       */
/*            																					                                             */
/* NOTES 	   :  driver function to invoke all other function to build a reverse Polish calculator    */
/*****************************************************************************************************/
int main() {
	int type;
	double op2;
	char s[MAXOP];
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
			push(atof(s));
			break;
			
			case '+':
			push(pop() + pop());
			break;
			
			case '*':
			push(pop() * pop());
			break;
			
			case '-':
			op2 = pop();
			push(pop() - op2);
			break;
			
			case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
			
			case '%':
			op2 = pop();
			if (op2 != 0.0)
				push((int)pop() % (int)op2);
			else
				printf("error: zero divisor\n");
			break;
			
			case '\n':
				printf("\t%.8g\n", pop());
			break;
			
			default:
				printf("error: unknown command %s\n", s);
			break;
		}
	}
return 0;
}

