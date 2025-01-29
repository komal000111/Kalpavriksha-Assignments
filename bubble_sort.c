#include<stdio.h>
int main()
{
   int n;
    printf("ENter the size of array");
    scanf("%d",&n);
 int arr1[n],i,temp;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
    }
    
    for(int i =0;i<n-1;i++)
    {
        for(int j =0;j<n-1-i;j++)
        {
            if(arr1[j]>arr1[j+1])
            {
                temp=arr1[j];
                arr1[j]=arr1[j+1];
                arr1[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr1[i]);
    }
}