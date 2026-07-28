/*
  LeetCode Submission ID: 2085387675
  Date: 29/07/2026, 04:21:15
  Runtime: 0 ms
  Memory: 26.4 MB
  Difficulty: Medium
  Problem Link: https://leetcode.com/problems/set-mismatch/submissions/2085387675/?envType=problem-list-v2&envId=dsa-linear-shoal-array-ii
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);

        for (int num : nums) {
            freq[num]++;
        }

        int duplicate = -1;
        int missing = -1;

        for (int i = 1; i <= n; i++) {
            if (freq[i] == 2)
                duplicate = i;
            else if (freq[i] == 0)
                missing = i;
        }

        return {duplicate, missing};
    }
};