/*. Problem Statement:
Write a program to remove all duplicate characters from a given string. The resulting string 
should retain the order of first appearance of characters and should not contain any duplicate 
letters.
Sample Input and Output:
1. Input: "programming"
Output: "progamin"
2. Input: "banana"
Output: "ban"
3. Input: "abacabad"
Output: "abcd"*/
#include<stdio.h>
#include<string.h>
#define Max 500
void duplicate(char* str , int  count_length)


{
    
    for(int length_of_string =0 ; length_of_string<count_length;length_of_string++)
    {
        for(int length_of_string1=length_of_string +1;length_of_string1<count_length;length_of_string1++){
            if(str[length_of_string]==str[length_of_string1])
            {
                for(int new_length =length_of_string1 ; new_length<count_length;new_length++)
                {
                    str[new_length]=str[new_length + 1];

                }
                
                count_length--;
                length_of_string1--;
            }
        }
    }
}
int main(){
    char str[Max];
    fgets(str,Max,stdin);
    int count_length =0;
    while(str[count_length]!='\n')
    {
        count_length++;
    }
    //printf("%d",count_length);
    
    duplicate(str,count_length);
    printf("%s\n",str);
    return 0;
}