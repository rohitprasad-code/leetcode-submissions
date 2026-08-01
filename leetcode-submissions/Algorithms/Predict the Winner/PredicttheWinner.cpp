/*
  LeetCode Submission ID: 2090493157
  Date: 02/08/2026, 00:36:58
  Runtime: 0 ms
  Memory: 10.4 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/predict-the-winner/submissions/2090493157/?envType=daily-question&envId=2026-08-01
*/

class Solution {
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int i, int j) {
        if (i == j)
            return nums[i];

        if (dp[i][j] != INT_MIN)
            return dp[i][j];

        int left = nums[i] - solve(nums, i + 1, j);
        int right = nums[j] - solve(nums, i, j - 1);

        return dp[i][j] = max(left, right);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(n, INT_MIN));

        return solve(nums, 0, n - 1) >= 0;
    }
};