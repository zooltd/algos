package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

/**
 * inorder =   [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * root: 3 left: [9] right: [15,20,7]
 */

/*
 * @lc app=leetcode id=106 lang=golang
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
func buildTree(inorder []int, postorder []int) *TreeNode {
	if len(postorder) == 0 {
		return nil
	}
	root := &TreeNode{postorder[len(postorder)-1], nil, nil}
	mid := 0
	for ; mid < len(inorder); mid++ {
		if inorder[mid] == root.Val {
			break
		}
	}
	root.Left = buildTree(inorder[:mid], postorder[:mid])
	root.Right = buildTree(inorder[mid+1:], postorder[mid:len(postorder)-1])
	return root
}

// @lc code=end
