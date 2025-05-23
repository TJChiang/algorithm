package assigncookies

import "sort"

func findContentChildren(g []int, s []int) int {
	sort.Ints(s)
	sort.Ints(g)
	index := len(s) - 1
	result := 0
	for i := len(g) - 1; i >= 0; i-- {
		if index >= 0 && s[index] >= g[i] {
			result++
			index--
		}
	}

	return result
}

func findContentChildrenDesc(g []int, s []int) int {
	sort.Ints(s)
	sort.Ints(g)
	index := 0
	for i := 0; i < len(s); i++ {
		if index < len(g) && s[i] >= g[index] {
			index++
		}
	}

	return index
}
