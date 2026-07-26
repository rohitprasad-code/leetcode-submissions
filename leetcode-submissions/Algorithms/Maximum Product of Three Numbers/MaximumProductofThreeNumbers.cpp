/*
  LeetCode Submission ID: 2081340055
  Date: 26/07/2026, 08:03:51
  Runtime: 7 ms
  Memory: 31.5 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/maximum-product-of-three-numbers/submissions/2081340055/?envType=daily-question&envId=2026-07-26
*/

class Solution {
public:
    int maximumProduct(vector<int>& A) {
        ranges::sort(A);
        int n = A.size();
        
        return max(
            A.back() * A[n - 2] * A[n - 3],
            A.back() * A.front() * A[1]
        );
    }
};