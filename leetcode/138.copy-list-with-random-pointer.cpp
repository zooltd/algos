/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node* n_curr = dummy;
        
        for (Node* o_curr = head; o_curr; o_curr = o_curr->next) {
            n_curr->next = new Node(o_curr->val);
            n_curr = n_curr->next;
            mp[o_curr] = n_curr;
        }

        for (Node* o_curr = head; o_curr; o_curr = o_curr->next) {
            if (o_curr->random)
                mp[o_curr]->random = mp[o_curr->random];
        }

        return dummy->next;
    }

private:
    unordered_map<Node*, Node*> mp;
};
// @lc code=end

