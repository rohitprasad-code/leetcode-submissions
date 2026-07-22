/*
  LeetCode Submission ID: 2076460044
  Date: 22/07/2026, 06:52:42
  Runtime: 116 ms
  Memory: 80.9 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/maximize-active-section-with-trade-i/submissions/2076460044/?envType=daily-question&envId=2026-07-21
*/

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int cnt1 = count(s.begin(), s.end(), '1');

        vector<int> zeroBlocks;
        int i = 0;
        while (i < n) {
            int start = i;

            while (i < n && s[i] == s[start]) {
                ++i;
            }

            if (s[start] == '0') {
                zeroBlocks.push_back(i - start);
            }
        }

        int m = zeroBlocks.size();

        if (m < 2) {
            return cnt1;
        }

        int bestGain = 0;  // Optimal Increment
        for (int i = 0; i < m - 1; ++i) {
            bestGain = max(bestGain, zeroBlocks[i] + zeroBlocks[i + 1]);
        }

        return cnt1 + bestGain;
    }
};