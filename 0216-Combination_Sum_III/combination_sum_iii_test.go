package _216_Combination_Sum_III

import (
	"fmt"
	"reflect"
	"testing"
)

type questions struct {
	input
	output
}

type input struct {
	k int
	n int
}

type output struct {
	first [][]int
}

func Test_combinationSum3(t *testing.T) {
	qs := []questions{
		{
			input{k: 3, n: 7},
			output{[][]int{{1, 2, 4}}},
		},
		{
			input{k: 3, n: 9},
			output{[][]int{{1, 2, 6}, {1, 3, 5}, {2, 3, 4}}},
		},
		{
			input{k: 4, n: 1},
			output{[][]int{}},
		},
	}

	for count, q := range qs {
		i, o := q.input, q.output
		result := combinationSum3(i.k, i.n)

		fmt.Printf("------------Test case %v-------------\n", count+1)
		fmt.Printf("Input: k = %d, n = %d \n", i.k, i.n)
		fmt.Println("Excepted: ", o.first)
		fmt.Println("Actual: ", result)

		if !reflect.DeepEqual(o.first, result) {
			t.Error("result error.")
		}
	}
}
