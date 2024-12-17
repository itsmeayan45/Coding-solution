#include <stdio.h>

int maxProfit(int prices[], int n) {
    if (n <= 1) return 0; 
    int minPrice = prices[0]; 
    int maxProfit = 0;    
    for (int i = 1; i < n; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else {
            int profit = prices[i] - minPrice;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
    }

    return maxProfit;
}

int main() {
    int prices1[] = {7, 10, 1, 3, 6, 9, 2};
    int n1 = sizeof(prices1) / sizeof(prices1[0]);
    printf("Maximum profit for prices1: %d\n", maxProfit(prices1, n1));  // Output: 8

    int prices2[] = {7, 6, 4, 3, 1};
    int n2 = sizeof(prices2) / sizeof(prices2[0]);
    printf("Maximum profit for prices2: %d\n", maxProfit(prices2, n2));  // Output: 0

    int prices3[] = {1, 6, 14, 23, 31};
    int n3 = sizeof(prices3) / sizeof(prices3[0]);
    printf("Maximum profit for prices3: %d\n", maxProfit(prices3, n3));
    return 0;
}