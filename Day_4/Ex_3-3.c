#include <stdio.h>
#define MAX_LENGTH 100
void expand(const char s1[], char s2[]) {
    int i, j, k;
    i = j = 0;

    // Check if the first character is a hyphen
    if (s1[i] == '-')
        s2[j++] = '-';

    while (s1[i] != '\0') {
        // Check for shorthand notation pattern
        if (s1[i] == '-' && s1[i + 1] != '\0' && s1[i + 1] != '-') {
            char start = s1[i - 1];
            char end = s1[i + 1];

            // Check if the start and end characters are valid
            if ((start >= 'a' && start <= 'z' && end >= 'a' && end <= 'z') ||
                (start >= 'A' && start <= 'Z' && end >= 'A' && end <= 'Z') ||
                (start >= '0' && start <= '9' && end >= '0' && end <= '9')) {
                // Expand the shorthand notation
                for (k = start + 1; k < end; k++)
                    s2[j++] = k;
            }
        } else {
            s2[j++] = s1[i];
        }
        i++;
    }

    s2[j] = '\0';  // Null-terminate the destination string
}

int main() {
    char source[MAX_LENGTH];
    char expanded[MAX_LENGTH];
    fgets(source, sizeof(source), stdin);
    expand(source, expanded);
    printf("Original: %s\n", source);
    printf("Expanded: %s\n", expanded);

    return 0;
}

