package _216_Combination_Sum_III

var (
	result [][]int
	path   []int
)

func combinationSum3(k int, n int) [][]int {
	result, path = make([][]int, 0), make([]int, 0, k)
	backtracking(k, n, 0, 1)
	return result
}

func backtracking(k int, n int, sum int, startIndex int) {
	if sum > n {
		return
	}
	if len(path) == k {
		if sum == n {
			tmp := make([]int, k)
			copy(tmp, path)
			result = append(result, tmp)
		}
		return
	}

	for i := startIndex; i <= 9 - (k - len(path)) + 1; i++ {
		sum += i
		path = append(path, i)
		backtracking(k, n, sum, i+1)
		sum -= i
		path = path[:len(path)-1]
	}
}
