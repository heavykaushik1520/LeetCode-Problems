/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.*/

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {

        if (strs.length == 0)
            return " ";
        StringBuilder sb = new StringBuilder();
        int min = Integer.MAX_VALUE;

        for (int i = 0; i < strs.length; i++)
        {
            if (strs[i].length() < min)
            {
                min = strs[i].length();
            }
        }

        for (int i = 0; i < min; i++)
        {
            for (int j = 0; j < strs.length - 1; j++)
            {
                if (strs[i].charAt(i) != strs[j + 1].charAt(i))
                {
                    return sb.toString();
                }
                        }

            sb.append(strs[0].charAt(i));
        }

        return sb.toString();
    }
};