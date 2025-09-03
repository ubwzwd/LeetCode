/*
 * @lc app=leetcode id=508 lang=golang
 *
 * [508] Most Frequent Subtree Sum
 *
 * https://leetcode.com/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (68.20%)
 * Likes:    2341
 * Dislikes: 326
 * Total Accepted:    164.5K
 * Total Submissions: 241.1K
 * Testcase Example:  '[5,2,-3]'
 *
 * Given the root of a binary tree, return the most frequent subtree sum. If
 * there is a tie, return all the values with the highest frequency in any
 * order.
 *
 * The subtree sum of a node is defined as the sum of all the node values
 * formed by the subtree rooted at that node (including the node itself).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,2,-3]
 * Output: [2,-3,4]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,2,-5]
 * Output: [2]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^5 <= Node.val <= 10^5
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
func findFrequentTreeSum(root *TreeNode) []int {
	sumMap := make(map[int]int) // map sum:frequency
	_ = recurHelper(root, sumMap)

	// finx max freq
	maxFreq := 0
	for _, v := range sumMap {
		if v > maxFreq {
			maxFreq = v
		}
	}

	// find all the sums with maxFreq
	var result []int
	for k, v := range sumMap {
		if v == maxFreq {
			result = append(result, k)
		}
	}
	return result
}

func recurHelper(node *TreeNode, sumMap map[int]int) int {
	if node == nil {
		return 0
	}
	leftSum := recurHelper(node.Left, sumMap)
	rightSum := recurHelper(node.Right, sumMap)
	curSum := leftSum + rightSum + node.Val
	if _, ok := sumMap[curSum]; ok {
		sumMap[curSum]++
	} else {
		sumMap[curSum] = 1
	}
	return curSum
}

// @lc code=end
