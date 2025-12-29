package assigncookies

import "testing"

func TestFindContentChildren(t *testing.T) {
	testCase := []struct {
		g        []int
		s        []int
		expected int
	}{
		{[]int{1, 2, 3}, []int{1, 1}, 1},
		{[]int{1, 2}, []int{1, 2, 3}, 2},
	}

	for _, e := range testCase {
		if result := findContentChildren(e.g, e.s); result != e.expected {
			t.Errorf("Test failed. Result is expected to get %v but get %v", e.expected, result)
		}
	}
}

func TestFindContentChildrenDes(t *testing.T) {
	testCase := []struct {
		g        []int
		s        []int
		expected int
	}{
		{[]int{1, 2, 3}, []int{1, 1}, 1},
		{[]int{1, 2}, []int{1, 2, 3}, 2},
	}

	for _, e := range testCase {
		if result := findContentChildrenDesc(e.g, e.s); result != e.expected {
			t.Errorf("Test failed. Result is expected to get %v but get %v", e.expected, result)
		}
	}
}
