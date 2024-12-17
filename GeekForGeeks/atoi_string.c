#include <stdio.h>
#include <limits.h>

int myAtoi(char *s) {
    // Initialize variables
    int i = 0, sign = 1, result = 0;

    // Skip leading whitespaces
    while (s[i] == ' ') {
        i++;
    }

    // Check for sign
    if (s[i] == '-' || s[i] == '+') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Convert the digits
    while (s[i] >= '0' && s[i] <= '9') {
        // Check for overflow and underflow
        if (result > (INT_MAX - (s[i] - '0')) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        result = result * 10 + (s[i] - '0');
        i++;
    }

    return result * sign;
}

int main() {
    char str1[] = "-123";
    char str2[] = "  -0012gfg4";
    char str3[] = "  1231231231311133";
    char str4[] = "-999999999999";
    char str5[] = "  -";

    printf("Input: \"%s\" Output: %d\n", str1, myAtoi(str1)); // Output: -123
    printf("Input: \"%s\" Output: %d\n", str2, myAtoi(str2)); // Output: -12
    printf("Input: \"%s\" Output: %d\n", str3, myAtoi(str3)); // Output: 2147483647
    printf("Input: \"%s\" Output: %d\n", str4, myAtoi(str4)); // Output: -2147483648
    printf("Input: \"%s\" Output: %d\n", str5, myAtoi(str5)); // Output: 0

    return 0;
}