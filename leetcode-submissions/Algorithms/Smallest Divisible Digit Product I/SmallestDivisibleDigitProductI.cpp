/*
  LeetCode Submission ID: 2096452534
  Date: 06/08/2026, 14:55:33
  Runtime: 0 ms
  Memory: 8.7 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/smallest-divisible-digit-product-i/submissions/2096452534/?envType=daily-question&envId=2026-08-06
*/

class Solution {
    int multi(int n) {
        int res = 1;
        while(n > 0) {
            res *= (n%10);
            n /= 10;
        }
        return res;
    }
public:
    int smallestNumber(int n, int t) {
        for(int i = n; i < 101; i++) {
            if(multi(i) % t == 0)
                return i;
        }
        return -1;
    }
};