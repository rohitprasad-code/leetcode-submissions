/*
  LeetCode Submission ID: 2070425097
  Date: 17/07/2026, 03:18:08
  Runtime: 7 ms
  Memory: 8.3 MB
  Difficulty: Medium
  Problem Link: https://leetcode.com/problems/closest-divisors/submissions/2070425097/
*/

class Solution {
private:
    vector<int> closestPair(int target) {
        for (int divisor = static_cast<int>(sqrt(target)); divisor >= 1; --divisor) {
            if (target % divisor == 0) {
                return {divisor, target / divisor};
            }
        }

        return {};
    }

public:
    vector<int> closestDivisors(int num) {
        vector<int> first = closestPair(num + 1);
        vector<int> second = closestPair(num + 2);

        int firstDifference = abs(first[0] - first[1]);
        int secondDifference = abs(second[0] - second[1]);

        return firstDifference <= secondDifference ? first : second;
    }
};