/*
 * @lc app=leetcode id=99 lang=golang
 *
 * [99] Recover Binary Search Tree
 *
 * https://leetcode.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Medium (57.18%)
 * Likes:    8481
 * Dislikes: 284
 * Total Accepted:    611.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * You are given the root of a binary search tree (BST), where the values of
 * exactly two nodes of the tree were swapped by mistake. Recover the tree
 * without changing its structure.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,3,null,null,2]
 * Output: [3,1,null,null,2]
 * Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3
 * makes the BST valid.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [3,1,4,null,null,2]
 * Output: [2,1,4,null,null,3]
 * Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2
 * and 3 makes the BST valid.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [2, 1000].
 * -2^31 <= Node.val <= 2^31 - 1
 *
 *
 *
 * Follow up: A solution using O(n) space is pretty straight-forward. Could you
 * devise a constant O(1) space solution?
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

func recoverTree(root *TreeNode) {
	_, _ = inorderTraverseWithNodeValue(root)
}

// return abnormal node
func inorderTraverseWithNodeValue(root *TreeNode) (*TreeNode, *TreeNode) {
	if root == nil {
		return nil, nil
	}

	// keep root as the max of left tree
	leftMin, leftMax := inorderTraverseWithNodeValue(root.Left)
	if leftMax != nil && leftMax.Val > root.Val {
		temp := leftMax.Val
		leftMax.Val = root.Val
		root.Val = temp
	}

	// keep the root as the min of right tree
	rightMin, rightMax := inorderTraverseWithNodeValue(root.Right)
	if rightMin != nil && rightMin.Val < root.Val {
		temp := rightMin.Val
		rightMin.Val = root.Val
		root.Val = temp
	}

	return leftMin, rightMax
}

// @lc code=end
