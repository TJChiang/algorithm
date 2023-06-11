package minimumdepthofbinarytree

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
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
	first int
}

var NULL = structures.NULL

func Test_minDepthRecursion(t *testing.T) {
	ast := assert.New(t)
	qs := []question{
		{
			input{[]int{3, 9, 20, NULL, NULL, 15, 7}},
			output{2},
		},
		{
			input{[]int{2, NULL, 3, NULL, 4, NULL, 5, NULL, 6}},
			output{5},
		},
		{
			input{[]int{}},
			output{0},
		},
	}

	for _, q := range qs {
		i, o := q.input, q.output
		root := structures.Int2TreeNode(i.first)
		actual := minDepthRecursion(root)
		ast.Equal(o.first, actual)
		fmt.Printf("Input: %v / ", i)
		fmt.Printf("Output: %v  \n", actual)
	}
}

func Test_minDepthIteration(t *testing.T) {
	ast := assert.New(t)
	qs := []question{
		{
			input{[]int{3, 9, 20, NULL, NULL, 15, 7}},
			output{2},
		},
		{
			input{[]int{2, NULL, 3, NULL, 4, NULL, 5, NULL, 6}},
			output{5},
		},
		{
			input{[]int{}},
			output{0},
		},
	}

	for _, q := range qs {
		i, o := q.input, q.output
		root := structures.Int2TreeNode(i.first)
		actual := minDepthIteration(root)
		ast.Equal(o.first, actual)
		fmt.Printf("Input: %v / ", i)
		fmt.Printf("Output: %v  \n", actual)
	}
}
