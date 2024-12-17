def kadane(arr):
    max_ending_here = arr[0]
    max_so_far = arr[0]

    for i in range(1, len(arr)):
        max_ending_here = max(arr[i], max_ending_here + arr[i])
        max_so_far = max(max_so_far, max_ending_here)

    return max_so_far

def min_kadane(arr):
    min_ending_here = arr[0]
    min_so_far = arr[0]

    for i in range(1, len(arr)):
        min_ending_here = min(arr[i], min_ending_here + arr[i])
        min_so_far = min(min_so_far, min_ending_here)

    return min_so_far

def max_circular_subarray_sum(arr):
    n = len(arr)
    if n == 0:
        return 0

    # Case 1: Get the maximum sum using standard Kadane's algorithm
    max_kadane = kadane(arr)

    # Case 2: Find the maximum sum for the circular case
    total_sum = sum(arr)
    min_kadane = min_kadane(arr)
    max_circular = total_sum - min_kadane

    # If all numbers are negative, max_circular will be 0, so we return max_kadane
    if max_circular == 0:
        return max_kadane

    # Return the maximum of the two cases
    return max(max_kadane, max_circular)

# Example usage
arr = [8, -8, 9, -9, 10, -11, 12]
result = max_circular_subarray_sum(arr)
print("Maximum circular subarray sum is:", result)