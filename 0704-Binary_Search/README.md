# 704. Binary Search
[LeetCode](https://leetcode.com/problems/binary-search/)
[參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.md)

有一個升冪的整數有序陣列 `nums`，以及一個 `target` 值。寫一個 function 找到 `nums` 中的 `target` 值。

如果 `target` 存在，回傳 `nums` 的 index；反之，回傳 `-1`。

必須使用時間複雜度 `O(log n)` 的演算法。

**範例 1**
```
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```

**範例 2**
```
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```

**邊界限制**：
- 1 <= nums.length <= 10<sup>4</sup>
- 10<sup>4</sup> < nums[i], target < 10<sup>4</sup>
- All the integers in `nums` are **unique**.
- `nums` is sorted in ascending order


## 思路

適不適合用二元搜尋？ 適合
- 陣列是否有序？ 是，否則不適合
- 陣列的值是否為唯一？ 是，否則找到的值非唯一值

二元搜尋最重要的是**定義邊界**，主要分兩種：
1. [left, right] => 左閉區間、右閉區間，包含左右邊的值
2. [left, right) => 左閉區間、右開區間，不包含右邊的值

### [left, right] 寫法
1. 當 left = right 的時候，也在區間內
2. 由於 right 也在區間內，當 `nums[middle] > target` 時，right 要賦值 middle - 1。原因為 nums[middle] 一定不是 target， middle 右邊一定也不是(有序且升冪)，那麼就要將 middle 左邊(middle - 1)作為有效邊界，繼續查詢。

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            // 防止溢出
            int mid = left + ((right - left) / 2);
            if (target == nums[mid]) return mid;
            else if (target > nums[mid]) left = ++mid;
            else if (target < nums[mid]) right = --mid;
        }

        return -1;
    }
}
```

### [left, right) 寫法
1. 當 left = right ，不在區間內
2. 由於 right 不在區間內，當 `nums[middle] > target` 時，right 要賦值 middle。原因為 nums[middle] 一定不是 target ， right 也不在邊界內，所以 right = middle 即可。

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size(); // <- 右邊為開區間，所以不用 -1

        while (left < right) {
            // 防止溢出
            int mid = left + ((right - left) / 2);
            if (target == nums[mid]) return mid;
            else if (target > nums[mid]) left = ++mid;
            else if (target < nums[mid]) right = mid;
        }

        return -1;
    }
}
```