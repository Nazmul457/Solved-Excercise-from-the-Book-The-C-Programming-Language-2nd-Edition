#include <stdio.h>
#include <string.h>

#define MAXLINE 10000

#define TRUE (1 == 1)
#define FALSE !TRUE

int get_line(char line[], int max_line_len);
void fold_line(char line[], char fold_str[], int n_break);
int find_longest_word(char line[]);

/*****************************************************************************/
/* FUNCTION NAME : main                                                      */
/*                                                                           */
/* INPUTS       : void                                                       */
/*                                                                           */
/* RETURN       : int                                                        */
/*                                                                           */
/* NOTES        : Reads input lines and folds them by inserting newline      */
/*                characters at appropriate positions to fit within the      */
/*                specified fold width.                                      */
/*****************************************************************************/
int main(void)
{
    char line[MAXLINE];
    char fold_str[MAXLINE];
    while (get_line(line, MAXLINE) > 0)
    {
        int breaking_point = find_longest_word(line);
        fold_line(line, fold_str, breaking_point);
        printf("%s", fold_str);
    }

    return 0;
}

/*****************************************************************************/
/* FUNCTION NAME : get_line                                                  */
/*                                                                           */
/* INPUTS       : char line[] - Array to store the input line                */
/*               int max_line_len - Maximum length of the input line         */
/*                                                                           */
/* RETURN       : int                                                        */
/*                                                                           */
/* NOTES        : Reads characters from input and stores them in line array. */
/*                Stops reading at EOF or newline, and adds null character   */
/*                at the end. Returns the length of the line (excluding      */
/*                null character).                                           */
/*****************************************************************************/
int get_line(char line[], int max_line_len)
{
    int c, i = 0;

    while (i < max_line_len - 1 && (c = getchar()) != EOF && c != '\n')
    {
        line[i++] = c;
    }

    if (c == '\n')
    {
        line[i++] = c;
    }

    line[i] = '\0';

    return i;
}

/*****************************************************************************/
/* FUNCTION NAME : fold_line                                                 */
/*                                                                           */
/* INPUTS       : char line[] - Input line to be folded                      */
/*               char fold_str[] - Output folded line                        */
/*               int n_break - Number of characters before line folding      */
/*                                                                           */
/* RETURN       : void                                                       */
/*                                                                           */
/* NOTES        :Folds the input line by inserting newlines at appropriate	 */ 
/*				positions to fit within the specified breaking point         */                
/*****************************************************************************/
void fold_line(char line[], char fold_str[], int n_break)
{
    int i, j;
    int column = 0;
    int last_blank = -1;

    for (i = 0, j = 0; line[i] != '\0'; ++i, ++j)
    {
        fold_str[j] = line[i];

        if (fold_str[j] == '\n')
        {
            column = 0;
            last_blank = -1;
        }

        column++;

        if (fold_str[j] == ' ' || fold_str[j] == '\t')
            last_blank = j;

        if (column == n_break)
        {
            if (last_blank != -1)
            {
                fold_str[last_blank] = '\n';
                column = j - last_blank;
                last_blank = -1;
            }
            else
            {
                fold_str[++j] = '-';
                fold_str[j] = '\n';

                column = 0;
            }
        }
    }

    fold_str[j] = '\0';
}

/*****************************************************************************/
/* FUNCTION NAME : find_longest_word                                         */
/*                                                                           */
/* INPUTS       : char line[] - Input line to find the longest word          */
/*                                                                           */
/* RETURN       : int                                                        */
/*                                                                           */
/* NOTES        : Finds the length of the longest word in the input line.    */
/*                Considers whitespace characters (' ', '\t', '\n') as       */
/*                word delimiters. Returns the length of the longest word.   */
/*****************************************************************************/
int find_longest_word(char line[])
{
    int longest_word_length = 0;
    int current_word_length = 0;
    int i;

    for (i = 0; line[i] != '\0'; i++)
    {
        if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
        {
            if (current_word_length > longest_word_length)
            {
                longest_word_length = current_word_length;
            }
            current_word_length = 0;
        }
        else
        {
            current_word_length++;
        }
    }

    if (current_word_length > longest_word_length)
    {
        longest_word_length = current_word_length;
    }

    return longest_word_length;
}
