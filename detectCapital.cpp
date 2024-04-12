/*We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

Example 1:

Input: word = "USA"
Output: true
Example 2:

Input: word = "FlaG"
Output: false*/

#include <string>
using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int capitalCount = 0;

        for (char c : word)
        {
            if (isupper(c))
                capitalCount++;
        }

        return capitalCount == word.length() || capitalCount == 0 || (capitalCount == 1 && isupper(word[0]));
    }
};
