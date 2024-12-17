def count_inversions(arr):
    n = len(arr)
    temp_arr = [0] * n
    inv_count = 0

    def merge_and_count(left, mid, right):
        nonlocal inv_count
        i = left    # Starting index for left subarray
        j = mid + 1 # Starting index for right subarray
        k = left    # Starting index to be sorted

        while i <= mid and j <= right:
            if arr[i] <= arr[j]:
                temp_arr[k] = arr[i]
                i += 1
            else:
                # There are mid - i inversions, because all the remaining elements in the left subarray
                # (arr[i], arr[i+1], ..., arr[mid]) are greater than arr[j]
                temp_arr[k] = arr[j]
                inv_count += (mid - i + 1)
                j += 1
            k += 1

        # Copy the remaining elements of left subarray, if any
        while i <= mid:
            temp_arr[k] = arr[i]
            i += 1
            k += 1

        # Copy the remaining elements of right subarray, if any
        while j <= right:
            temp_arr[k] = arr[j]
            j += 1
            k += 1

        # Copy the sorted subarray into Original array
        for i in range(left, right + 1):
            arr[i] = temp_arr[i]

    def merge_sort_and_count(left, right):
        if left < right:
            mid = (left + right) // 2
            merge_sort_and_count(left, mid)
            merge_sort_and_count(mid + 1, right)
            merge_and_count(left, mid, right)

    merge_sort_and_count(0, n - 1)
    return inv_count

# Example usage
arr1 = [2, 4, 1, 3, 5]
print("Inversion Count:", count_inversions(arr1))  # Output: 3

arr2 = [2, 3, 4, 5, 6]
print("Inversion Count:", count_inversions(arr2))  # Output: 0

arr3 = [10, 10, 10]
print("Inversion Count:", count_inversions(arr3))  # Output: 0