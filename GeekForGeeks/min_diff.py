def min_difference(arr, n, k):

    arr.sort()
    diff = arr[n - 1] - arr[0] 
    new_min = arr[0] + k  
    new_max = arr[n - 1] - k  
    for i in range(1, n):
        current_min = max(arr[i] - k, 0) 
        current_max = arr[i - 1] + k
        new_min = min(new_min, current_min)
        new_max = max(new_max, current_max)

    
    return max(0, new_max - new_min)  


if __name__ == "__main__":
    arr = [1, 5, 8, 10]
    k = 2
    n = len(arr)

    result = min_difference(arr, n, k)
    print("Minimum possible difference:", result)

    arr2 = [3, 9, 12, 16, 20]
    k2 = 3
    n2 = len(arr2)

    result2 = min_difference(arr2, n2, k2)
    print("Minimum possible difference:", result2)