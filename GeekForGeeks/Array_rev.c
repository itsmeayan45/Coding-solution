#include<stdio.h>
int main()
{
    int arr[]={10,25,76,93};
    int i,j;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0,j=n-1;i<j;i++,j--)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    for(i=0;i<n;i++)
    {
        printf("%3d",arr[i]);
    }
}