/*
  LeetCode Submission ID: 2090071481
  Date: 01/08/2026, 22:06:56
  Runtime: 2 ms
  Memory: 9.4 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/contest/biweekly-contest-188/problems/count-valid-prefixes/submissions/2090071481/
*/

class Solution {
public:
    int countValidPrefixes(string s) {
        int z = 0;
        int o = 0;
        int res = 0;
        for(char c : s) {
            if(c == '0')
                z++;
            else
                o++;
            if(abs(z - o) <= 1)
                res++;
        }
        return res;
    }
};