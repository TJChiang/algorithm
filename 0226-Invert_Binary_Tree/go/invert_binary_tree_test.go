package invertbinarytree

import (
	"fmt"
	"testing"

	"github.com/tjchiang/leetcode-exercise/structures"
)

type question struct {
	input
	output
}

type input struct {
	first []int
}

type output struct {
	first []int
}

func Test_InvertBinaryTree(t *testing.T) {
	qs := []question{
		{
			input{[]int{}},
			output{[]int{}},
		},
		{
			input{[]int{2, 1, 3}},
			output{[]int{2, 3, 1}},
		},
		{
			input{[]int{4, 2, 7, 1, 3, 6, 9}},
			output{[]int{4, 7, 2, 9, 6, 3, 1}},
		},
	}

	fmt.Printf("-------------------------------------\n")

	for _, q := range qs {
		_, o := q.input, q.output
		fmt.Printf("Input: %v / ", o)
		root := structures.Int2TreeNode(o.first)
		fmt.Printf("Output: %v  \n", structures.TreeNode2Int(InvertBinaryTree(root)))
	}

	fmt.Println("")
}
