/*
  LeetCode Submission ID: 2073770011
  Date: 19/07/2026, 23:15:58
  Runtime: 2 ms
  Memory: 8.7 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/submissions/2073770011/?envType=daily-question&envId=2026-07-19
*/

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> vis(26), num(26);
        for (char ch : s) {
            num[ch - 'a']++;
        }

        string stk;
        for (char ch : s) {
            if (!vis[ch - 'a']) {
                while (!stk.empty() && stk.back() > ch) {
                    if (num[stk.back() - 'a'] > 0) {
                        vis[stk.back() - 'a'] = 0;
                        stk.pop_back();
                    } else {
                        break;
                    }
                }
                vis[ch - 'a'] = 1;
                stk.push_back(ch);
            }
            num[ch - 'a'] -= 1;
        }
        return stk;
    }
};
