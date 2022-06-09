/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* curr = head;
       int size = 0;
       while (curr) curr = curr->next, size++;
       if (n == size) return head->next;
       int idx = size - n;
       curr = head;
       while (--idx) curr = curr->next;
       curr->next = curr->next->next;
       return head;
    }
};
// @lc code=end

