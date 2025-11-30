/*
 * @lc app=leetcode id=24 lang=golang
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (67.75%)
 * Likes:    12742
 * Dislikes: 495
 * Total Accepted:    1.7M
 * Total Submissions: 2.5M
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head. You
 * must solve the problem without modifying the values in the list's nodes
 * (i.e., only nodes themselves may be changed.)
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4]
 *
 * Output: [2,1,4,3]
 *
 * Explanation:
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: head = []
 *
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1]
 *
 * Output: [1]
 *
 *
 * Example 4:
 *
 *
 * Input: head = [1,2,3]
 *
 * Output: [2,1,3]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 100].
 * 0 <= Node.val <= 100
 *
 *
 */
package main

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	var header, headNode, firstNode, secondNode *ListNode
	headNode = &ListNode{Val: 0}
	header = headNode
	headNode.Next = head
	firstNode = head
	secondNode = head.Next
	for firstNode != nil && secondNode != nil {
		headNode.Next = secondNode
		firstNode.Next = secondNode.Next
		secondNode.Next = firstNode

		headNode = firstNode
		firstNode = firstNode.Next
		if firstNode != nil {
			secondNode = firstNode.Next
		} else {
			secondNode = nil
		}
	}
	return header.Next
}

// @lc code=end
