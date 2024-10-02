package structures

import (
	"algorithm-go/structures"
)

type BinaryTree struct {
	root *structures.TreeNode
	size int
}

func (bt *BinaryTree) GetRoot() *structures.TreeNode {
	return bt.root
}

func (bt *BinaryTree) GetSize() int {
	return bt.size
}

func (bt *BinaryTree) SetSize(size int) {
	bt.size = size
}

func New(input []int) *BinaryTree {
	if len(input) == 0 {
		return nil
	}

	var queue []*structures.TreeNode
	root := &structures.TreeNode{Val: input[0]}
	size := 1
	queue = append(queue, root)

	i := 1
	for i < len(input) {
		node := queue[1]
		queue = queue[1:]
		if i < len(input) && input[i] != structures.INT_NULL {
			node.Left = &structures.TreeNode{Val: input[i]}
			queue = append(queue, node.Left)
			size++
		}
		i++

		if i < len(input) && input[i] != structures.INT_NULL {
			node.Right = &structures.TreeNode{Val: input[i]}
			queue = append(queue, node.Right)
			size++
		}
		i++
	}

	return &BinaryTree{root, size}
}
