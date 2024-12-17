#include <stdio.h>

int maxSubArraySum(int arr[], int n) {
    int max_so_far = arr[0]; // Initialize to the first element
    int max_ending_here = arr[0]; // Initialize to the first element

    for (int i = 1; i < n; i++) {
        max_ending_here = (arr[i] > max_ending_here + arr[i]) ? arr[i] : (max_ending_here + arr[i]);
        max_so_far = (max_so_far > max_ending_here) ? max_so_far : max_ending_here;
    }

    return max_so_far;
}

int main() {
    int arr1[] = {2, 3, -8, 7, -1, 2, 3};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Maximum sum of subarray: %d\n", maxSubArraySum(arr1, n1));

    int arr2[] = {-2, -4};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Maximum sum of subarray: %d\n", maxSubArraySum(arr2, n2));

    int arr3[] = {5, 4, 1, 7, 8};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Maximum sum of subarray: %d\n", maxSubArraySum(arr3, n3));

    return 0;
}