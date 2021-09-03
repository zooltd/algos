#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    return mergeSort(lists, 0, lists.size() - 1);
  }

  ListNode *mergeSort(vector<ListNode *> &lists, int l, int r) {
    if (l == r)
      return lists[l];
    if (l > r)
      return nullptr;
    int mid = (l + r) / 2;
    return merge(mergeSort(lists, l, mid), mergeSort(lists, mid + 1, r));
  }

  ListNode *merge(ListNode *n1, ListNode *n2) {
    ListNode dummy;
    ListNode *tail = &dummy;
    while (n1 && n2) {
      ListNode *&node = n1->val < n2->val ? n1 : n2;
      tail = tail->next = node;
      node = node->next;
    }
    tail->next = n1 ? n1 : n2;
    return dummy.next;
  }
};
// @lc code=end
