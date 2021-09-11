package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

/*
 * @lc app=leetcode id=105 lang=golang
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
/**
 * preorder = [3,9,20,15,7]
 * inorder  = [9,3,15,20,7]
 * root: 3 left_tree:[9] right_tree:[15,20,7]
 */
func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	}
	root := &TreeNode{preorder[0], nil, nil}
	mid := 0
	for ; mid < len(inorder); mid++ {
		if inorder[mid] == preorder[0] {
			break
		}
	}
	root.Left = buildTree(preorder[1:len(inorder[:mid])+1], inorder[:mid])
	root.Right = buildTree(preorder[len(inorder[:mid])+1:], inorder[mid+1:])
	return root
}

// @lc code=end
