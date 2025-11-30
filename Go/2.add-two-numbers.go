/*
 * @lc app=leetcode id=2 lang=golang
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (46.77%)
 * Likes:    34747
 * Dislikes: 6953
 * Total Accepted:    6.2M
 * Total Submissions: 13.2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 *
 * Example 1:
 *
 *
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 *
 *
 * Example 2:
 *
 *
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 *
 * Example 3:
 *
 *
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
 *
 *
 */
package main

type ListNode struct {
	Val  int
	Next *ListNode
}

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	return helperIteration(l1, l2)
}

// recursion
func helper(l1, l2 *ListNode, extra bool) *ListNode {
	if l1 == nil && l2 == nil && !extra {
		return nil
	}
	val := 0
	nextExtra := false
	var nextL1, nextL2 *ListNode
	if l1 != nil {
		val += l1.Val
		nextL1 = l1.Next
	}
	if l2 != nil {
		val += l2.Val
		nextL2 = l2.Next
	}
	if extra {
		val++
	}
	if val >= 10 {
		val -= 10
		nextExtra = true
	}
	curNode := &ListNode{Val: val}
	curNode.Next = helper(nextL1, nextL2, nextExtra)
	return curNode
}

// iteration
func helperIteration(l1, l2 *ListNode) *ListNode {
	var header, curNode *ListNode
	extra := false
	header = &ListNode{Val: 0}
	curNode = header
	for l1 != nil || l2 != nil || extra {
		val := 0
		if l1 != nil {
			val += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			val += l2.Val
			l2 = l2.Next
		}
		if extra {
			val++
			extra = false
		}
		if val >= 10 {
			val -= 10
			extra = true
		}
		curNode.Next = &ListNode{Val: val}
		curNode = curNode.Next
	}
	return header.Next
}

// @lc code=end
