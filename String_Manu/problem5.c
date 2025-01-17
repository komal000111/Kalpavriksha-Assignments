/*
. Problem Statement:
Write a program to implement the atoi() function, which converts a string to an integer. The 
function should handle negative numbers and return 0 for invalid input.
Sample Input and Output:
1. Input: "1234"
Output: 1234
2. Input: "-567"
Output: -567
3. Input: "abc123"
Output: 0
*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define Max 100

bool anagram(char* str1, char* str2, int length_str, int length_str1)
{
    char temp;

    if(length_str1 != length_str)
    {
        return false;  // If the lengths don't match, they cannot be anagrams
    }

    // Sorting the first string (str1)
    for(int i = 0; i < length_str; i++)
    {
        for(int j = i + 1; j < length_str; j++)
        {
            if(str1[i] > str1[j])
            {
                temp = str1[i];
                str1[i] = str1[j];
                str1[j] = temp;
            }
        }
    }

    // Sorting the second string (str2)
    for(int i = 0; i < length_str1; i++)
    {
        for(int j = i + 1; j < length_str1; j++)
        {
            if(str2[i] > str2[j])
            {
                temp = str2[i];
                str2[i] = str2[j];
                str2[j] = temp;
            }
        }
    }

    // After sorting, compare both strings
    if(strcmp(str1, str2) == 0)
    {
        return true;  // They are anagrams if sorted strings are equal
    }

    return false;  // If they are not equal after sorting, they are not anagrams
}

int main()
{
    char str1[Max], str2[Max];
    
    // Reading the input strings
    fgets(str1, Max, stdin);
    fgets(str2, Max, stdin);

    // Removing newline characters added by fgets
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    // Calculating the lengths of the strings
    int length_str = strlen(str1);
    int length_str1 = strlen(str2);

    // Checking if the strings are anagrams
    bool ana = anagram(str1, str2, length_str, length_str1);

    // Printing the result
    if(ana)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    return 0;
}
