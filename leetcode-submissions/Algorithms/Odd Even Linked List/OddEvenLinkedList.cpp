/*
  LeetCode Submission ID: 2085398377
  Date: 29/07/2026, 05:01:19
  Runtime: 0 ms
  Memory: 15.6 MB
  Difficulty: Medium
  Problem Link: https://leetcode.com/problems/odd-even-linked-list/submissions/2085398377/
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
        if(head == NULL || head->next == NULL) return head;

        ListNode* odd = head; // 1st odd node
        ListNode* even = head->next; // 1st even node
        ListNode* evenHead = even; // save head of even list

        while(even != NULL && even->next != NULL) {
            odd->next = even->next; // connect curr odd to next odd node
            odd = odd->next;

            even->next = odd->next; // connect curr even to next even node
            even = even->next;
        }
        odd->next = evenHead; // attach even list after odd list
        return head;
    }
};