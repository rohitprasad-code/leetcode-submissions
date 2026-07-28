/*
  LeetCode Submission ID: 2085384594
  Date: 29/07/2026, 04:16:01
  Runtime: 0 ms
  Memory: 26.3 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/set-mismatch/
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