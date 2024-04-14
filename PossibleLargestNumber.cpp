/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"*/

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert numbers to strings
        vector<string> numStrings(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            numStrings[i] = to_string(nums[i]);
        }
        
       
        sort(numStrings.begin(), numStrings.end(), [](const string& a, const string& b) {
            return a + b > b + a; // Compare a+b with b+a
        });
        
        // Concatenate the sorted strings
        string result;
        for (const string& str : numStrings) {
            result += str;
        }
        
        // Handle leading zeros
        if (result[0] == '0') {
            return "0"; // If the largest number is 0, return "0"
        }
        
        return result;
    }
};
