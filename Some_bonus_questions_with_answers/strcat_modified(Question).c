#include <stdio.h>
#include <string.h>

void my_strcat(char *s, const char *t, size_t max_length) {
    if (s == NULL || t == NULL) {
        printf("Invalid input: NULL pointer.\n");
        return;
    }

    size_t s_length = strlen(s);
    size_t t_length = strlen(t);
    
    if(s_length <= max_length) {
    	printf("Error: Source string is full.\n");
    	return;
	}
    else if (s_length + t_length >= max_length) {
        printf("Error: Insufficient space to concatenate strings.\n");
        return;
    }

    while (*s != '\0') {
        s++;
    }

    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

int main() {
    // Test case 1: Valid input, sufficient space
    char s1[100] = "Hello, ";
    char t1[] = "world!";
    printf("Before concatenation: %s\n", s1);
    my_strcat(s1, t1, sizeof(s1));
    printf("After concatenation: %s\n\n", s1);

    // Test case 2: Insufficient space
    char s2[12] = "Hello, ";
    char t2[] = "world!";
    printf("Before concatenation: %s\n", s2);
    my_strcat(s2, t2, sizeof(s2));
    printf("After concatenation: %s\n\n", s2);

    // Test case 3: NULL pointer
    char s3[100] = "Hello, ";
    char *t3 = NULL;
    printf("Before concatenation: %s\n", s3);
    my_strcat(s3, t3, sizeof(s3));
    printf("After concatenation: %s\n\n", s3);
    
    // Test case 4: Insufficient space/Source string is already full
    char s4[8] = "Hello, ";
    char t4[] = "";
    printf("Before concatenation: %s\n", s4);
    my_strcat(s4, t4, sizeof(s4));
    printf("After concatenation: %s\n\n", s4);

    return 0;
}

