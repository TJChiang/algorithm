package structures

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func InorderTraversal(cur *TreeNode) (res []int) {
	var traversal func(node *TreeNode)
	traversal = func(node *TreeNode) {
		if node == nil {
			return
		}

		traversal(node.Left)
		res = append(res, node.Val)
		traversal(node.Right)
	}

	traversal(cur)
	return res
}

func PreorderTraversal(cur *TreeNode) (res []int) {
	var traversal func(node *TreeNode)
	traversal = func(node *TreeNode) {
		if node == nil {
			return
		}

		res = append(res, node.Val)
		traversal(node.Left)
		traversal(node.Right)
	}

	traversal(cur)
	return res
}

func PostorderTraversal(cur *TreeNode) (res []int) {
	var traversal func(node *TreeNode)
	traversal = func(node *TreeNode) {
		if node == nil {
			return
		}

		traversal(node.Left)
		traversal(node.Right)
		res = append(res, node.Val)
	}

	traversal(cur)
	return res
}

func LevelOrder(root *TreeNode, mode string) (res [][]int) {
	if mode == "traversal" {
		res = levelOrderTraversal(root)
	} else {
		res = levelOrderTraversalWithQueue(root)
	}
	return
}

func levelOrderTraversal(root *TreeNode) [][]int {
	var res [][]int
	depth := 0

	var order func(root *TreeNode, depth int)
	order = func(root *TreeNode, depth int) {
		if root == nil {
			return
		}
		if len(res) == depth {
			res = append(res, []int{})
		}
		res[depth] = append(res[depth], root.Val)

		order(root.Left, depth+1)
		order(root.Right, depth+1)
	}
	order(root, depth)
	return res
}

func levelOrderTraversalWithQueue(root *TreeNode) (res [][]int) {
	if root == nil {
		return res
	}

	curLevel := []*TreeNode{root}
	for len(curLevel) > 0 {
		nextLevel := []*TreeNode{}
		vals := []int{}

		for _, node := range curLevel {
			vals = append(vals, node.Val)
			if node.Left != nil {
				nextLevel = append(nextLevel, node.Left)
			}
			if node.Right != nil {
				nextLevel = append(nextLevel, node.Right)
			}
		}
		res = append(res, vals)
		curLevel = nextLevel
	}
	return
}
