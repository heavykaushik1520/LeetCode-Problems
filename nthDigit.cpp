/*
Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].



Example 1:

Input: n = 3
Output: 3
Example 2:

Input: n = 11
Output: 0
Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
 */

class Solution
{
public:
    int findNthDigit(int n)
    {
        long base = 9, digits = 1;

        // Step 1: Determine the range of numbers where the nth digit belongs
        while (n - base * digits > 0)
        {
            n -= base * digits;
            base *= 10;
            digits++;
        }

        // Step 2: Calculate which number in that range contains the nth digit
        long num = pow(10, digits - 1) + (n - 1) / digits;

        // Step 3: Calculate the position of the nth digit within that number
        int digitIndex = (n - 1) % digits;

        // Step 4: Extract and return the nth digit
        return to_string(num)[digitIndex] - '0';
    }
};
