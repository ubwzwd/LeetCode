/*
 * @lc app=leetcode id=235 lang=golang
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
 *
 * algorithms
 * Medium (68.96%)
 * Likes:    11909
 * Dislikes: 345
 * Total Accepted:    2M
 * Total Submissions: 2.9M
 * Testcase Example:  '[6,2,8,0,4,7,9,null,null,3,5]\n2\n8'
 *
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) node
 * of two given nodes in the BST.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of
 * itself).”
 *
 *
 * Example 1:
 *
 *
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * Output: 6
 * Explanation: The LCA of nodes 2 and 8 is 6.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * Output: 2
 * Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant
 * of itself according to the LCA definition.
 *
 *
 * Example 3:
 *
 *
 * Input: root = [2,1], p = 2, q = 1
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [2, 10^5].
 * -10^9 <= Node.val <= 10^9
 * All Node.val are unique.
 * p != q
 * p and q will exist in the BST.
 *
 *
 */
package main

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val   int
 *     Left  *TreeNode
 *     Right *TreeNode
 * }
 */

// recursive way
// func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
// 	if root == nil || root == p || root == q {
// 		return root
// 	}

// 	if (p.Val < root.Val && q.Val > root.Val) || (p.Val > root.Val && q.Val < root.Val) {
// 		return root
// 	}

// 	var left, right *TreeNode
// 	if p.Val < root.Val || q.Val < root.Val {
// 		left = lowestCommonAncestor(root.Left, p, q)
// 	}
// 	if p.Val > root.Val || q.Val > root.Val {
// 		right = lowestCommonAncestor(root.Right, p, q)
// 	}

// 	if left != nil && right != nil {
// 		return root
// 	}
// 	if left != nil {
// 		return left
// 	}
// 	return right
// }

// iterative way
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	current := root
	for current != nil {
		if p.Val < current.Val && q.Val < current.Val {
			current = current.Left
		} else if p.Val > current.Val && q.Val > current.Val {
			current = current.Right
		} else {
			return current
		}
	}
	return nil
}

// @lc code=end
