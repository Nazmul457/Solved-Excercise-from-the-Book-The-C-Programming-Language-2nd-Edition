#include <stdio.h>

void squeezeString(char s1[], const char s2[]) {
    int i, j, k;
    int shouldDelete;
    
    for (i = j = 0; s1[i] != '\0'; i++) {
        shouldDelete = 0;
        
        for (k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k]) {
                shouldDelete = 1;
                break;
            }
        }
        
        if (!shouldDelete)
            s1[j++] = s1[i];
    }
    
    s1[j] = '\0';
}

int main() {
    char s1[100];
    char s2[100];

    printf("Enter the first string (s1): ");
    scanf("%s", s1);

    printf("Enter the second string (s2): ");
    scanf("%s", s2);

    squeezeString(s1, s2);

    printf("Modified string (s1): %s\n", s1);

    return 0;
}
