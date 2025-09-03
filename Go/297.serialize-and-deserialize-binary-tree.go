/*
 * @lc app=leetcode id=297 lang=golang
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (59.45%)
 * Likes:    10820
 * Dislikes: 421
 * Total Accepted:    1.1M
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 *
 * Clarification: The input/output format is the same as how LeetCode
 * serializes a binary tree. You do not necessarily need to follow this format,
 * so please be creative and come up with different approaches yourself.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,null,null,4,5]
 * Output: [1,2,3,null,null,4,5]
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * -1000 <= Node.val <= 1000
 *
 *
 */

package main

import (
	"strconv"
	"strings"
)

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type Codec struct {
}

func Constructor() Codec {
	return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
	if root == nil {
		return ""
	}
	// BFS
	var result []string
	queue := []*TreeNode{root}
	for len(queue) > 0 {
		// traverse all the element in current level
		curLevelLen := len(queue)
		for range curLevelLen {
			// append value to string
			node := queue[0]
			queue = queue[1:]
			if node == nil {
				result = append(result, "null")
				continue
			}
			result = append(result, strconv.Itoa(node.Val))
			queue = append(queue, node.Left)
			queue = append(queue, node.Right)
		}
	}
	// remove trailing nulls
	for len(result) > 0 && result[len(result)-1] == "null" {
		result = result[:len(result)-1]
	}

	// []string to string
	return assembleString(result)
}

func assembleString(in []string) string {
	if len(in) == 0 {
		return ""
	}

	var result strings.Builder
	for i, s := range in {
		if i > 0 {
			result.WriteByte(',')
		}
		result.WriteString(s)
	}
	return result.String()
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
	// maybe can use DFS
	if len(data) == 0 {
		return nil
	}
	strs := strings.Split(data, ",")
	root := &TreeNode{Val: strToInt(strs[0])}

	queue := []*TreeNode{root}
	i := 1

	for i < len(strs) {
		node := queue[0]
		queue = queue[1:]

		// left child
		if strs[i] != "null" {
			node.Left = &TreeNode{Val: strToInt(strs[i])}
			queue = append(queue, node.Left)
		}
		i++
		// right child
		if i < len(strs) && strs[i] != "null" {
			node.Right = &TreeNode{Val: strToInt(strs[i])}
			queue = append(queue, node.Right)
		}
		i++
	}
	return root
}

func strToInt(str string) int {
	res, _ := strconv.Atoi(str)
	return res
}

/**
 * Your Codec object will be instantiated and called as such:
 * ser := Constructor();
 * deser := Constructor();
 * data := ser.serialize(root);
 * ans := deser.deserialize(data);
 */
// @lc code=end
