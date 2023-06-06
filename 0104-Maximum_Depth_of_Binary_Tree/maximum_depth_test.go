package maximumdepthofbinarytree

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

func Test_maxDepthRecursion(t *testing.T) {
	ast := assert.New(t)
	qs := []question{
		{
			input{[]int{3, 9, 20, NULL, NULL, 15, 7}},
			output{3},
		},
		{
			input{[]int{1, NULL, 2}},
			output{2},
		},
	}

	for _, q := range qs {
		i, o := q.input, q.output
		root := structures.Int2TreeNode(i.first)
		actual := maxDepthRecursion(root)
		ast.Equal(o.first, actual)
		fmt.Printf("Input: %v / ", i)
		fmt.Printf("Output: %v  \n", actual)
	}
}

func Test_maxDepthIteration(t *testing.T) {
	ast := assert.New(t)
	qs := []question{
		{
			input{[]int{3, 9, 20, NULL, NULL, 15, 7}},
			output{3},
		},
		{
			input{[]int{1, NULL, 2}},
			output{2},
		},
	}

	for _, q := range qs {
		i, o := q.input, q.output
		root := structures.Int2TreeNode(i.first)
		actual := maxDepthIteration(root)
		ast.Equal(o.first, actual)
		fmt.Printf("Input: %v / ", i)
		fmt.Printf("Output: %v  \n", actual)
	}
}
