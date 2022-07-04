/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        dfs(node);
        for (auto [s, d]: hash)
            for (auto ver: s->neighbors)
                d->neighbors.push_back(hash[ver]);
        return hash[node];
    }

    void dfs(Node* node) {
        hash[node] = new Node(node->val);
        for (auto ver: node->neighbors)
            if (hash.count(ver) == 0)
                dfs(ver);
    }
private:
    unordered_map<Node*, Node*> hash;
};
// @lc code=end

