/*
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is
the smallest in lexicographical order
 among all possible results.



Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"*/

#include <string>
#include <vector>
#include <stack>
#include <algorithm>

class Solution
{
public:
    std::string removeDuplicateLetters(std::string s)
    {
        std::vector<int> count(26, 0);
        std::vector<bool> visited(26, false);
        std::stack<char> st;

        for (char c : s)
        {
            count[c - 'a']++;
        }

        for (char c : s)
        {
            count[c - 'a']--;
            if (visited[c - 'a'])
                continue;

            while (!st.empty() && st.top() > c && count[st.top() - 'a'] > 0)
            {
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            visited[c - 'a'] = true;
        }

        std::string result = "";
        while (!st.empty())
        {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};
