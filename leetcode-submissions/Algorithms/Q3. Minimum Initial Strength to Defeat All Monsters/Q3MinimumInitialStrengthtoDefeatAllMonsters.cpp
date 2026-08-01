/*
  LeetCode Submission ID: 2090239774
  Date: 01/08/2026, 23:17:58
  Runtime: 3 ms
  Memory: 247.9 MB
  Difficulty: Medium
  Problem Link: https://leetcode.com/contest/biweekly-contest-188/problems/minimum-initial-strength-to-defeat-all-monsters/submissions/2090239774/
*/

class Solution {
public:
    long long minInitialStrength(vector<int>& ms, vector<vector<int>>& bs) {
        int n = ms.size();
        vector<long long> diff(n + 1, 0);
        for(auto &b : bs) {
            diff[b[0]] += b[2];
            if(b[1] + 1 < n)
                diff[b[1] + 1] -= b[2];
        }
        vector<long long> bonus(n);
        long long cur = 0;
        for(int i = 0; i < n; i++) {
            cur += diff[i];
            bonus[i] = cur;
        }
        long long res = 0;
        long long pre = 0;
        for(int i = 0; i < n; i++) {
            if(bonus[i] < ms[i]) {
                res = max(res, pre + (long long) ms[i] - bonus[i]);
            }
            pre += ms[i];
        }
        return res;
    }
};