package symmetrictree

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
	first bool
}

func Test_isSymmetricRecursion(t *testing.T) {
	qs := []question{
		{
			input{[]int{1, 2, 2, 3, 4, 4, 3}},
			output{true},
		},
		{
			input{[]int{1, 2, 2, structures.NULL, 3, structures.NULL, 3}},
			output{false},
		},
	}

	fmt.Printf("-----------------Recursion----------------\n")

	for _, q := range qs {
		i, _ := q.input, q.output
		fmt.Printf("Input: %v / ", i)
		root := structures.Int2TreeNode(i.first)
		fmt.Printf("Output: %v  \n", isSymmetricRecursion(root))
	}

	fmt.Println("")
}

func Test_isSymmetricIteration(t *testing.T) {
	qs := []question{
		{
			input{[]int{1, 2, 2, 3, 4, 4, 3}},
			output{true},
		},
		{
			input{[]int{1, 2, 2, structures.NULL, 3, structures.NULL, 3}},
			output{false},
		},
	}

	fmt.Printf("-----------------Iteration----------------\n")

	for _, q := range qs {
		i, _ := q.input, q.output
		fmt.Printf("Input: %v / ", i)
		root := structures.Int2TreeNode(i.first)
		fmt.Printf("Output: %v  \n", isSymmetricIteration(root))
	}

	fmt.Println("")
}
