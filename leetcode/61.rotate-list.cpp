/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode* curr = head;
        int cnt = 1;
        while (curr && curr->next) {
            cnt++;
            curr = curr->next;
        }
        curr->next = head;
        int i = k % cnt;

        curr = head;
        int j = cnt - i - 1;
        while (j--)
            curr = curr->next;
    
        ListNode* newHead = curr->next;
        
        curr->next = nullptr;
        return newHead;
    }
};
// @lc code=end

