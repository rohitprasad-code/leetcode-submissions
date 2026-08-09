/*
  LeetCode Submission ID: 2100834666
  Date: 10/08/2026, 02:13:55
  Runtime: 0 ms
  Memory: 13.7 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/stone-game-ii/submissions/2100834666/?envType=daily-question&envId=2026-08-09
*/

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> memo(piles.size(), vector<int>(piles.size()));
        vector<int> suffixSum = piles;
        for (int i = suffixSum.size() - 2; i >= 0; --i)
            suffixSum[i] += suffixSum[i + 1];
        return maxStones(suffixSum, 1, 0, memo);
    }

    int maxStones(vector<int>& suffixSum, int maxTillNow, int currIndex,
                  vector<vector<int>>& memo) {
        if (currIndex + 2 * maxTillNow >= suffixSum.size())
            return suffixSum[currIndex];
        if (memo[currIndex][maxTillNow] > 0) return memo[currIndex][maxTillNow];
        int res = INT_MAX;

        for (int i = 1; i <= 2 * maxTillNow; ++i) {
            res = min(res, maxStones(suffixSum, max(i, maxTillNow),
                                     currIndex + i, memo));
        }
        memo[currIndex][maxTillNow] = suffixSum[currIndex] - res;
        return memo[currIndex][maxTillNow];
    }
};