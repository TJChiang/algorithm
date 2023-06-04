package symmetrictree

import "github.com/tjchiang/leetcode-exercise/structures"

type TreeNode = structures.TreeNode

func compare(left *TreeNode, right *TreeNode) bool {
	if left != nil && right == nil {
		return false
	} else if left == nil && right != nil {
		return false
	} else if left == nil && right == nil {
		return true
	} else if left.Val != right.Val {
		return false
	}

	// 外面 左邊 - 右邊
	outside := compare(left.Left, right.Right)
	// 裡面 右邊 - 左邊
	inside := compare(left.Right, right.Left)

	return outside && inside
}

func isSymmetricRecursion(root *TreeNode) bool {
	if root == nil {
		return true
	}

	return compare(root.Left, root.Right)
}

func isSymmetricIteration(root *TreeNode) bool {
	if root == nil {
		return true
	}

	var queue []*TreeNode
	queue = append(queue, root.Left)
	queue = append(queue, root.Right)

	for len(queue) > 0 {
		left := queue[0]
		right := queue[1]
		queue = queue[2:]
		if left == nil && right == nil {
			continue
		}
		if left == nil || right == nil || left.Val != right.Val {
			return false
		}
		queue = append(queue, left.Left, right.Right, left.Right, right.Left)
	}

	return true
}
