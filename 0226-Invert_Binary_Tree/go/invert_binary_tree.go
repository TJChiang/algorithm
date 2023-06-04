package invertbinarytree

import "github.com/tjchiang/leetcode-exercise/structures"

type TreeNode = structures.TreeNode

func InvertBinaryTree(root *TreeNode) *TreeNode {
	if root == nil {
		return root
	}
	InvertBinaryTree(root.Left)
	InvertBinaryTree(root.Right)
	root.Left, root.Right = root.Right, root.Left
	return root
}
