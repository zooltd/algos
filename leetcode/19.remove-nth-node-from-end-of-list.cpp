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
    /**
    * @brief https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0019.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9.md
    */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* slow, * fast;
        slow = fast = dummy;
        while (n-- && fast)
            fast = fast->next;
        if (!fast) return head;
        fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};

class Solution2 {
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

