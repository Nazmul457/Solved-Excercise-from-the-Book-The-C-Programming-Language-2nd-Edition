#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define MAXVAL 100
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;
enum { NAME, PARENS, BRACKETS };

int getch(void);
void ungetch(int c);
void dcl(void);
void dirdcl(void);
int gettoken(void);

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

/*****************************************************************************/
/* FUNCTION NAME : main														                           */
/*																			  																	 */																							     
/* INPUTS 	     : none														 													 */
/*        																	                                 */
/* RETURN 	     : integer													                         */
/*            																                               */
/* NOTES 	    	 : functions to run other function with parameters			     */
/*****************************************************************************/
int main()
{
    while (gettoken() != EOF) {
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        if (tokentype != '\n'){        	
            printf("syntax error\n");
            continue;
		}
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

/*****************************************************************************/
/* FUNCTION NAME : dcl														                           */
/*																			                                     */																							     
/* INPUTS 	     : none														                           */
/*        																	                                 */
/* RETURN 	     : none														                           */
/*            																                               */
/* NOTES 	    : parses a C declaration based on a simplified grammar.		     */
/*****************************************************************************/
void dcl(void)
{
    int ns;
    for (ns = 0; gettoken() == '*'; ns++)
        ;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

void dirdcl(void)
{
    int type;
    if (tokentype == '(') {
        dcl();
        if (tokentype != ')') {
            printf("error: missing )\n");
			getch();
			return;        	
		}
    } else if (tokentype == NAME) {
        strcpy(name, token);
    } else {
        printf("error: expected name or (dcl)\n");
        getch();
		return;
    }
    while ((type = gettoken()) == PARENS || type == BRACKETS) {
        if (type == PARENS) {
            strcat(out, " function returning");
        } else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

int gettoken(void)
{
    int c, getch(void);
    void ungetch(int c);
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else {
        return tokentype = c;
    }
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
