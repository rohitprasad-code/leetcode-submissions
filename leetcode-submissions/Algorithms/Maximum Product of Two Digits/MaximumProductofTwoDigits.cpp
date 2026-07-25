/*
  LeetCode Submission ID: 2080142087
  Date: 25/07/2026, 06:42:27
  Runtime: 0 ms
  Memory: 8.4 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/maximum-product-of-two-digits/submissions/2080142087/?envType=daily-question&envId=2026-07-25
*/

class Solution {
public:
    int maxProduct(int n) {
        int first = 0, second = 0;
        while (n > 0) {
            int x = n % 10;
            if (x > first) {
                second = first;
                first = x;
            } else if (x > second) {
                second = x;
            }
            n /= 10;
        }
        return first * second;
    }
};