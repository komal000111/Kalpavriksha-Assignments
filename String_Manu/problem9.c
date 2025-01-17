/*
9.Problem Statement:
Write a program to remove all instances of a specific character from a string.
Sample Input and Output:
1. Input: string = "banana", char = 'a'
Output: "bnn"
2. Input: string = "hello world", char = 'l'
Output: "heo word"
3. Input: string = "abcdef", char = 'x'
Output: "abcde"

*/

#include <stdio.h>
#include <string.h>

void removeChar(char *str, char ch) {
    int i = 0, j = 0;
    while (str[i]) {
        if (str[i] != ch) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

int main() {
    char str[100], ch;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Enter the character to remove: ");
    scanf("%c", &ch);

    removeChar(str, ch);

    printf("String after removal: %s\n", str);

    return 0;
}
