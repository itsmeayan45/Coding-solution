#include <stdio.h>
#include <limits.h>

int maxProductSubarray(int arr[], int n) {
    if (n == 0) return 0;

    int maxProduct = arr[0];
    int minProduct = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < 0) {
            
            int temp = maxProduct;
            maxProduct = minProduct;
            minProduct = temp;
        }

        
        maxProduct = (arr[i] > maxProduct * arr[i]) ? arr[i] : maxProduct * arr[i];
        minProduct = (arr[i] < minProduct * arr[i]) ? arr[i] : minProduct * arr[i];

        
        if (maxProduct > result) {
            result = maxProduct;
        }
    }

    return result;
}

int main() {
    int arr1[] = {-2, 6, -3, -10, 0, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Maximum product subarray: %d\n", maxProductSubarray(arr1, n1));

    int arr2[] = {-1, -3, -10, 0, 6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Maximum product subarray: %d\n", maxProductSubarray(arr2, n2));

    int arr3[] = {2, 3, 4};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Maximum product subarray: %d\n", maxProductSubarray(arr3, n3));

    return 0;
}