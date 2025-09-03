/*
 * @lc app=leetcode id=169 lang=golang
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (65.83%)
 * Likes:    21636
 * Dislikes: 764
 * Total Accepted:    4.7M
 * Total Submissions: 7.1M
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array nums of size n, return the majority element.
 *
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * You may assume that the majority element always exists in the array.
 *
 *
 * Example 1:
 * Input: nums = [3,2,3]
 * Output: 3
 * Example 2:
 * Input: nums = [2,2,1,1,1,2,2]
 * Output: 2
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 5 * 10^4
 * -10^9 <= nums[i] <= 10^9
 *
 *
 *
 * Follow-up: Could you solve the problem in linear time and in O(1) space?
 */
package main

// @lc code=start
// O(N), O(N)
func majorityElement(nums []int) int {
	countMap := make(map[int]int)
	for _, num := range nums {
		countMap[num]++
	}
	majority := 0
	majorCount := 0
	for num, count := range countMap {
		if count > majorCount {
			majorCount = count
			majority = num
		}
	}
	return majority
}

// O(N)时间, O(1)空间 - 最优解
func majorityElementBoyerMoore(nums []int) int {
	candidate := 0
	count := 0

	for _, num := range nums {
		if count == 0 {
			candidate = num
		}
		if num == candidate {
			count++
		} else {
			count--
		}
	}
	return candidate
}

// @lc code=end
