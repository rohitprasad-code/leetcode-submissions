/*
  LeetCode Submission ID: 921484177
  Date: 29/07/2026, 05:01:29
  Runtime: 11 ms
  Memory: 10.5 MB
  Difficulty: Medium
  Problem Link: https://leetcode.com/problems/odd-even-linked-list/submissions/921484177/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }

        ListNode * oddPosition = head;
        ListNode * oddHead = oddPosition;

        ListNode * evenPosition = head->next;
        ListNode * evenHead = evenPosition;

        while (evenPosition && evenPosition->next) {
            oddPosition->next = oddPosition->next->next;
            evenPosition->next = evenPosition->next->next;

            oddPosition = oddPosition->next;
            evenPosition = evenPosition->next;
        }

        oddPosition->next = evenHead;

        return oddHead;
    }
};