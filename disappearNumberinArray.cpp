/*
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2]*/

#include <vector>
#include <cmath> // for abs()

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        std::vector<int> disappearedNumbers;
        
        // Mark numbers as negative to indicate appearance
        for (int num : nums) {
            int index = std::abs(num) - 1;
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }
        
        // Find the positive numbers (missing numbers)
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                disappearedNumbers.push_back(i + 1);
            }
        }
        
        return disappearedNumbers;
    }
};
