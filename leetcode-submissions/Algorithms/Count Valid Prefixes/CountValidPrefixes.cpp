/*
  LeetCode Submission ID: 2090523050
  Date: 02/08/2026, 01:17:47
  Runtime: 0 ms
  Memory: 9.6 MB
  Difficulty: Medium
  Problem Link: https://leetcode.com/problems/count-valid-prefixes/submissions/2090523050/
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