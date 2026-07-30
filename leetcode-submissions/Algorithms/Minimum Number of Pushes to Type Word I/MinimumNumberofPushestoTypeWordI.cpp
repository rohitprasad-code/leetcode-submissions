/*
  LeetCode Submission ID: 2087676007
  Date: 30/07/2026, 20:46:33
  Runtime: 0 ms
  Memory: 8.1 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/submissions/2087676007/?envType=daily-question&envId=2026-07-30
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