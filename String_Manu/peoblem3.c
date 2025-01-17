/*
3.Problem Statement:
Write a function to check if a given substring exists within a string. Return the starting index of 
the substring if it exists; otherwise, return -1.
Sample Input and Output:
1. Input: string = "hello world", substring = "world"
Output: 6
2. Input: string = "programming", substring = "gram"
Output: 3
3. Input: string = "abcdef", substring = "xyz"
Output: -1

*/
#include<stdio.h>
#include<string.h>
#define Max 500
int substring(char* str , char* str1 , int count_length , int count_length1)

{
    int flag=-1;
    for(int length_of_string = 0 ; length_of_string<=(count_length-count_length1); length_of_string++)
    {
          int length_of_string1=0;
          while(length_of_string1 <count_length1 && str[length_of_string+length_of_string1]==str1[length_of_string1])
          {
                length_of_string1++;
          }
          if(length_of_string1==count_length1)
          {
            flag=length_of_string;
            break;
          }
        
    }
    return flag;

}
int main()
{
    char str[Max],str1[Max];
    fgets(str,Max,stdin);
     fgets(str1,Max,stdin);
    int count_length =0;
    int count_length1 =0;
    while(str[count_length]!='\n')
    {
        count_length++;
    }
    
    while(str1[count_length1]!='\n')
    {
        count_length1++;
    }
   
   int index = substring(str,str1,count_length,count_length1);
    printf("%d",index);
    return 0;
}