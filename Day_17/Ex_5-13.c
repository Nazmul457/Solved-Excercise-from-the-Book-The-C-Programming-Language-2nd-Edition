#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define DEFAULT_LINES 10

void print_last_lines(FILE *file, int num_lines) {
    char **lines = (char **)malloc(num_lines * sizeof(char *));
    if (lines == NULL) {
        fprintf(stderr, "Error: Insufficient memory.\n");
        exit(1);
    }

    int line_count = 0;
    char line[MAX_LINE_LENGTH];

    // Store the last n lines in the circular buffer
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        lines[line_count % num_lines] = strdup(line);
        line_count++;
    }

    int start = line_count > num_lines ? line_count - num_lines : 0;
    int end = line_count;
	int i;
    for (i = start; i < end; i++) {
        printf("%s", lines[i % num_lines]);
        free(lines[i % num_lines]);
    }

    free(lines);
}

int main(int argc, char *argv[]) {
    int num_lines = DEFAULT_LINES;

    if (argc > 1) {
        num_lines = atoi(argv[1]);
        if (num_lines <= 0) {
            fprintf(stderr, "Error: Invalid number of lines.\n");
            return 1;
        }
    }

    print_last_lines(stdin, num_lines);

    return 0;
}

