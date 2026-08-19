/*
  LeetCode Submission ID: 2112414989
  Date: 19/08/2026, 13:29:21
  Runtime: 127 ms
  Memory: 116.1 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/cinema-seat-allocation/submissions/2112414989/?envType=daily-question&envId=2026-08-19
*/

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> rows;
        
        for (auto &seat : reservedSeats) {
            rows[seat[0]].insert(seat[1]);
        }

        int ans = (n - rows.size()) * 2;

        for (auto [row, seats] : rows) {
            bool left = true, middle = true, right = true;

            for (int i = 2; i <= 5; i++) {
                if (seats.count(i)) left = false;
            }

            for (int i = 4; i <= 7; i++) {
                if (seats.count(i)) middle = false;
            }

            for (int i = 6; i <= 9; i++) {
                if (seats.count(i)) right = false;
            }

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};