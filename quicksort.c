#include<stdio.h>
int partition(int arr[],int high,int lower)
{
    int pivot = arr[lower];
    int i = lower;
    int j =high;
    int temp;
    while(i<j)
    {
        while(i<=high && arr[i]<=pivot)
        {
            i++;
        }
        while(j>=lower &&arr[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[lower];
    arr[lower]=arr[j];
    arr[j]=temp;
    return j;

}
void sort(int arr[],int high, int lower)
{
    if(lower<high)
    {
    int partitionindex;
    partitionindex=partition(arr,high, lower);
    sort(arr,partitionindex-1,lower);
    sort(arr,high,partitionindex+1);
    }
    

}
int print(int arr[] , int n)
{
    printf("\n");
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
    printf("%ld ", sizeof(arr)/sizeof(arr[0]));
    for(int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int high , mid , lower;
    lower=0;
    high=n-1;
   
    print(arr,n);
    sort(arr,high,lower);
    print(arr,n);
}