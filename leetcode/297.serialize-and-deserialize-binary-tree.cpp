#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (!root)
      return "null";
    return to_string(root->val) + "," + serialize(root->left) + "," +
           serialize(root->right);
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    if (data == "null")
      return nullptr;
    stringstream s(data);
    return makeDeserialize(s);
  }

  TreeNode *makeDeserialize(stringstream &s) {
    string str;
    getline(s, str, ',');
    if (str == "null") {
      return nullptr;
    } else {
      TreeNode *root = new TreeNode(stoi(str));
      root->left = makeDeserialize(s);
      root->right = makeDeserialize(s);
      return root;
    }
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
