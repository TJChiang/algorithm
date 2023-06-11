package minimumdepthofbinarytree

import "github.com/tjchiang/leetcode-exercise/structures"

type TreeNode = structures.TreeNode

// DFS
func minDepthRecursion(root *TreeNode) int {
	return getDepth(root)
}

func getDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	left, right := getDepth(root.Left), getDepth(root.Right)

	if root.Left == nil && root.Right != nil {
		return right + 1
	}
	if root.Left != nil && root.Right == nil {
		return left + 1
	}
	return min(left, right) + 1
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// BFS
func minDepthIteration(root *TreeNode) int {
	if root == nil {
		return 0
	}
	queue := make([]*TreeNode, 0)
	queue = append(queue, root)

	result := 1

	for len(queue) > 0 {
		size := len(queue)
		for i := 0; i < size; i++ {
			// pull queue 第一個值
			node := queue[0]
			queue = queue[1:]

			// 表示為第一個葉子節點
			if node.Left == nil && node.Right == nil {
				return result
			}
			if node.Left != nil {
				queue = append(queue, node.Left)
			}
			if node.Right != nil {
				queue = append(queue, node.Right)
			}
		}
		// 該層結束，要到下一層，層數+1
		result++
	}

	return result
}
