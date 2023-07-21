#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define MAXOP 100
#define MAXVAL 100
#define BUFFSIZE 100
#define NUMBER '0'

int sp = 0;
double val[MAXVAL];

int bufp = 0;
char buf[BUFFSIZE];
int getop(char[]);
void push(double);
double pop(void);
double printTop(void);
void duplicate(void);
void swapTop(void);
void clearStack(void);

double variables[26]; // Array to store variables (a-z)
double lastPrintedValue = 0.0;
int var = 0;

/****************************************************************************************************************/
/* FUNCTION NAME : main																			     			                                          */
/*																								     			                                                    */																							     
/* INPUTS 	   :  none															    			    			                                        */
/*        																						     			                                                */
/* RETURN 	   : = 0	-- Success																     			                                      */
/*		  	     : < 0	-- Failed				                            												     			            */
/*            																					     			                                              */
/* NOTES 	   :  driver function to invoke all other function to upgrade the reverse Polish calculator			      */
/****************************************************************************************************************/
int main(void)
{
  int type;
  double op1, op2;
  char s[MAXOP];

  printf("Reverse Polish Notation (RPN) Calculator\n");
  printf("Enter numbers and operators (+, -, *, /, %, ~, !, $, &, =).\n");
  printf("Type 'q' to quit.\n");
  printf("Commands:\n");
  printf("   + : Addition\n");
  printf("   - : Subtraction\n");
  printf("   * : Multiplication\n");
  printf("   / : Division\n");
  printf("   % : Modulo\n");
  printf("   ~ : Print top of stack\n");
  printf("   ! : Duplicate top of stack\n");
  printf("   $ : Swap top two elements of stack\n");
  printf("   & : Clear the stack\n");
  printf("   = : Variable assignment\n");

  while ((type = getop(s)) != 'q')
  {
    switch (type)
    {
    case NUMBER:
      push(atof(s));
      break;

    case '+':
      op1 = pop();
      op2 = pop();
      push(op1 + op2);
      printf("Result of %g + %g is: ", op1, op2);
	  printTop();
      break;

    case '-':
      op1 = pop();
      op2 = pop();
      push(op2 - op1);
      printf("Result of %g - %g is: ", op2, op1);
	  printTop();
      break;

    case '*':
      op1 = pop();
      op2 = pop();
      push(op2 * op1);      
      printf("Result of %g * %g is: ", op1, op2);
	  printTop();
      break;

    case '/':
      op1 = pop();
      op2 = pop();

      if (op1 != 0.0)
      {
        push(op2 / op1);
        printf("Result of %g / %g is: ", op2, op1);
	    printTop();
      }
      else
      {
        printf("Error: zero divisor.\n");
      }
	  break;

    case '%':
      op1 = pop();
      op2 = pop();

      if (op1 != 0.0)
      {
        int modded = (int)op2 % (int)op1;
		push(modded);
        printf("Result: ", modded);
	    printTop();
      }
      else
      {
        printf("Error: zero divisor.\n");
      }
	  break;

    case '~':
      printf("Top of stack is: ");
      printTop();
      break;

    case '!':
      duplicate();
      printf("Top 2 element duplicated!");
      break;

    case '$':
      swapTop();
      printf("Top 2 element swaped!");
      break;

    case '&':
      clearStack();
      printf("Stack Cleared!\n");
      printTop();
      break;

    case '?':
      push(sin(pop()));
      printf("Result: ");
	  printTop();
      break;

    case ';':
      push(exp(pop()));
      printf("Result: ");
	  printTop();
      break;

    case '^':
      op2 = pop();
      push(pow(pop(), op2));
      printf("Result: ");
	  printTop();
      break;

    case '=': // Variable assignment
      variables[var - 'a'] = pop();
      push(variables[var - 'a']);
      printf("var %c : %g\n",var, variables[var-'a']);
      break;

    case '\n':
      break;

    default:
      if (isalpha(type))
      {
        var = type;
        push(variables[var - 'a']);        
      }
      else
      {
        printf("error: unknown command %s\n", s);
      }
      break;
    }
  }

  printf("Exiting the Stack Calculator.\n");

  return 0;
}

void push(double f)
{
  if (sp < MAXVAL)
  {
    val[sp++] = f;
  }
  else
  {
    printf("Error: stack full, can't push %g.\n", f);
  }
  return;
}

double pop(void)
{
  if (sp > 0)
  {
    return val[--sp];
  }
  else
  {
    printf("Error: stack empty.\n");
    return 0.0;
  }
}

double printTop(void)
{
  if (sp > 0)
  { 	
    printf("%.8g\n", val[sp - 1]);
    return val[sp - 1];
  }
  else
  {
    printf("Stack is empty.\n");
    return -1;
  }
}

void duplicate(void)
{
  if (sp > 0 && sp < MAXVAL)
  {
    val[sp] = val[sp - 1];
    sp++;
  }
  else if (sp >= MAXVAL)
  {
    printf("Error: stack full, can't duplicate.\n");
  }
  else
  {
    printf("Error: stack empty, can't duplicate.\n");
  }
  return;
}

void swapTop(void)
{
  if (sp > 1)
  {
    double temp = val[sp - 1];
    val[sp - 1] = val[sp - 2];
    val[sp - 2] = temp;
  }
  else if (sp == 1)
  {
    printf("Error: only one element in the stack, can't swap.\n");
  }
  else
  {
    printf("Error: stack empty, can't swap.\n");
  }
  return;
}

void clearStack(void)
{
  sp = 0;
  printf("Stack cleared.\n");
  return;
}


int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFFSIZE)
  {
    printf("ungetch: too many characters\n");
  }
  else
  {
    buf[bufp++] = c;
  }
  return;
}

/***********************************************************************************************/
/* FUNCTION NAME : getop															                                         */
/*																							                                               */																							     
/* INPUTS 	   :  s[] -- string to store the inputs									  		                     */	     			    
/*        																					                                           */
/* RETURN 	   : integer																	                                     */
/*            																				                                         */
/* NOTES 	   : get operators, numeric operands and variable name with values 				           */
/*				     handling negative input value                      				   								   */
/***********************************************************************************************/
int getop(char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;

  s[1] = '\0';

  if (!isdigit(c) && c != '.' && c != '-')
    return c;

  if (c == '-')
  {
    int next = getch();

    if (isdigit(next) || next == '.')
    {
      s[1] = next; // Store the '-' in the array
      i = 1;

      while (isdigit(s[++i] = c = getch()))
        ;

      if (c == '.')
      {
        while (isdigit(s[++i] = c = getch()))
          ;
      }

      s[i] = '\0';

      if (c != EOF)
        ungetch(c);

      return NUMBER;
    }
    else
    {
      if (next != EOF)
        ungetch(next); // Push back the non-digit character

      return c; // Return '-' as an operator
    }
  }

  i = 0;

  if (isdigit(c))
  {
    while (isdigit(s[++i] = c = getch()))
      ;

    if (c == '.')
    {
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

