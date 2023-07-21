#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

/******************************************************************************/
/* FUNCTION NAME: compareFiles                                                */
/*                                                                            */
/* INPUTS      : FILE* file1 - pointer to the first input file                */
/*               FILE* file2 - pointer to the second input file               */
/*                                                                            */
/* RETURN      : int - line number of the first difference or -1 if identical */
/*                                                                            */
/* NOTES       : Compares two files line by line and detects differences.     */
/*               Displays differing lines and handles file length disparities.*/
/******************************************************************************/
int compareFiles(FILE* file1, FILE* file2);

/******************************************************************************/
/* FUNCTION NAME: main                                                        */
/*                                                                            */
/* INPUTS      : none                                                         */
/*                                                                            */
/* RETURN      : int - 0 if successful                                        */
/*                                                                            */
/* NOTES       : Compares two text files line by line and detects differences.*/
/*               Displays result and handles file opening errors.             */
/******************************************************************************/
int main() {
    FILE* file1;
    FILE* file2;

    file1 = fopen("file1.txt", "r");
    file2 = fopen("file2.txt", "r");

    if (file1 == NULL || file2 == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    int line = compareFiles(file1, file2);
    if (line == -1) {
        printf("Files are identical.\n");
    } else {
        printf("Files differ at line %d.\n", line);
    }

    fclose(file1);
    fclose(file2);

    return 0;
}


int compareFiles(FILE* file1, FILE* file2) {
    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];
    int line = 1;

    while (fgets(line1, MAX_LINE_LENGTH, file1) != NULL && fgets(line2, MAX_LINE_LENGTH, file2) != NULL) {
        if (strcmp(line1, line2) != 0) {
            printf("Files differ at line %d.\n", line);
            printf("File 1: %s", line1);
            printf("File 2: %s", line2);
            return line;
        }
        line++;
    }

    // If one file has more lines than the other
    if (fgets(line1, MAX_LINE_LENGTH, file1) != NULL) {
        printf("File 2 ended, but File 1 still has more lines.\n");
        printf("Remaining lines in File 1:\n");
        printf("%s", line1);
        return line;
    } else if (fgets(line2, MAX_LINE_LENGTH, file2) != NULL) {
        printf("File 1 ended, but File 2 still has more lines.\n");
        printf("Remaining lines in File 2:\n");
        printf("%s", line2);
        return line;
    }

    // If both files have the same content
    return -1;
}

