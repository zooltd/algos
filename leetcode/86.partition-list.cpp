/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *before = new ListNode();
        ListNode *after = new ListNode();
        ListNode *pb = before, *pa = after;
        for (ListNode *p = head; p; p = p->next) {
            if (p->val < x) {
                pb->next = p;
                pb = p;
            } else {
                pa->next = p;
                pa = p;
            }
        }
        pb->next = after->next;
        pa->next = nullptr;

        return before->next;
    }
};
// @lc code=end

