/*
  LeetCode Submission ID: 713730793
  Date: 29/07/2026, 04:58:38
  Runtime: 39 ms
  Memory: 18 MB
  Difficulty: Medium
  Problem Link: https://leetcode.com/problems/valid-sudoku/submissions/713730793/
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowCheck[9][9] = {0}, columnCheck[9][9] = {0}, boxCheck[9][9] = {0};
        
        int out = board.size();
        int in = board[0].size();

        for (int i = 0; i < out; i++) {
            for (int j = 0; j < in; j++) {
                 if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if (rowCheck[i][num] || columnCheck[j][num] || boxCheck[k][num]) {
                        return false;
                    }
                    rowCheck[i][num] = columnCheck[j][num] = boxCheck[k][num] = 1;
                }
            }
        }
        return true;
    }
};
