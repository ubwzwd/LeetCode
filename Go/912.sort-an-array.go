/*
 * @lc app=leetcode id=912 lang=golang
 *
 * [912] Sort an Array
 *
 * https://leetcode.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (56.31%)
 * Likes:    6937
 * Dislikes: 832
 * Total Accepted:    979K
 * Total Submissions: 1.7M
 * Testcase Example:  '[5,2,3,1]'
 *
 * Given an array of integers nums, sort the array in ascending order and
 * return it.
 *
 * You must solve the problem without using any built-in functions in
 * O(nlog(n)) time complexity and with the smallest space complexity
 * possible.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [5,2,3,1]
 * Output: [1,2,3,5]
 * Explanation: After sorting the array, the positions of some numbers are not
 * changed (for example, 2 and 3), while the positions of other numbers are
 * changed (for example, 1 and 5).
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [5,1,1,2,0,0]
 * Output: [0,0,1,1,2,5]
 * Explanation: Note that the values of nums are not necessarily unique.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 5 * 10^4
 * -5 * 10^4 <= nums[i] <= 5 * 10^4
 *
 *
 */
package main

import "math/rand"

// @lc code=start
func sortArray(nums []int) []int {
	if len(nums) <= 1 {
		return nums
	}
	mergeSort(nums, 0, len(nums)-1)
	return nums
}

func mergeSort(nums []int, left, right int) {
	if left >= right {
		return
	}

	mid := (right-left)/2 + left
	mergeSort(nums, left, mid)
	mergeSort(nums, mid+1, right)

	leftStart := left
	rightStart := mid + 1
	sortedPart := make([]int, right-left+1)
	i := 0

	for leftStart <= mid || rightStart <= right {
		if leftStart > mid {
			sortedPart[i] = nums[rightStart]
			i++
			rightStart++
			continue
		}
		if rightStart > right {
			sortedPart[i] = nums[leftStart]
			i++
			leftStart++
			continue
		}
		// if both exists
		if nums[leftStart] <= nums[rightStart] {
			sortedPart[i] = nums[leftStart]
			i++
			leftStart++
		} else {
			sortedPart[i] = nums[rightStart]
			i++
			rightStart++
		}
	}
	for i, num := range sortedPart {
		nums[i+left] = num
	}
	return
}

// 快排的时间复杂度和空间复杂度都不稳定，最差的时间复杂度有n^2
func quickSortOptimized(nums []int, left, right int) {
	if left >= right {
		return
	}

	// 随机选择枢轴避免最坏情况
	randomIndex := left + rand.Intn(right-left+1)
	nums[randomIndex], nums[right] = nums[right], nums[randomIndex]

	pivotIndex := partition(nums, left, right)
	quickSortOptimized(nums, left, pivotIndex-1)
	quickSortOptimized(nums, pivotIndex+1, right)
}

func partition(nums []int, left, right int) int {
	pivot := nums[right] // 选择最后一个元素作为枢轴
	i := left - 1

	for j := left; j < right; j++ {
		if nums[j] <= pivot {
			i++
			nums[i], nums[j] = nums[j], nums[i]
		}
	}

	nums[i+1], nums[right] = nums[right], nums[i+1]
	return i + 1
}

// @lc code=end
