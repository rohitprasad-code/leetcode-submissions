/*
  LeetCode Submission ID: 1661175945
  Date: 29/07/2026, 04:59:05
  Runtime: 3 ms
  Memory: 10.4 MB
  Difficulty: Medium
  Problem Link: https://leetcode.com/problems/subsets-ii/submissions/1661175945/
*/

class Solution {
    void helper(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &res) {
        res.push_back(ds);
        for(int i = ind; i < nums.size(); i++) {
            if(i != ind && nums[i] == nums[i-1])
                continue;
            ds.push_back(nums[i]);
            helper(i+1, nums, ds, res);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ds;
        vector<vector<int>> res;
        helper(0, nums, ds, res);
        return res;
    }
};