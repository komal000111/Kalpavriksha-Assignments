/*Given a string array words, return the maximum value of length(word[i]) * length(word[j]) 
where the two words do not share common letters. If no such two words exist, return 0.
Example 1:
 
Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".
Example 2:
 
Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".
Example 3:
 
Input: words = ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define hashsize 255
int haveCommonLetters(char *word1, char *word2) {
    int hash[hashsize] = {0};

    
    while (*word1) {
        hash[*word1 - 'a'] = 1;
        word1++;
    }

   
    while (*word2) {
        if (hash[*word2 - 'a'] == 1)
            return 1; 
        word2++;
    }

    return 0; 
}
int calculate(char s[20][100],int n)
{
   
   // int n = strlen(s);
    int maxcount=0;
    int hash[hashsize]={0};
    int hash1[hashsize]={0};
    for(int i=0;i<n;i++)
    {   
        for(int j=i+1;j<n;j++)
        {
            if (!haveCommonLetters(s[i], s[j])) { 
                int product = strlen(s[i]) * strlen(s[j]);
                if (product > maxcount) {
                    maxcount = product;
                }      
            
    }
   
    

}
}
return maxcount;
}
int main()
{
    char str[200];
    char str1[20][100];
    int k=0;
  getchar();
  getchar();
    while(scanf("%[^\"]s",str))
    {
        strcpy(str1[k],str);
        k++;
       // char ch=
        char ch1 =getchar();
        char ch =getchar();
        if(ch==']')
        {
            break;
        }
        getchar();
    }
   int val= calculate(str1,k);
   printf("%d",val);
    return 0;
}