/*
 * @lc app=leetcode id=102 lang=golang
 *
 * [102] Binary Tree Level Order Traversal
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
// func levelOrder(root *TreeNode) [][]int {
// 	if root == nil {
// 		return [][]int{}
// 	}
// 	queue := list.New()
// 	queue.PushBack(root)

// 	cur := root
// 	var result [][]int

// 	for queue.Len() > 0 {
// 		levelSize := queue.Len()
// 		levelResult := make([]int, levelSize)
// 		for i := range levelSize {
// 			// get the top of the queue
// 			cur = queue.Remove(queue.Front()).(*TreeNode)

// 			// assemble current level result
// 			levelResult[i] = cur.Val

// 			if cur.Left != nil {
// 				queue.PushBack(cur.Left)
// 			}
// 			if cur.Right != nil {
// 				queue.PushBack(cur.Right)
// 			}
// 		}
// 		result = append(result, levelResult)
// 	}
// 	return result
// }

// slice ver
func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	queue := []*TreeNode{root}

	var result [][]int

	for len(queue) > 0 {
		levelSize := len(queue)
		levelResult := make([]int, levelSize)
		for i := range levelSize {
			// get the top of the queue
			root = queue[0]
			queue = queue[1:]

			// assemble current level result
			levelResult[i] = root.Val

			if root.Left != nil {
				queue = append(queue, root.Left)
			}
			if root.Right != nil {
				queue = append(queue, root.Right)
			}
		}
		result = append(result, levelResult)
	}
	return result
}

// @lc code=end
