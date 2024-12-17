#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void next_permutation(int arr[], int n) {
    int i = n - 2;

    
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }

    if (i >= 0) { 

        int j = n - 1;
        while (arr[j] <= arr[i]) {
            j--;
        }

       
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    
    reverse(arr, i + 1, n - 1);
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    next_permutation(arr, n);

    // Print the next permutation
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}