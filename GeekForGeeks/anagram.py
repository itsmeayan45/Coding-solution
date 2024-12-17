def anagrams(s1, s2):
    
    if len(s1) != len(s2):
        return False
    
    
    char_count = {}
    
    for char in s1:
        char_count[char] = char_count.get(char, 0) + 1
    
    for char in s2:
        if char in char_count:
            char_count[char] -= 1
        else:
            return False
    
    
    for count in char_count.values():
        if count != 0:
            return False
    
    return True


s1 = "geeks"
s2 = "kseeg"
print(anagrams(s1, s2))  

s1 = "allergy"
s2 = "allergic"
print(anagrams(s1, s2))  