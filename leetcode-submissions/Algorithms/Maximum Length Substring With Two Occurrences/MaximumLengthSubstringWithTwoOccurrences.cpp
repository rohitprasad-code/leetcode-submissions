/*
  LeetCode Submission ID: 2106058667
  Date: 14/08/2026, 07:41:02
  Runtime: 5 ms
  Memory: 9.5 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/?envType=daily-question&envId=2026-08-14
*/

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> mp;
        int left = 0;
        int res = 0;
        for (int right = 0; right < s.length(); ++right) {
            mp[s[right]]++;
            while (mp[s[right]] > 2) {
                mp[s[left]]--;
                ++left;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};