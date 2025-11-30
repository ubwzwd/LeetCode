/*
 * @lc app=leetcode id=148 lang=golang
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (62.56%)
 * Likes:    12628
 * Dislikes: 401
 * Total Accepted:    1.1M
 * Total Submissions: 1.8M
 * Testcase Example:  '[4,2,1,3]'
 *
 * Given the head of a linked list, return the list after sorting it in
 * ascending order.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [4,2,1,3]
 * Output: [1,2,3,4]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [-1,5,3,4,0]
 * Output: [-1,0,3,4,5]
 *
 *
 * Example 3:
 *
 *
 * Input: head = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 5 * 10^4].
 * -10^5 <= Node.val <= 10^5
 *
 *
 *
 * Follow up: Can you sort the linked list in O(n logn) time and O(1) memory
 * (i.e. constant space)?
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
func sortList(head *ListNode) *ListNode {
	// merge sort
	return mergeSortLinkedList(head)
}

func mergeSortLinkedList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	// find mid
	slow, fast := head, head.Next
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}
	mid := slow.Next
	slow.Next = nil

	leftHead := mergeSortLinkedList(head)
	rightHead := mergeSortLinkedList(mid)

	dummyHead := &ListNode{}
	prev := dummyHead
	for leftHead != nil || rightHead != nil {
		// put right
		if leftHead == nil || (rightHead != nil && rightHead.Val < leftHead.Val) {
			prev.Next = rightHead
			rightHead = rightHead.Next
		} else {
			prev.Next = leftHead
			leftHead = leftHead.Next
		}
		prev = prev.Next
	}
	return dummyHead.Next
}

// @lc code=end
