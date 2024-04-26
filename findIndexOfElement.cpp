/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]*/
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
        {
            return {-1, -1};
        }
        int l1 = 0;
        int r1 = nums.size() - 1;
        while (l1 < r1)
        {
            int m1 = l1 + (r1 - l1) / 2;
            if (nums[m1] >= target)
            {
                r1 = m1;
            }
            else
            {
                l1 = m1 + 1;
            }
        }

        int l2 = 0;
        int r2 = nums.size();
        while (l2 < r2)
        {
            int m2 = l2 + (r2 - l2) / 2;
            if (nums[m2] > target)
            {
                r2 = m2;
            }
            else
            {
                l2 = m2 + 1;
            }
        }

        if (nums[l1] != target)
        {
            return {-1, -1};
        }
        if (l1 == l2)
        {
            return {l1, l2};
        }
        return {l1, l2 - 1};
    }
};