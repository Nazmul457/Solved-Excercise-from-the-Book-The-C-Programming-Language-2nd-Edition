#include <stdio.h>
#include <stdbool.h>

/*****************************************************************************/
/* FUNCTION NAME : isupper_space                                             */
/*                                                                           */
/* INPUTS       : char c - the character to be checked                       */
/*                                                                           */
/* RETURN       : bool - true if the character is uppercase, false otherwise */
/*                                                                           */
/* NOTES        : Checks if the given character is uppercase based on ASCII  */
/*                values. Returns true if the character falls within the     */
/*                range of uppercase letters (A-Z), and false otherwise.     */
/*****************************************************************************/
bool isupper_space(char c) {
    // Check if the given character is uppercase using ASCII values
    return c >= 'A' && c <= 'Z';
}

/*****************************************************************************/
/* FUNCTION NAME : isupper_time                                              */
/*                                                                           */
/* INPUTS       : char c - the character to be checked                       */
/*                                                                           */
/* RETURN       : bool - true if the character is uppercase, false otherwise */
/*                                                                           */
/* NOTES        : Checks if the given character is uppercase using a lookup  */
/*                table approach. Returns true if the character is an        */
/*                uppercase letter (A-Z), and false otherwise.               */
/*****************************************************************************/

bool isupper_time(char c) {
    // Lookup table to store the uppercase property of characters
    static const bool uppercaseTable[256] = {
        /* 0-255: false */
        /* ... */
        /* 'A'-'A' to 'Z'-'A': true */
        ['A'] = true,  // A
        ['B'] = true,  // B
        ['C'] = true,  // C
        // ... and so on for all uppercase characters
    };

    // Check if the given character is uppercase
    return uppercaseTable[(unsigned char)c];
}

/*****************************************************************************/
/* FUNCTION NAME : main                                                      */
/*                                                                           */
/* INPUTS       : none                                                       */
/*                                                                           */
/* RETURN       : int - 0 if successful                                      */
/*                                                                           */
/* NOTES        : Takes a character as input and checks if it is uppercase.  */
/*                Utilizes both isupper_space and isupper_time functions to  */
/*                perform the checks and displays the result.                */
/*****************************************************************************/

int main() {
    char c;

    printf("Enter a character: ");
    scanf("%c", &c);

    printf("Using isupper_space: ");
    if (isupper_space(c)) {
        printf("Character is uppercase.\n");
    } else {
        printf("Character is not uppercase.\n");
    }

    printf("Using isupper_time: ");
    if (isupper_time(c)) {
        printf("Character is uppercase.\n");
    } else {
        printf("Character is not uppercase.\n");
    }
    return 0;
}

