/* This is a test C file for our lexical and syntax analyzer */

#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Main function
int main() {
    int num = 5;
    int result = 0;
    int a = 10;
    int b = 5;
    int i=0;

    // Calculate factorial
    result = factorial(num);
    
    // Print result
    printf("Factorial of %d is %d\n", num, result);
    
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    
    // Test control structures
    for (i = 0; i < 5; i++) {
        if (i % 2 == 0) {
            printf("%d is even\n", i);
        } else {
            printf("%d is odd\n", i);
        }
    }
    
    return 0;
}