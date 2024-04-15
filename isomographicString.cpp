/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.



Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true*/

#include <unordered_map>
#include <string>

class Solution
{
public:
    bool isIsomorphic(std::string s, std::string t)
    {
        if (s.size() != t.size())
            return false;

        std::unordered_map<char, char> s_to_t_mapping;
        std::unordered_map<char, char> t_to_s_mapping;

        for (int i = 0; i < s.size(); ++i)
        {
            char s_char = s[i];
            char t_char = t[i];

            // Check if s_char already has a mapping
            if (s_to_t_mapping.find(s_char) != s_to_t_mapping.end())
            {
                // If the mapping doesn't match, return false
                if (s_to_t_mapping[s_char] != t_char)
                    return false;
            }
            else
            {
                // If s_char doesn't have a mapping, create one
                s_to_t_mapping[s_char] = t_char;
            }

            // Check if t_char already has a mapping
            if (t_to_s_mapping.find(t_char) != t_to_s_mapping.end())
            {
                // If the mapping doesn't match, return false
                if (t_to_s_mapping[t_char] != s_char)
                    return false;
            }
            else
            {
                // If t_char doesn't have a mapping, create one
                t_to_s_mapping[t_char] = s_char;
            }
        }

        return true;
    }
};
