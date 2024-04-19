/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.



Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.*/

#include <cctype> // For isalnum function
#include <string>

class Solution
{
public:
    bool isPalindrome(string s)
    {
        // Initialize two pointers, one from the beginning and one from the end
        int left = 0;
        int right = s.length() - 1;

        // Traverse the string using two pointers
        while (left < right)
        {
            // Move the left pointer until it points to an alphanumeric character
            while (left < right && !isalnum(s[left]))
            {
                left++;
            }
            // Move the right pointer until it points to an alphanumeric character
            while (left < right && !isalnum(s[right]))
            {
                right--;
            }
            // Convert characters to lowercase and compare
            if (tolower(s[left]) != tolower(s[right]))
            {
                return false; // If characters are not equal, it's not a palindrome
            }
            // Move both pointers towards the center
            left++;
            right--;
        }
        return true; // If we reach here, it's a palindrome
    }
};
