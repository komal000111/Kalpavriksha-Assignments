/*
4.Problem Statement:
Write a program to check if one string is a rotation of another string. For example, "abcd" and 
"dabc" are rotations of each other.
Sample Input and Output:
1. Input: string1 = "abcd", string2 = "dabc"
Output: true
2. Input: string1 = "rotation", string2 = "ationrot"
Output: true
3. Input: string1 = "hello", string2 = "world"
Output: false
*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define Max 500
bool rotation(char str[],char str1[],int length_str,int length_str1)
{
    char temp;

    int j =0;
    if(length_str1 != length_str)
    {
        return false;
    }
    for(int i =0;i<length_str;i++)
    {
        if(strcmp(str , str1)==0)
        {
            return true;

        }
        temp = str[length_str-1];
    for(int j=length_str-1;j>0;j--)
    {
        str[j]= str[j-1];
       
        
        
    }
     str[0]=temp;
    
}
return false;
}
int main()
{
    char str[Max],str1[Max];
    fgets(str,Max,stdin);
    fgets(str1,Max,stdin);
    int length_str =0;
    int length_str1=0;
    while(str[length_str] !='\n')
    {
        length_str++;
    }
    while(str1[length_str1] !='\n')
    {
        length_str1++;
    }
   bool sttr = rotation(str,str1,length_str,length_str1);
   
    if(sttr){
        printf("true\n");
    }
    else{
        printf("false\n");
    }
    return sttr;
}