/*
#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> romanToIntMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;
        int prevValue = 0;

        for (char c : s) {
            int value = romanToIntMap[c];
            result += value;
            if (value > prevValue) {
                result -= 2 * prevValue; // Subtract twice the previous value
            }
            prevValue = value;
        }

        return result;
    }
};
*/
#include <unordered_map>
#include <string>

class Solution
{
public:
    int romanToInt(std::string s)
    {
        std::unordered_map<char, int> romanToIntMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

        int result = 0;
        int prevValue = 0;

        for (char c : s)
        {
            int value = romanToIntMap[c];
            result += value;
            if (value > prevValue)
            {
                result -= 2 * prevValue; // Subtract twice the previous value
            }
            prevValue = value;
        }

        return result;
    }
};
