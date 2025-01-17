/*
7.Problem Statement:
Write a program to find the longest word in a given sentence. Assume words are separated by 
spaces.
Sample Input and Output:
1. Input: "The quick brown fox jumps"
Output: "jumps"
2. Input: "Hello world"
Output: "Hello"
3. Input: "a abc abcd"
Output: "abcd"

*/
#include <stdio.h>
#include <string.h>

void findLongestWord(const char *sentence) {
    int maxLength = 0;
    char longestWord[100];
    char currentWord[100];
    int i = 0, j = 0;

    while (sentence[i] != '\0') {
        if (sentence[i] != ' ') {
            currentWord[j++] = sentence[i];
        } else {
            currentWord[j] = '\0';
            if (j > maxLength) {
                maxLength = j;
                strcpy(longestWord, currentWord);
            }
            j = 0;
        }
        i++;
    }

    if (j > maxLength) {
        currentWord[j] = '\0';
        strcpy(longestWord, currentWord);
    }

    printf("Longest word: %s\n", longestWord);
}

int main() {
    char sentence[200];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    sentence[strcspn(sentence, "\n")] = '\0';

    findLongestWord(sentence);

    return 0;
}

