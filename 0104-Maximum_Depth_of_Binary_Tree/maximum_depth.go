package maximumdepthofbinarytree

import "github.com/tjchiang/leetcode-exercise/structures"

type TreeNode = structures.TreeNode

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxDepthRecursion(root *TreeNode) int {
	if root == nil {
		return 0
	}
	leftDepth, rightDepth := maxDepthRecursion(root.Left), maxDepthRecursion(root.Right)

	// + 1 是當前中間節點
	return max(leftDepth, rightDepth) + 1
}

func maxDepthIteration(root *TreeNode) int {
	result := 0
	queue := make([]*TreeNode, 0)
	if root != nil {
		queue = append(queue, root)
	}

	// level order traversal
	for len(queue) > 0 {
		s := len(queue)
		for i := 0; i < s; i++ {
			node := queue[0]
			if node.Left != nil {
				queue = append(queue, node.Left)
			}
			if node.Right != nil {
				queue = append(queue, node.Right)
			}
			queue = queue[1:]
		}
		result++
	}

	return result
}
