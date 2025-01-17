/*
6.Problem Statement:
Write a program to check if two strings are anagrams of each other. Two strings are anagrams 
if they contain the same characters in the same frequency.
Sample Input and Output:
1. Input: "listen", "silent"
Output: true
2. Input: "triangle", "integral"
Output: true
3. Input: "apple", "pale"
Output: false

*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define Max 100

bool anagram(char* str1 , char* str2,int length_str , int length_str1)
{
    char temp;
    if(length_str1 != length_str)
    {
        return false;
    }
    for(int i=0;i<length_str;i++)
    {
        for(int j =i+1;j<length_str;j++)
        {
            if(str1[i]>str1[j])
            {
               temp = str1[i];
                str1[i]=str1[j];
                str1[j]=temp;
            }
        }

    }
    for(int i=0;i<length_str1;i++)
    {
        for(int j =i+1;j<length_str1;j++)
        {
            if(str2[i]>str2[j])
            {
               temp = str2[i];
                str2[i]=str2[j];
                str2[j]=temp;
            }
        }
   
}
 if(strcmp(str1 , str2)==0)
    {
        return true;
    }
    return false;
}
int main(){
    char str1[Max],str2[Max];
    fgets(str1,Max,stdin);
    fgets(str2,Max,stdin);
    int length_str=0;
    int length_str1=0;


    while(str1[length_str] != '\n')
    {
        length_str++;
    }
    while(str2[length_str1] != '\n')
    {
        length_str1++;
    }
    bool ana = anagram(str1,str2,length_str,length_str1);
    if(ana)
    {
        printf("true\n");
    }
    else{
        printf("false\n");
    }
    

    return 0;
}