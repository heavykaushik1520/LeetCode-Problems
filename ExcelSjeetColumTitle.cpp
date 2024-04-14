/*
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...


Example 1:

Input: columnNumber = 1
Output: "A"
Example 2:

Input: columnNumber = 28
Output: "AB"
Example 3:

Input: columnNumber = 701
Output: "ZY"
 */
#include <string>
using namespace std;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string result = "";
        while (columnNumber > 0)
        {
            int remainder = columnNumber % 26;
            if (remainder == 0)
            {
                remainder = 26;
                columnNumber -= 1;
            }
            char letter = 'A' + remainder - 1;
            result = letter + result;
            columnNumber /= 26;
        }
        return result;
    }
};
