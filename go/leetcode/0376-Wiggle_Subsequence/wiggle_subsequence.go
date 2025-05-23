package wigglesubsequence

func wiggleMaxLengthGreedy(nums []int) int {
	size := len(nums)
	if size <= 1 || size > 1000 {
		return 0
	}

	curDiff := 0 // 當前差
	preDiff := 0 // 前一筆差
	result := 1

	for i := 0; i < size-1; i++ {
		curDiff = nums[i+1] - nums[i]
		// 當前差與前一筆差為正負相反，或是前一筆平坦值與當前差出現變動
		if (preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0) {
			result++
			preDiff = curDiff // 僅在出現峰值時 (非平坦)，更新 preDiff
		}
	}
	return result
}

func wiggleMaxLengthDp(nums []int) int {
	size := len(nums)
	if size <= 1 {
		return size
	}

	dp := make([][2]int, size)
	dp[0][0] = 1 // i 0 波峰最大長度，前 i 個數最大山峰值
	dp[0][1] = 1 // i 1 波谷最大長度，前 i 個數最大山谷值
	for i := 1; i < size; i++ {
		// 山峰山谷值初始化
		dp[i][0] = 1
		dp[i][1] = 1
		for j := 0; j < i; j++ {
			// 前 i 個數 (0 < j < i)，當前 i 值小於 nums[j] => 前一筆山峰值後面，視為下一筆山谷值，更新當前 i 山谷最大值
			if nums[i] < nums[j] {
				dp[i][1] = max(dp[i][1], dp[j][0]+1)
			}
		}
		for j := 0; j < i; j++ {
			// 前 i 個數 (0 < j < i)，當前 i 值大於 nums[j] => 前一筆山谷值後面，視為下一筆山峰值，更新當前 i 山峰最大值
			if nums[i] > nums[j] {
				dp[i][0] = max(dp[i][0], dp[j][1]+1)
			}
		}
	}
	return max(dp[size-1][0], dp[size-1][1])
}
