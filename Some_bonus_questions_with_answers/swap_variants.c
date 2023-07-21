#include <stdio.h>

//swap using a macro
#define SWAP(a, b) { (a) ^= (b); (b) ^= (a); (a) ^= (b); }

//swap using a temporary variable
void swap_by_temp(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
//swap using xor operator
void swap_by_xor_op(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
    return;
}

//swap using arithmatic operator
void swap_arithmatic(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    int x = 5;
    int y = 10;

    printf("Before swap: x = %d, y = %d\n", x, y);
    swap_by_temp(&x, &y);
    printf("After swap using a temporary variable: x = %d, y = %d\n\n", x, y);

	printf("Before swap: x = %d, y = %d\n", x, y);
    swap_by_xor_op(&x, &y);
    printf("After swap using bitwise XOR operator: x = %d, y = %d\n\n", x, y);
    
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap_arithmatic(&x, &y);
    printf("After swap using arithmetic operations: x = %d, y = %d\n\n", x, y);
    
    printf("Before swap: x = %d, y = %d\n", x, y);
    SWAP(x, y);
    printf("After swap using a macro: x = %d, y = %d\n", x, y);
    
    return 0;
}
