/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.


Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.*/
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0 || x == 1)
            return x; // Base case: if x is 0 or 1, return x

        long left = 1;  // Start from 1
        long right = x; // End at x

        while (left < right)
        {                                         // Perform binary search
            long mid = left + (right - left) / 2; // Calculate mid point

            if (mid * mid == x)
            { // If mid squared is equal to x, return mid
                return mid;
            }
            else if (mid * mid < x)
            { // If mid squared is less than x, search in the right half
                left = mid + 1;
            }
            else
            { // If mid squared is greater than x, search in the left half
                right = mid;
            }
        }

        // At the end of the loop, 'left' will be equal to 'right'
        // Since we are rounding down to the nearest integer, return left - 1
        return left - 1;
    }
};
