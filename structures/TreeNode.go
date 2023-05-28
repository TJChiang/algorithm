package structures

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var NULL = -1 << 63

func Int2TreeNode(numbers []int) *TreeNode {
	n := len(numbers)
	if n == 0 {
		return nil
	}

	root := &TreeNode{
		Val: numbers[0],
	}

	queue := make([]*TreeNode, 1, n*2)
	queue[0] = root

	i := 1
	for i < n {
		node := queue[0]
		queue = queue[1:]

		if i < n && numbers[i] != NULL {
			node.Left = &TreeNode{Val: numbers[i]}
			queue = append(queue, node.Left)
		}
		i++

		if i < n && numbers[i] != NULL {
			node.Right = &TreeNode{Val: numbers[i]}
			queue = append(queue, node.Right)
		}
		i++
	}

	return root
}

func TreeNode2Int(tn *TreeNode) []int {
	res := make([]int, 0, 1024)

	queue := []*TreeNode{tn}

	for len(queue) > 0 {
		size := len(queue)
		for i := 0; i < size; i++ {
			nd := queue[i]
			if nd == nil {
				res = append(res, NULL)
			} else {
				res = append(res, nd.Val)
				queue = append(queue, nd.Left, nd.Right)
			}
		}
		queue = queue[size:]
	}

	i := len(res)
	for i > 0 && res[i-1] == NULL {
		i--
	}

	return res[:i]
}
