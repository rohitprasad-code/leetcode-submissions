/*
  LeetCode Submission ID: 2093275207
  Date: 04/08/2026, 05:58:43
  Runtime: 4 ms
  Memory: 32.3 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/find-missing-elements/submissions/2093275207/?envType=daily-question&envId=2026-08-04
*/

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> res;
        for (int i = 0; i < n - 1; i++) {
            for (int j = nums[i] + 1; j < nums[i + 1]; j++) {
                res.push_back(j);
            }
        }
        return res;
    }
};