/*
  LeetCode Submission ID: 2081338852
  Date: 26/07/2026, 08:02:58
  Runtime: 0 ms
  Memory: 31.5 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/maximum-product-of-three-numbers/submissions/2081338852/?envType=daily-question&envId=2026-07-26
*/

class Solution {
public:
    int maximumProduct(vector<int>& A) {
        int a = -1001, b = a, c = b;    // max 3
        int x =  1001, y = x;           // min 2

        for (auto& n : A) {
            int pa = a, pb = b, px = x;

            a = max(a, n);
            b = max(b, min(pa, n));
            c = max(c, min(pb, n));

            x = min(x, n);
            y = min(y, max(px, n));
        }

        return max(a * b * c, a * x * y);
    }
};