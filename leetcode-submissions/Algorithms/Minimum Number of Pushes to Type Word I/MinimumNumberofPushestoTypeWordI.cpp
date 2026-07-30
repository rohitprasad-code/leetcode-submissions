/*
  LeetCode Submission ID: 2088088598
  Date: 31/07/2026, 04:22:20
  Runtime: 0 ms
  Memory: 8.5 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/submissions/2088088598/?envType=daily-question&envId=2026-07-30
*/

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += i / 8 + 1;
        }
        return ans;
    }
};