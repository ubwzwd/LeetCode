/*
 * @lc app=leetcode id=112 lang=golang
 *
 * [112] Path Sum
 */
package main

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func hasPathSum(root *TreeNode, targetSum int) bool {
	if root == nil {
		return false
	}
	remainingSum := targetSum - root.Val
	if remainingSum == 0 && root.Left == nil && root.Right == nil {
		return true
	}
	return hasPathSum(root.Left, remainingSum) || hasPathSum(root.Right, remainingSum)
}

// @lc code=end
