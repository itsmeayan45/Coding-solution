def first_non_repeating_character(s):
    
    char_count = {}
    
    
    for char in s:
        if char in char_count:
            char_count[char] += 1
        else:
            char_count[char] = 1
    
   
    for char in s:
        if char_count[char] == 1:
            return char
    
    
    return -1

# Example usage:
s1 = "geeksforgeeks"
s2 = "racecar"
s3 = "aabbccc"

print(first_non_repeating_character(s1))  # Output: 'f'
print(first_non_repeating_character(s2))  # Output: 'e'
print(first_non_repeating_character(s3))  # Output: -1