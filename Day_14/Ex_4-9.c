#include <stdio.h>
#define BUFSIZE 100

int buf[BUFSIZE];  // Buffer to hold characters
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

int main() {
    int c;

    // Test case 1: Pushing back 'A' and 'B'
    ungetch('A');
    ungetch('B');

    // Reading characters
    while ((c = getch()) != EOF) {
        printf("%c", c);
    }
    putchar('\n');

    // Test case 2: Pushing back EOF
    ungetch(EOF);
	printf("%d", c);
    // Reading characters
    while ((c = getch()) != EOF) {
        printf("%c", c);
    }
    putchar('\n');

    return 0;
}

