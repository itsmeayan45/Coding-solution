def find_Majority(arr):
    if not arr:
        return []
    n = len(arr)
    major = n // 3
    count_map = {}
    for candidate in arr:
        if candidate in count_map:
            count_map[candidate] += 1
        else:
            count_map[candidate] = 1
    result = []
    for candidate, count in count_map.items():
        if count > major:
            result.append(candidate)
    result.sort()
    return result
arr=[2,3,4,5,5,5,5,5,6,6,6,6,6]
print(find_Majority(arr))

