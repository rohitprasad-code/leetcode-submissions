/*
  LeetCode Submission ID: 2103625307
  Date: 12/08/2026, 09:37:28
  Runtime: 54 ms
  Memory: 149.4 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/submissions/2103625307/?envType=daily-question&envId=2026-08-12
*/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int left = 0, max_len = 0;
        for (int right = 0; right < nums.size(); ++right) {
            count[nums[right]]++;
            while (count[nums[right]] > k) {
                count[nums[left]]--;
                left++;
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};