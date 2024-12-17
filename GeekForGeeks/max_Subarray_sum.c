#include <stdio.h>
#include <limits.h>

int max_circular_subarray_sum(int arr[], int n) {
    int max_kadane = INT_MIN, max_ending = 0;
    int min_kadane = INT_MAX, min_ending = 0;
    int total_sum = 0;

    for (int i = 0; i < n; i++) {
        total_sum += arr[i];
        max_ending= (max_ending+ arr[i] > arr[i]) ? max_ending + arr[i] : arr[i];
        max_kadane = (max_kadane > max_ending) ? max_kadane : max_ending;
        min_ending= (min_ending + arr[i] < arr[i]) ? min_ending+ arr[i] : arr[i];
        min_kadane = (min_kadane < min_ending) ? min_kadane : min_ending;
    }
    int max_circular = total_sum - min_kadane;
    return (max_kadane > max_circular && max_circular != 0) ? max_kadane : max_circular;
}

int main() {
    int arr[] = {8, -8, 9, -9, 10, -11, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = max_circular_subarray_sum(arr, n);
    printf("Maximum circular subarray sum is: %d\n", result);
    return 0;
}