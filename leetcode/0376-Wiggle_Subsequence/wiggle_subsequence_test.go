package wigglesubsequence

import (
	"testing"
)

func TestWiggleMaxLengthGreedy(t *testing.T) {
	testCase := []struct {
		nums     []int
		expected int
	}{
		{[]int{1, 7, 4, 9, 2, 5}, 6},
		{[]int{1, 17, 5, 10, 13, 15, 10, 5, 16, 8}, 7},
		{[]int{1, 2, 3, 4, 5, 6, 7, 8, 9}, 2},
		{[]int{1, 2, 2, 2, 2, 1}, 3},
		{[]int{2, 5}, 2},
		{[]int{1, 2, 2, 2, 3, 4}, 2},
	}

	for i, e := range testCase {
		if result := wiggleMaxLengthGreedy(e.nums); result != e.expected {
			t.Errorf("Test failed. Result of case %v is expected to get %v but get %v", i, e.expected, result)
		}
	}
}

func TestWiggleMaxLengthDp(t *testing.T) {
	testCase := []struct {
		nums     []int
		expected int
	}{
		{[]int{1, 7, 4, 9, 2, 5}, 6},
		{[]int{1, 17, 5, 10, 13, 15, 10, 5, 16, 8}, 7},
		{[]int{1, 2, 3, 4, 5, 6, 7, 8, 9}, 2},
		{[]int{1, 2, 2, 2, 2, 1}, 3},
		{[]int{2, 5}, 2},
		{[]int{1, 2, 2, 2, 3, 4}, 2},
	}

	for i, e := range testCase {
		if result := wiggleMaxLengthDp(e.nums); result != e.expected {
			t.Errorf("Test failed. Result of case %v is expected to get %v but get %v", i, e.expected, result)
		}
	}
}
