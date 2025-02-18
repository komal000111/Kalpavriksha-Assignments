/*Problem: First Non-Repeating Character in a Stream
Problem Statement
Given a stream of characters, process each character and find the first non-repeating character in the stream at every step. If there is no non-repeating character, return -1.
Input
A string S consisting of lowercase English letters.
Output
A string where each character represents the first non-repeating character at that moment.
Constraints
1 ≤ |S| ≤ 10^5 (Length of the stream is large, so optimize for O(N) time).
Example 1
Input:
plaintextCopyEditS = "aabc"
Explanation:
a → First non-repeating is "a".
aa → No non-repeating character, so "-1".
aab → First non-repeating is "b".
aabc → First non-repeating is "b".
✅ Output: "a-1bb"*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_CHAR 256
#define MAX_LEN 100005
typedef struct {
    char data[MAX_LEN];
    int front , rear;

}queue;
typedef struct hashmap{
    char c;
    int count;
} hashm;
hashm hash[MAX_LEN];
int hashsize=0;
queue*q;
void intitQueue(queue* q)
{
    q->front=q->rear=0;
}
void enqueue(queue*q,char ch)
{
    q->data[q->rear++]=ch;
}
char dequeue(queue*q)
{
    char val=q->data[q->front];
    q->front++;
    return val;
}

char peek()
{
    return q->data[q->front];
}
int isEmpty(queue*q)
{
    return q->front==q->rear;
}
void firstNOnReapeatingChar(char*s)
{
    // intitQueue(q);
    
    // int hash[MAX_CHAR]={0};
    int n =strlen(s);
//     for(int i=0;i<n;i++)
//     {
//     if(hash[s[i]]==0)
//     {
//         enqueue(q,s[i]);
//     }
//     else if(!isEmpty(q)&&s[i]==peek())
//     {
//         dequeue(q);
//     }

//     hash[s[i]]++;
//     if(isEmpty(q))
//     {
//             int val=-1;
//             printf("%d",val);
//         }
//     if (!isEmpty(q))
//     {
//         printf("%c",peek());
//     }

//     // if(isEmpty(q))
//     // {
//     //     int val=-1;
//     //     printf("%d",val);
//     // }
    

// }
for(int i=0;i<n;i++)
{
    int j=0;
    for( j=0;j<hashsize;j++)
    {
        if(hash[j].c==s[i])
        {
            hash[j].count++;
            break;
        }
    }
    if(j==hashsize)
    {
            hash[hashsize].c=s[i];
            hash[hashsize].count=1;
            hashsize++;
    }
    int k=0;
    for( k=0;k<hashsize;k++)
    {
        if(hash[k].count==1)
        {
            printf("%c",hash[k].c);
            break;
        }
    }
    if(k==hashsize)
    {
        printf("-1");
    }
}

}
int main()
{
    
    char s [MAX_LEN];
    char s1[MAX_LEN];
    scanf("%s",s);
    q=(queue*)malloc(sizeof(queue));
    firstNOnReapeatingChar(s);

    return 0;

}
