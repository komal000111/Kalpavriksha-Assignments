#include<stdio.h>


int search(int arr[] , int n , int x)
{
    
    for(int i =0;i<n;i++)
    {
        if(arr[i] == x)
        return i;
    

    }
    return -1;
    
}
int main()
{
    int n ;
    scanf("%d",&n);
    int arr[n];
    
    for(int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
   
   int x;
    scanf("%d",&x);//element to be search
    int result = search(arr,n,x);
    if(result != -1)
    {
        printf("element found");

    }
    else{
    printf("element not found");}
   return 0;
}