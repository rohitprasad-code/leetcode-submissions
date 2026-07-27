/*
  LeetCode Submission ID: 2083281518
  Date: 27/07/2026, 17:04:38
  Runtime: 0 ms
  Memory: 13.3 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/submissions/2083281518/?envType=daily-question&envId=2026-07-27
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int biggest = 0;
        int secondBiggest = 0;
        for (int num : nums) {
            if (num > biggest) {
                secondBiggest = biggest;
                biggest = num;
            } else {
                secondBiggest = max(secondBiggest, num);
            }
        }
        
        return (biggest - 1) * (secondBiggest - 1);
    }
};