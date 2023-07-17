package _077_Combinations

var res [][]int
var path []int

func combine(n int, k int) [][]int {
	res, path = make([][]int, 0), make([]int, 0, k)
	backtracking(n, k, 1)
	return res
}

func backtracking(n int, k int, startIndex int) {
	if len(path) == k {
		tmp := make([]int, k)
		copy(tmp, path)
		res = append(res, tmp)
		return
	}
	for i := startIndex; i <= n; i++ {
		// 剪枝
		if i > n-(k-len(path))+1 {
			break
		}
		path = append(path, i)
		backtracking(n, k, i+1)
		path = path[:len(path)-1]
	}
}
