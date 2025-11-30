/*
 * @lc app=leetcode id=315 lang=golang
 *
 * [315] Count of Smaller Numbers After Self
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (42.97%)
 * Likes:    9114
 * Dislikes: 249
 * Total Accepted:    365.8K
 * Total Submissions: 850.9K
 * Testcase Example:  '[5,2,6,1]'
 *
 * Given an integer array nums, return an integer array counts where counts[i]
 * is the number of smaller elements to the right of nums[i].
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [5,2,6,1]
 * Output: [2,1,1,0]
 * Explanation:
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-1]
 * Output: [0]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [-1,-1]
 * Output: [0,0]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */
package main

// @lc code=start
func countSmaller(nums []int) []int {
	return countSmallerMergeSortVer(nums)
}

func countSmallerMergeSortVer(nums []int) []int {
	index := make([]int, len(nums))
	tempIndex := make([]int, len(nums))
	result := make([]int, len(nums))
	for i := range len(nums) {
		index[i] = i
		tempIndex[i] = i
	}
	mergeSortWithCount(nums, index, tempIndex, result, 0, len(nums)-1)
	return result
}

// process [left, right] part
func mergeSortWithCount(nums, index, tempIndex, results []int, left, right int) {
	if left >= right {
		return
	}

	mid := (right-left)/2 + left
	mergeSortWithCount(nums, index, tempIndex, results, left, mid)
	mergeSortWithCount(nums, index, tempIndex, results, mid+1, right)

	// what to do here?
	leftStart, rightStart, indexStart := left, mid+1, left
	for leftStart <= mid || rightStart <= right {
		if rightStart > right || (leftStart <= mid && (nums[index[leftStart]] <= nums[index[rightStart]])) {
			// if the element in the left part is smaller, move to the next
			tempIndex[indexStart] = index[leftStart]
			// meaning all the elements before the current right element, is smaller than current left element
			results[index[leftStart]] += rightStart - mid - 1
			leftStart++
		} else {
			// element in the left part is greater than right, count
			tempIndex[indexStart] = index[rightStart]
			rightStart++
		}
		indexStart++
	}

	for i := left; i <= right; i++ {
		index[i] = tempIndex[i]
	}
	return
}

// timeout
func countSmallerIteration(nums []int) []int {
	result := make([]int, len(nums))
	for i, base := range nums {
		start := i + 1
		res := 0
		for start < len(nums) {
			if nums[start] < base {
				res++
			}
			start++
		}
		result[i] = res
	}
	return result
}

// @lc code=end
