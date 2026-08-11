/*
  LeetCode Submission ID: 2102696189
  Date: 11/08/2026, 16:02:19
  Runtime: 3 ms
  Memory: 23.1 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/submissions/2102696189/?envType=daily-question&envId=2026-08-11
*/

class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> num_set(nums.begin(), nums.end());
        int total = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                total += nums[i];
            } else {
                break;
            }
        }

        while (num_set.count(total)) {
            total += 1;
        }

        return total;
    }
};