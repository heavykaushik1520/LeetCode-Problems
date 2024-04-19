/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.



Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 */
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.size() > magazine.size())
        {
            return false;
        }
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        int i = 0;
        int n = magazine.size();
        while (ransomNote.size() != 0 && i != n)
        {
            if (ransomNote[0] == magazine[i])
            {
                ransomNote.erase(0, 1);
            }
            i++;
        }
        if (ransomNote.size() != 0)
        {
            return false;
        }
        return true;
    }
};