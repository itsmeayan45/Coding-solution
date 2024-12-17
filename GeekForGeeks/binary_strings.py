def add_binary(s1: str, s2: str) -> str:
    # Initialize variables
    result = []
    carry = 0
    i, j = len(s1) - 1, len(s2) - 1

    # Loop until both strings are processed and there's no carry left
    while i >= 0 or j >= 0 or carry:
        # Get the current bits (0 or 1) from each string
        bit1 = int(s1[i]) if i >= 0 else 0
        bit2 = int(s2[j]) if j >= 0 else 0
        
        # Calculate the sum of bits and carry
        total = bit1 + bit2 + carry
        carry = total // 2  # Update carry for the next iteration
        result.append(str(total % 2))  # Append the result bit

        # Move to the next bits
        i -= 1
        j -= 1

    # The result is in reverse order, so reverse it
    result.reverse()
    
    # Join the list into a string and remove leading zeros
    return ''.join(result).lstrip('0') or '0'  # Return '0' if the result is empty

# Example usage
s1 = "1101"
s2 = "111"
print(add_binary(s1, s2))  # Output: 10100

s1 = "00100"
s2 = "010"
print(add_binary(s1, s2))  # Output: 110