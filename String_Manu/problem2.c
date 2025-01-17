/*
2.Problem Statement:
Write a program to count the number of words in a given string. Assume words are separated 
by one or more spaces, and the string may contain leading or trailing spaces.
Sample Input and Output:
1. Input: "Hello World"
Output: 2
2. Input: " The quick brown fox"
Output: 4
3. Input: "This is a test "
Output: 4
*/

#include<stdio.h>
#include<string.h>
#define Max 500
int count_word(char* str , int count_length)
{
    int count =0;
    for(int length_of_string =0 ; length_of_string<count_length;length_of_string++){
        if(str[length_of_string] == ' '){
            count++;
        }
    }
    return count;
}
int main(){
    char str[Max];
    fgets(str , Max,stdin);
    int count_length =0;
    while(str[count_length] != '\n')
    {
        count_length++;
    }
    int count=count_word(str,count_length);
    printf("%d",count);
    return 0;
}