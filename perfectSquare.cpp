/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 */

#include <vector>
#include <cmath>

class Solution {
public:
    int numSquares(int n) {
        // Create a vector to store the minimum number of perfect squares required to sum up to each number from 0 to n
        std::vector<int> dp(n + 1, INT_MAX);

        // Base case: 0 requires 0 perfect squares
        dp[0] = 0;

        // Iterate through numbers from 1 to n
        for (int i = 1; i <= n; ++i) {
            // Try every possible perfect square less than or equal to i
            for (int j = 1; j * j <= i; ++j) {
                // Update dp[i] with the minimum of its current value and dp[i - j*j] + 1
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }

        // Return the result for n
        return dp[n];
    }
};
