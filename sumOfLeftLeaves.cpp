/*
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.



Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.*/
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> charCount;

        // Count the frequency of each character
        for (char c : s)
        {
            charCount[c]++;
        }

        int length = 0;
        bool oddFound = false;

        // Iterate over the character counts
        for (const auto &pair : charCount)
        {
            int count = pair.second;
            if (count % 2 == 0)
            {
                length += count; // Add even counts directly to the length
            }
            else
            {
                length += count - 1; // Add even part of odd counts
                oddFound = true;     // Mark odd count found
            }
        }

        // If at least one odd count was found, add 1 for the middle character
        if (oddFound)
        {
            length++;
        }

        return length;
    }
};

int main()
{
    Solution solution;
    cout << "Length of longest palindrome: " << solution.longestPalindrome("abccccdd") << endl;
    cout << "Length of longest palindrome: " << solution.longestPalindrome("a") << endl;
    return 0;
}
