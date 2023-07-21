#include <stdio.h>

#define TAB_WIDTH 4  // Set the tab stop value as a symbolic parameter

/*****************************************************************************/
/* FUNCTION NAME : main                                                      */
/* INPUTS       : void                                                       */
/* RETURN       : int                                                        */
/* NOTES        : Reads input characters and replaces tabs with asterisks, 	 */
/*				  maintaining tab stop positions 																	 */
/*****************************************************************************/
int main(void) {
    int c;
    int position = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spaces = TAB_WIDTH - (position % TAB_WIDTH);
            int i;
            for (i = 0; i < spaces; i++) {
                putchar('*'); /*Determines that the tabs are replaced by tabs*/
                position++;
            }
        } else if (c == '\n') {
            putchar(c);
            position = 0;
        } else {
            putchar(c);
            position++;
        }
    }
    return 0;
}

