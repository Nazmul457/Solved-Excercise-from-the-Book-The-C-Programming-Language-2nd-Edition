#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define MAXVAL 100
#define BUFFSIZE 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);
double printTop(void);
void duplicate(void);
void swapTop(void);
void clearStack(void);

/********************************************************************************************************/
/* FUNCTION NAME : main																			     	                                      */
/*																								     	                                                */																							     
/* INPUTS 	   :  none															    			    	                                    */
/*        																						     	                                            */
/* RETURN 	   : = 0	-- Success																     	                                  */
/*		  	     : < 0	-- Failed																     	                                    */
/*            																					     	                                          */
/* NOTES 	   :  driver function to invoke all other function to upgrade the reverse Polish calculator   */
/********************************************************************************************************/
int main(void) {
  int type;
  double op2;
  char s[MAXOP];

  printf("Reverse Polish calculator\n");
  printf("Enter numbers and operators (+, -, *, /, %%, p, d, s, c).\n");
  printf("Type 'p' to print the top\n");
  printf("Type 'd' to duplicate the top\n");
  printf("Type 's' to swap the top two elements\n");
  printf("Type 'c' to clear the stack.\n");
  
  printf("Type 'q' to quit.\n");

  while ((type = getop(s)) != 'q') {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;

    case '+':
      push(pop() + pop());
      break;

    case '-':
      op2 = pop();
      push(pop() - op2);
      break;

    case '*':
      push(pop() * pop());
      break;

    case '/':
      op2 = pop();

      if (op2 != 0.0) {
        push(pop() / op2);
      }
      else {
        printf("Error: zero divisor.\n");
      }

      break;

    case '%':
      op2 = pop();

      if (op2 != 0.0) {
        push((int)pop() % (int)op2);
      }
      else {
        printf("Error: zero divisor.\n");
      }
      break;

    case 'p':
      printTop();
      break;

    case 'd':
      duplicate();
      break;

    case 's':
      swapTop();
      break;

    case 'c':
      clearStack();
      break;

    case '\n':
      printf("result: %.8g\n", printTop());
      break;

    default:
      printf("Error: unknown command %s.\n", s);
      break;
    }
  }

  printf("Exiting the Calculator.\n");

  return 0;
}

int sp = 0;
double val[MAXVAL];

void push(double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
  }
  else {
    printf("Error: stack full, can't push %g.\n", f);
  }
}

double pop(void) {
  if (sp > 0) {
    return val[--sp];
  }
  else {
    printf("Error: stack empty.\n");
    return 0.0;
  }
}

double printTop(void) {
  if (sp > 0) {
    return val[sp - 1];
  }
  else {
    return -1;
  }
}

void duplicate(void) {
  if (sp > 0 && sp < MAXVAL) {
    val[sp] = val[sp - 1];
    sp++;
  }
  else if (sp >= MAXVAL) {
    printf("Error: stack full, can't duplicate.\n");
  }
  else {
    printf("Error: stack empty, can't duplicate.\n");
  }
}

void swapTop(void) {
  if (sp > 1) {
    double temp = val[sp - 1];
    val[sp - 1] = val[sp - 2];
    val[sp - 2] = temp;
  }
  else if (sp == 1) {
    printf("Error: only one element in the stack, can't swap.\n");
  }
  else {
    printf("Error: stack empty, can't swap.\n");
  }
}

void clearStack(void) {
  sp = 0;
  printf("Stack cleared.\n");
}

int bufp = 0;
char buf[BUFFSIZE];

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp >= BUFFSIZE) {
    printf("ungetch: too many characters\n");
  }
  else {
    buf[bufp++] = c;
  }
}

/********************************************************************************************************/
/* FUNCTION NAME : getop																				                                        */
/*									                                                															     	*/																							     
/* INPUTS 	   :  1. s[] -- the source string									     	                            				*/	     			    
/*        														                                            								     	*/
/* RETURN 	   : integer																	     		                                      */
/*            																					                                               	*/
/* NOTES 	   : get operator or numeric operand handling negative input value						               	*/
/********************************************************************************************************/
int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;

  s[1] = '\0';

  if (!isdigit(c) && c != '.' && c != '-')
    return c;

  if (c == '-') {
    int next = getch();

    if (isdigit(next) || next == '.') {
      s[1] = next; // Store the '-' in the array
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
	}
    else {
      if (next != EOF)
        ungetch(next); // Push back the non-digit character

      return c; // Return '-' as an operator
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

  return c; // Return the non-digit character as an operator
}
