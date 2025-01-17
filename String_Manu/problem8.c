/*
.Problem Statement:
Write a program to compress a string by replacing consecutive occurrences of the same 
character with the character followed by the count. If the compressed string is not smaller 
than the original, return the original string.
Sample Input and Output:
1. Input: "aaabbc"
Output: "a3b2c1"
2. Input: "abcd"
Output: "abcd"
3. Input: "aabbcc"
Output: "a2b2c2"
*/

#include <stdio.h>
#include <string.h>

char* compressString(const char *str) {
    int n = strlen(str);
    if (n == 0) return str;

    char compressed[2 * n + 1];
    int index = 0;
    int count = 1;

    for (int i = 1; i <= n; i++) {
        if (str[i] == str[i - 1]) {
            count++;
        } else {
            compressed[index++] = str[i - 1];
            compressed[index++] = count + '0';
            count = 1;
        }
    }

    compressed[index] = '\0';

    return strlen(compressed) < n ? compressed : (char *)str;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    printf("Compressed string: %s\n", compressString(str));

    return 0;
}
