#include<stdio.h>
int maxProfit(int prices[],int n)
{
    int max_profit = 0;
    for (int i = 1; i < n; i++) {
        if (prices[i] > prices[i-1]) {
            max_profit += prices[i] - prices[i-1];
        }
    }
    return max_profit;
}
int main()
{
    int arr[]={100,180,260,310,40,535,695};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("%d",maxProfit(arr,n));
}