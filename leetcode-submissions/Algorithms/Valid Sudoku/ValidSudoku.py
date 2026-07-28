# LeetCode Submission ID: 1122572983
# Date: 29/07/2026, 04:58:33
# Runtime: 106 ms
# Memory: 16.4 MB
# Difficulty: Medium
# Problem Link: https://leetcode.com/problems/valid-sudoku/submissions/1122572983/

import collections

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        col = defaultdict(set)
        row = defaultdict(set)
        sq = defaultdict(set)

        for c in range(9):
            for r in range(9):  
                if board[c][r] == '.':
                    continue
                elif board[c][r] in col[c] or board[c][r] in row[r] or board[c][r] in sq[(c//3, r//3)]:
                    return False
                else:
                    col[c].add(board[c][r])
                    row[r].add(board[c][r])
                    sq[(c//3, r//3)].add(board[c][r])
        return True