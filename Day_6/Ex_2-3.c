#include <stdio.h>
#include <ctype.h>

int htoi(const char *s) {
    int result = 0;
    int i = 0;
    
    // Skip optional 0x or 0X prefix
    if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X'))
        i += 2;
    
    // Iterate through each character of the string
    while (s[i] != '\0') {
        char c = tolower(s[i]);
        int digit;
        
        // Convert hexadecimal digit to decimal value
        if (isdigit(c))
            digit = c - '0';
        else if (c >= 'a' && c <= 'f')
            digit = c - 'a' + 10;
        else {
            // Invalid character encountered
            printf("Invalid hexadecimal digit '%c'\n", s[i]);
            return -1;
        }
        
        // Accumulate the result
        result = result * 16 + digit;
        i++;
    }
    
    return result;
}

int main() {
    char hex[20];
    
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    
    int decimal = htoi(hex);
    printf("Decimal equivalent: %d\n", decimal);
    
    return 0;
}
