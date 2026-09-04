/*
  LeetCode Submission ID: 2130446608
  Date: 04/09/2026, 13:13:54
  Runtime: 0 ms
  Memory: 30.2 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/smallest-stable-index-i/submissions/2130446608/?envType=daily-question&envId=2026-09-04
*/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int maxValue = nums[i], minValue = nums[i];
            for (int j = 0; j < i; ++j) {
                maxValue = max(maxValue, nums[j]);
            }
            for (int j = i + 1; j < n; ++j) {
                minValue = min(minValue, nums[j]);
            }
            if (maxValue - minValue <= k) {
                return i;
            }
        }
        return -1;
    }
};