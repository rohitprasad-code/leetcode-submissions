/*
  LeetCode Submission ID: 2114225224
  Date: 20/08/2026, 22:40:49
  Runtime: 2 ms
  Memory: 23.7 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/distribute-elements-into-two-arrays-i/description/?envType=daily-question&envId=2026-08-20
*/

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for (int i = 2; i < n; i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};