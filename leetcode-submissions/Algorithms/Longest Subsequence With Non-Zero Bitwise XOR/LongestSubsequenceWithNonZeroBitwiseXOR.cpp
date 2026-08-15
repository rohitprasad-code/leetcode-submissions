/*
  LeetCode Submission ID: 2108048456
  Date: 15/08/2026, 22:50:40
  Runtime: 0 ms
  Memory: 171.4 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/submissions/2108048456/?envType=daily-question&envId=2026-08-15
*/

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalXor = 0;
        bool allZero = true;

        for (int x : nums) {
            totalXor ^= x;
            if (x > 0) {
                allZero = false;
            }
        }

        if (totalXor > 0) {
            return n;
        }

        return allZero ? 0 : n - 1;
    }
};