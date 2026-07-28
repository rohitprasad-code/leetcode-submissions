/*
  LeetCode Submission ID: 2085395318
  Date: 29/07/2026, 04:50:24
  Runtime: 3 ms
  Memory: 14.9 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/submissions/2085395318/?envType=problem-list-v2&envId=dsa-linear-shoal-array-ii
*/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> mp;

        // Store first occurrence of each number
        for (int i = 0; i < sorted.size(); i++) {
            if (mp.find(sorted[i]) == mp.end()) {
                mp[sorted[i]] = i;
            }
        }

        vector<int> ans;

        for (int num : nums) {
            ans.push_back(mp[num]);
        }

        return ans;
    }
};