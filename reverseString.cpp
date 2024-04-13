/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.



Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.*/

class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());

        int start = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        reverse(s.begin() + start, s.end());

        int left = 0, right = s.size() - 1;
        while (left <= right && s[left] == ' ')
            left++;
        while (left <= right && s[right] == ' ')
            right--;
        s = s.substr(left, right - left + 1);

        int i = 0, j = 0;
        while (j < s.size())
        {
            while (j < s.size() && s[j] == ' ')
                j++;
            while (j < s.size() && s[j] != ' ')
                s[i++] = s[j++];
            if (j < s.size())
                s[i++] = ' ';
        }
        s.resize(i);

        return s;
    }
};
