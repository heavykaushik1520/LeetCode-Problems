/*
Given an integer num, return a string of its base 7 representation.

 

Example 1:

Input: num = 100
Output: "202"
Example 2:

Input: num = -7
Output: "-10"*/
#include <string>
#include <algorithm> // for reverse

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        
        string result = "";
        bool isNegative = false;
        
        if (num < 0) {
            isNegative = true;
            num = -num;
        }
        
        // Convert to base 7
        while (num > 0) {
            int remainder = num % 7;
            result += to_string(remainder);
            num /= 7;
        }
        
        reverse(result.begin(), result.end());
        
        if (isNegative) {
            result = "-" + result;
        }
        
        return result;
    }
};
