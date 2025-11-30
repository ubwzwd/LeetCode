/*
 * @lc app=leetcode id=23 lang=golang
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (57.46%)
 * Likes:    20738
 * Dislikes: 769
 * Total Accepted:    2.7M
 * Total Submissions: 4.6M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * You are given an array of k linked-lists lists, each linked-list is sorted
 * in ascending order.
 *
 * Merge all the linked-lists into one sorted linked-list and return it.
 *
 *
 * Example 1:
 *
 *
 * Input: lists = [[1,4,5],[1,3,4],[2,6]]
 * Output: [1,1,2,3,4,4,5,6]
 * Explanation: The linked-lists are:
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * merging them into one sorted linked list:
 * 1->1->2->3->4->4->5->6
 *
 *
 * Example 2:
 *
 *
 * Input: lists = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: lists = [[]]
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] is sorted in ascending order.
 * The sum of lists[i].length will not exceed 10^4.
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
func mergeKLists(lists []*ListNode) *ListNode {
	return nil
}

type Heap interface {
	Pop() any
	Push(T any) bool
}

type minHeap[T any] struct {
	data      []T
	firstLess func(a, b T) bool
}

func (h *minHeap[T]) len() int {
	return len(h.data)
}

func (h *minHeap[T]) Pop() T {
	if h.len() == 0 {
		var zero T
		return zero
	}
	result := h.data[0]
	lastIndex := h.len() - 1
	h.data[0] = h.data[lastIndex]
	h.data = h.data[:lastIndex]

	// now shift the heap top down
	currentIndex := 0
	for 2*currentIndex+1 < h.len() {
		// if new head is greater than it's child, swap
		leftIndex := 2*currentIndex + 1
		rightIndex := leftIndex + 1
		if h.firstLess(h.data[leftIndex], h.data[currentIndex]) {
			temp := h.data[leftIndex]
			h.data[leftIndex] = h.data[currentIndex]
			h.data[currentIndex] = temp
			currentIndex = leftIndex
		} else if rightIndex < h.len() && h.firstLess(h.data[rightIndex], h.data[currentIndex]) {
			temp := h.data[rightIndex]
			h.data[rightIndex] = h.data[currentIndex]
			h.data[currentIndex] = temp
			currentIndex = rightIndex
		} else {
			break
		}
	}

	return result
}

func (h *minHeap[T]) Push(newEle T) bool {
	// push it into the last position
	h.data = append(h.data, newEle)

	curIdx := h.len() - 1
	for curIdx > 0 {
		// find parent index
		parentIdx := (curIdx - 1) / 2
		// if parent is greater, pop it up
		if h.firstLess(h.data[curIdx], h.data[parentIdx]) {
			temp := h.data[curIdx]
			h.data[curIdx] = h.data[parentIdx]
			h.data[parentIdx] = temp
			curIdx = parentIdx
		} else {
			break
		}
	}
	return true
}

// @lc code=end
