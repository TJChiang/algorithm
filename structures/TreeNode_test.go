package structures

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

var (
	//      1
	//    /   \
	//   2     3
	//  / \   / \
	// 4   5 6   7
	Order = []int{1, 2, 3, 4, 5, 6, 7}
)

func Test_Int2TreeNode(t *testing.T) {
	ast := assert.New(t)
	expected := &TreeNode{
		Val: 1,
		Left: &TreeNode{
			Val:   2,
			Left:  &TreeNode{Val: 4},
			Right: &TreeNode{Val: 5},
		},
		Right: &TreeNode{
			Val:   3,
			Left:  &TreeNode{Val: 6},
			Right: &TreeNode{Val: 7},
		},
	}

	actual := Int2TreeNode(Order)
	ast.Equal(expected, actual)
}
