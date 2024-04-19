/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false*/
class Solution
{
public:
    bool isAnagram(string s, string t)
    {

        int freq1[27] = {0};

        for (int i = 0; i < s.size(); i++)
        {
            freq1[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            freq1[t[i] - 'a']--;
        }
        for (int i = 0; i < 27; i++)
        {
            if (freq1[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};