/*
 * @lc app=leetcode id=94 lang=golang
 *
 * [94] Binary Tree Inorder Traversal
 */
package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// recursion ver
// func inorderTraversal(root *TreeNode) []int {
// 	if root == nil {
// 		return []int{}
// 	}

// 	result := inorderTraversal(root.Left)
// 	result = append(result, root.Val)
// 	return append(result, inorderTraversal(root.Right)...)
// }

// iterration ver
func inorderTraversal(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}
	result := make([]int, 0, 100)
	stack := make([]*TreeNode, 100)
	cur := root

	// init stack
	topIndex := -1

	for cur != nil || topIndex >= 0 {
		for cur != nil {
			topIndex += 1
			stack[topIndex] = cur
			cur = cur.Left
		}

		cur = stack[topIndex]
		result = append(result, cur.Val)
		topIndex -= 1

		cur = cur.Right
	}
	return result
}

// @lc code=end
