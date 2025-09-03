/*
 * @lc app=leetcode id=968 lang=golang
 *
 * [968] Binary Tree Cameras
 *
 * https://leetcode.com/problems/binary-tree-cameras/description/
 *
 * algorithms
 * Hard (47.37%)
 * Likes:    5563
 * Dislikes: 87
 * Total Accepted:    171.7K
 * Total Submissions: 362.4K
 * Testcase Example:  '[0,0,null,0,0]'
 *
 * You are given the root of a binary tree. We install cameras on the tree
 * nodes where each camera at a node can monitor its parent, itself, and its
 * immediate children.
 *
 * Return the minimum number of cameras needed to monitor all nodes of the
 * tree.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [0,0,null,0,0]
 * Output: 1
 * Explanation: One camera is enough to monitor all nodes if placed as shown.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [0,0,null,0,null,0,null,null,0]
 * Output: 2
 * Explanation: At least two cameras are needed to monitor all nodes of the
 * tree. The above image shows one of the valid configurations of camera
 * placement.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 1000].
 * Node.val == 0
 *
 *
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
func minCameraCover(root *TreeNode) int {
	ans := 0
	var dfs func(*TreeNode) int
	dfs = func(node *TreeNode) int {
		// 1: this node has camera
		// 2: this node is covered by child
		// 3: this node is covered by parent
		if node == nil {
			return 2
		}

		leftCoverStatus := dfs(node.Left)
		rightCoverStatus := dfs(node.Right)

		// if both children are covered by child, current node can be covered by parent
		if leftCoverStatus == 2 && rightCoverStatus == 2 {
			return 3
		}
		// if any child covered by parent, current node should have camera
		if leftCoverStatus == 3 || rightCoverStatus == 3 {
			ans++
			return 1
		}
		// if any child has camera, and no child need to be covered by parent, it's covered by child
		// if leftCoverStatus == 1 || rightCoverStatus == 1
		return 2
	}
	if dfs(root) == 3 {
		ans++
	}
	return ans
}

// @lc code=end
