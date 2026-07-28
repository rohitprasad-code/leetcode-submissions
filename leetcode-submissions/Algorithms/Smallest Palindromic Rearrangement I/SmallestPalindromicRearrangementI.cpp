/*
  LeetCode Submission ID: 2084858749
  Date: 28/07/2026, 19:41:37
  Runtime: 82 ms
  Memory: 53.9 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/submissions/2084858749/?envType=daily-question&envId=2026-07-28
*/

class Solution {
public:
    string smallestPalindrome(string s) {
        int len = s.length();
        int partition = len / 2;

        sort(s.begin(), s.begin() + partition);

        for (int i = 0; i < partition; ++i) {
            s[len - 1 - i] = s[i];
        }

        return s;
    }
};