/*
  LeetCode Submission ID: 2111689491
  Date: 18/08/2026, 21:58:08
  Runtime: 0 ms
  Memory: 29.2 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/find-the-largest-almost-missing-integer/description/?envType=daily-question&envId=2026-08-18
*/

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == k) {
            return *max_element(nums.begin(), nums.end());
        }
        int count[51] = {0};
        for (int x : nums) {
            count[x]++;
        }
        if (k == 1) {
            for (int i = 50; i >= 0; --i) {
                if (count[i] == 1) {
                    return i;
                }
            }
            return -1;
        }
        int res = -1;
        if (count[nums[0]] == 1) {
            res = max(res, nums[0]);
        }
        if (count[nums.back()] == 1) {
            res = max(res, nums.back());
        }
        return res;
    }
};