#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*****************************************************************************/
/* FUNCTION NAME: main                                                       */
/*                                                                           */
/* INPUTS      : int argc - number of command-line arguments                 */
/*               char *argv[] - array of strings containing the arguments    */
/*                                                                           */
/* RETURN      : int - 0 if successful, 1 if error                           */
/*                                                                           */
/* NOTES       : Converts strings based on program name.                     */
/*               "lower" for lowercase conversion, "upper" for uppercase.    */
/*               Displays converted strings with spaces.                     */
/*****************************************************************************/

int main(int argc, char *argv[]) {
    // Check if at least one argument is provided (excluding program name)
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    int i;
    char* programName = argv[1];

    // Determine the desired conversion based on the program name
    int (*convertFunc)(int) = NULL;
    if (strcmp(programName, "lower") == 0) {
        convertFunc = tolower;
    } else if (strcmp(programName, "upper") == 0) {
        convertFunc = toupper;
    }

    // Convert the input string using the selected conversion function
    if (convertFunc != NULL) {
        for (i = 2; i < argc; i++) {
            int j;
            for (j = 0; argv[i][j] != '\0'; j++) {
                putchar(convertFunc(argv[i][j]));
            }
            putchar(' ');  // Add a space between words
        }
        putchar('\n');
    } else {
        printf("Invalid program name: %s\n", programName);
        return 1;
    }

    return 0;
}


