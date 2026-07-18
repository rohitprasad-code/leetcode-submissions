/*
  LeetCode Submission ID: 2072129816
  Date: 18/07/2026, 16:38:49
  Runtime: 0 ms
  Memory: 16.3 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/find-greatest-common-divisor-of-array/submissions/2072129816/?envType=daily-question&envId=2026-07-18
*/

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(auto num : nums) {
            mini = min(mini, num);
            maxi = max(maxi, num);
        }
        return __gcd(mini, maxi);
    }
};