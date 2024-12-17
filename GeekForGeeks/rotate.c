#include<stdio.h>
void rotatearray(int arr[],int n,int d)
{
        int temp[n];
    
    
    d = d %n;
    
    
    for (int i = 0; i < n; i++) {
        temp[i] = arr[(i + d) % n];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}


int main()
{
    int n,d;
    printf("Enter the number of Elements:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the value of D:\n");
    scanf("%d",&d);
    rotatearray(arr,n,d);
    printf("Final output of the array is:\n");
    for(int i=0;i<n;i++)
    {
        printf("%3d",arr[i]);
    }

}
/*Input: arr[] = [1, 2, 3, 4, 5], d = 2
Output: [3, 4, 5, 1, 2]
Explanation: when rotated by 2 elements, it becomes 3 4 5 1 2.
Input: arr[] = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20], d = 3
Output: [8, 10, 12, 14, 16, 18, 20, 2, 4, 6]
Explanation: when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.
Input: arr[] = [7, 3, 9, 1], d = 9
Output: [3, 9, 1, 7]
Explanation: when we rotate 9 times, we'll get 3 9 1 7 as resultant array.*/