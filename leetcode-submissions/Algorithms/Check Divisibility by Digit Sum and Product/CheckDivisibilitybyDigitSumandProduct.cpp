/*
  LeetCode Submission ID: 2115641062
  Date: 22/08/2026, 08:59:28
  Runtime: 0 ms
  Memory: 7.9 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/submissions/2115641062/?envType=daily-question&envId=2026-08-22
*/

class Solution {
public:
    bool checkDivisibility(int n) {
        int c = n, s = 0, m = 1;
        while(n) {
            int d = n % 10;
            s += d;
            m *= d;
            n /= 10;
        }
        return ((c % (s + m)) == 0);
    }
};