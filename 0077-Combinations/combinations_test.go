package _077_Combinations

import (
	"fmt"
	"reflect"
	"testing"
)

type question struct {
	input
	output
}

type input struct {
	n int
	k int
}

type output struct {
	first [][]int
}

func Test_combine(t *testing.T) {
	qs := []question{
		{
			input{n: 4, k: 2},
			output{[][]int{{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}}},
		},
		{
			input{n: 1, k: 1},
			output{[][]int{{1}}},
		},
	}

	for count, q := range qs {
		i, o := q.input, q.output
		result := combine(i.n, i.k)

		fmt.Printf("------------Test case %v-------------\n", count+1)

		fmt.Printf("Input n: %v, k: %v \n", i.n, i.k)
		fmt.Println("expected: ", o.first)
		fmt.Println("actual: ", result)

		if !reflect.DeepEqual(result, o.first) {
			t.Errorf("n: %v, k: %v, result error.", i.n, i.k)
		}
	}
}
