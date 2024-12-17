#include <stdio.h>

int findMissingPositive(int arr[], int size) {
    // First, we will ignore negative numbers and numbers greater than size
    for (int i = 0; i < size; i++) {
        while (arr[i] > 0 && arr[i] <= size && arr[arr[i] - 1] != arr[i]) {
            // Swap arr[i] with arr[arr[i] - 1]
            int temp = arr[i];
            arr[i] = arr[temp - 1];
            arr[temp - 1] = temp;
        }
    }

    // Now, find the first index which does not have the correct value
    for (int i = 0; i < size; i++) {
        if (arr[i] != i + 1) {
            return i + 1; // The smallest missing positive number
        }
    }

    // If all numbers from 1 to size are present, return size + 1
    return size + 1;
}

int main() {
    int arr1[] = {2, -3, 4, 1, 1, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("\n%d\n",size1);
    printf("Smallest positive missing number is: %d\n", findMissingPositive(arr1, size1));

    int arr2[] = {5, 3, 2, 5, 1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Smallest positive missing number is: %d\n", findMissingPositive(arr2, size2));

    int arr3[] = {-8, 0, -1, -4, -3};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Smallest positive missing number is: %d\n", findMissingPositive(arr3, size3));

    return 0;
}