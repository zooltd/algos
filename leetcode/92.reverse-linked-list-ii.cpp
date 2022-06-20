/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        for (int i = 0; i < left - 1; i++) prev = prev->next;

        ListNode* pa = prev->next;
        ListNode* pb = pa->next;
        for (int i = left; i < right; i++) {
            ListNode* tmp = pb->next;
            pb->next = pa;
            pa = pb, pb = tmp;
        }

        prev->next->next = pb;
        prev->next = pa;

        return dummy->next;
    }
};
// @lc code=end

