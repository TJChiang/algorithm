# 209. Minimum Size Subarray Sum

###### tags: `Array`、`雙指針`、`滑動窗口`
<br>

[LeetCode](https://leetcode.com/problems/minimum-size-subarray-sum/)

[參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0209.%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.md)

輸入一個 n 個正整數的陣列 `nums` 和一個正整數 `target`，找出 `nums` 中滿足其和 ≥ `target` 的**連續最小長度**子陣列，並返回其長度。如果沒有符合條件的子陣列，回傳 0。


**範例 1**
```
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
```

**範例 2**
```
Input: target = 4, nums = [1,4,4]
Output: 1
```

**範例 3**
```
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
```

**限制邊界**
- 1 <= target <= 10<sup>9</sup>
- 1 <= nums.length <= 10<sup>5</sup>
- 1 <= nums[i] <= 10<sup>5</sup>

## 暴力解法
```cpp
class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int result = INT32_MAX; // 結果
            int sum = 0; // 子陣列的和
            int length = 0; // 子陣列長度
            for (int i = 0; i < nums.size(); i++) {
                sum = 0;
                for (int j = i; j < nums.size(); j++) {
                    sum += nums[j];
                    if (sum >= target) { // 和大於等於 target 時，更新 result
                        length = j - i + 1; // 子陣列長度
                        result = result < length ? result : length; // 指定最小長度
                        break;
                    }
                }
            }

            // 不符合的話就回傳 0
            return result == INT32_MAX ? 0 : result;
        }
};
```
- 時間複雜度：O(n<sup>2</sup>)
- 空間複雜度：O(1)


## 滑動窗口

**不斷調整子陣列的起始位址和結束位址，以獲得期望的結果。**

此題實現滑動窗口，主要確認三點：
- 窗口內是什麼？
    - 滿足其和 ≥ `target`，的連續最小長度子陣列
- 如何移動窗口的起始位址？
    - 如果目前窗口的值大於 `target` ，窗口就要向前移動(縮小範圍)。
- 如何移動窗口的結束位址？
    - 窗口的結束位址就是遍歷陣列的指針，窗口的起始位址設置為陣列的起始位址。

```cpp
class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int result = INT32_MAX; // 結果
            int sum = 0; // 子陣列的和
            int startIndex = 0;
            int length = 0; // 子陣列長度
            for (int endIndex = 0; endIndex < nums.size(); endIndex++) {
                sum += nums[endIndex];
                // 這邊使用 while ，每次更新起始位址，並不斷比較子陣列是否符合條件
                while (sum >= target) {
                    length = endIndex - startIndex + 1; // 子陣列長度
                    result = result < length ? result : length; // 指定最小長度
                    sum -= nums[startIndex]; // 調整起始位址，縮小範圍
                    startIndex++;
                }
            }

            // 不符合的話就回傳 0
            return result == INT32_MAX ? 0 : result;
        }
};
```
- 時間複雜度：O(n)
    - 主要看每個元素被操作的次數，每一個元素在滑動窗口進入時操作一次，出去時操作一次，每個元素被操作兩次，所以時間複雜度為 2 x n ，也就是 O(n)。
- 空間複雜度：O(1)

## 額外題目
- [904. Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/)
- [76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)