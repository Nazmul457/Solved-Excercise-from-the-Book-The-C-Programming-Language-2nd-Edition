#include <stdio.h>

int any(const char s1[], const char s2[]) {
    int i, j;
    
    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j])
                return i;
        }
    }
    
    return -1;
}

int main() {
    char s1[100];
    char s2[100];

    printf("Enter the first string (s1): ");
    scanf("%s", s1);

    printf("Enter the second string (s2): ");
    scanf("%s", s2);

    int result = any(s1, s2);

    if (result == -1) {
        printf("No characters from s2 found in s1\n");
    } else {
        printf("First occurrence of a character from s2 in s1 is at index: %d\n", result);
    }

    return 0;
}

