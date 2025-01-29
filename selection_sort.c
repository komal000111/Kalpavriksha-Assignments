#include<stdio.h>
int sort(int arr[],int n)
{
    for(int i =0;i<n;i++)
    {
        int minindex=i;
        for(int j =i+1;j<n;j++)
        {
            if(arr[j]<arr[minindex])
            {
                minindex=j;
            }
            
        }
        int temp;
        temp=arr[minindex];
        arr[minindex]=arr[i];
        arr[i]=temp;
    }
    return 0;
}
int print(int arr[] , int n)
{
    for(int i =0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
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
    print(arr,n);
    sort(arr,n);
    print(arr,n);
}