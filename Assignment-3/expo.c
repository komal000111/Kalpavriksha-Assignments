#include <stdio.h>
#include <stdlib.h>


int modular_exponentiation(int base, int exponent, int modulus) {
    int result = 1;
    base = base % modulus; 

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1; 
        base = (base * base) % modulus;
    }

    return result;
}

int main() {
    int base, exponent, modulus, result;

   
    do {
        printf("Enter the base (B): ");
        scanf("%d", &base);
        printf("Enter the exponent (N): ");
        scanf("%d", &exponent);
        printf("Enter the modulus (M): ");
        scanf("%d", &modulus);

        if (modulus <= 1 || exponent < 0) {
            printf("Invalid input.\n");
        }
    } while (modulus <= 1 || exponent < 0);

    result = modular_exponentiation(base, exponent, modulus);
    printf("Result: %d\n", result);

    return 0;
}