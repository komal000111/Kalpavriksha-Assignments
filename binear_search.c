#include<stdio.h>


int search(int arr[] , int low, int high  , int x)
{
    
   while(low <=high)
   {
    int mid = low+(high - low)/2;
    if(arr[mid] == x)
    return mid;
    if(arr[mid] < x)
    low=mid+1;
    else
    high = mid -1;
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
    int result = search(arr,0,n-1,x);
    if(result != -1)
    {
        printf("element found");

    }
    else{
    printf("element not found");}
   return 0;
}