#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS 32

struct key {
    char *word;
    int count;
};

struct key keytab[NKEYS] = {
    { "auto", 0 },
    { "break", 0 },
    { "case", 0 },
    { "char", 0 },
    { "const", 0 },
    { "continue", 0 },
    { "default", 0 },
    { "do", 0 },
    { "double", 0 },
    { "else", 0 },
    { "enum", 0 },
    { "extern", 0 },
    { "float", 0 },
    { "for", 0 },
    { "goto", 0 },
    { "if", 0 },
    { "int", 0 },
    { "long", 0 },
    { "register", 0 },
    { "return", 0 },
    { "short", 0 },
    { "signed", 0 },
    { "sizeof", 0 },
    { "static", 0 },
    { "struct", 0 },
    { "switch", 0 },
    { "typedef", 0 },
    { "union", 0 },
    { "unsigned", 0 },
    { "void", 0 },
    { "volatile", 0 },
    { "while", 0 }
};

int get_word(char *ptr, char *word, int lim);
int binsearch(char *, struct key *, int);

/*****************************************************************************/
/* FUNCTION NAME : main                                                      */
/*                                                                           */
/* INPUTS       : void                                                       */
/* RETURN       : int                                                        */
/*                                                                           */
/* NOTES        : Reads input text and counts the occurrences of keywords.   */
/*                Ignores comments and string literals.                      */
/*****************************************************************************/
int main() {
    char line[MAXWORD];
    char word[MAXWORD];
    int in_comment = 0;
    int skip_line = 0;
    int under_char = 0;
    int in_string_literal = 0;

    printf("Enter text (press Ctrl + z to finish):\n");

    while (fgets(line, sizeof(line), stdin) != NULL) {
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0'; // Remove the newline character
        }

        char *ptr = line;

        while (*ptr != '\0') {
            if (!in_comment && !in_string_literal) {
                if (*ptr == '#') {
                    // Handle preprocessing directives
                    // Skip counting
                    break;
                }

                if (*ptr == '/' && *(ptr + 1) == '*') {
                    // Start of a multi-line comment
                    in_comment = 1;
                    ptr += 2;
                    continue;
                }
                
                if (*ptr == '/' && *(ptr + 1) == '/') {
				    // Start of a single-line comment
				    skip_line = 1;
				    break; // Skip the entire line and move to the next iteration
				}

                if (*ptr == '"') {
                    // Start of a string literal
                    in_string_literal = 1;
                    ptr++;
                    continue;
                }
                
                if(*ptr =='_'){
                	//Start of a underscore
                	under_char = 1;
					ptr++;
                	continue;
				}

                int word_len = get_word(ptr, word, MAXWORD);

                // Convert word to lowercase for case-insensitive comparison
                int i;
				for (i = 0; i < word_len; i++) {
                    word[i] = tolower(word[i]);
                }

                int index = binsearch(word, keytab, NKEYS);
                if (index != -1) {
                    keytab[index].count++;
                }

                ptr += word_len;
            }

            if (in_comment) {
                if (*ptr == '*' && *(ptr + 1) == '/') {
                    // End of a comment
                    in_comment = 0;
                    ptr += 2;
                    continue;
                }
            }
            
            if(under_char){
            	//skip the word starts with underscore
            	while(*ptr++ != '\0');
            	under_char = 0;
            	continue;
			}
			
            if(skip_line){
            	//skip the single-line comment
            	while(*ptr++ != '\n');
				skip_line = 0;
            	continue;
			}
			
            if (in_string_literal) {
                if (*ptr == '"') {
                    // End of a string literal
                    in_string_literal = 0;
                    ptr++;
                    continue;
                }
            }
            ptr++;
        }
    }

    printf("\nKeyword counts:\n");
    int j;
    for (j = 0; j < NKEYS; j++) {
        if (keytab[j].count > 0) {
            printf("%4d %s\n", keytab[j].count, keytab[j].word);
        }
    }

    return 0;
}

int binsearch(char *word, struct key tab[], int n) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(word, tab[mid].word);

        if (cmp < 0) {
            high = mid - 1;
        } else if (cmp > 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int get_word(char *ptr, char *word, int lim) {
    int c;
    int word_len = 0;

    while (*ptr != '\0' && isspace(*ptr)) {
        ptr++;
    }

    while (*ptr != '\0' && !isspace(*ptr) && word_len < lim - 1) {
        word[word_len++] = *ptr++;
    }

    word[word_len] = '\0';
    return word_len;
}
