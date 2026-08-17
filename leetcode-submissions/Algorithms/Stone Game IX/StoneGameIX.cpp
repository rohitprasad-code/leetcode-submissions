/*
  LeetCode Submission ID: 2110387659
  Date: 17/08/2026, 22:04:29
  Runtime: 3 ms
  Memory: 131.4 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/stone-game-ix/description/?envType=daily-question&envId=2026-08-17
*/

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};

        for (int stone : stones) {
            cnt[stone % 3]++;
        }

        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        return abs(cnt[1] - cnt[2]) > 2;
    }
};