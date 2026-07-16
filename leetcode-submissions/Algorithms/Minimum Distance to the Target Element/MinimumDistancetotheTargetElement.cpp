/*
  LeetCode Submission ID: 2070426262
  Date: 17/07/2026, 03:21:33
  Runtime: 0 ms
  Memory: 13.5 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/minimum-distance-to-the-target-element/submissions/2070426262/?envType=daily-question&envId=2026-07-16
*/

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                res = min(res, abs(i - start));
            }
        }
        return res;
    }
};