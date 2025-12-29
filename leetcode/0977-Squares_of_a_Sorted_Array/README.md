# 0977 Squares of a Sorted Array

###### tags: `Array`、`雙指針`
<br>

[LeetCode](https://leetcode.com/problems/squares-of-a-sorted-array/)

[參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.md)

有一組非降冪排序的整數陣列 `nums`，回傳每個數字的平方組成新陣列，且依非降冪排列。

**範例 1**
```
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
```

**範例 2**
```
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
```

**限制邊界**
- 1 <= nums.length <= 10<sup>4</sup>
- -10<sup>4</sup> <= nums[i] <= 10<sup>4</sup>
- `nums` is sorted in **non-decreasing** order.

## 思路

### 暴力排序
```CPP
class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            for (int i = 0; i < nums.size(); i++) {
                nums[i] *= nums[i];
            }

            // 快速排序
            sort(nums.begin(), nums.end());

            return nums;
        }
};
```

- 時間複雜度：O(nlogn)
- 空間複雜度：O(1)

### 雙指針法

平方後的最大值一定出現在 `nums` 的**兩端**，所以設定兩個指標分別指向 `nums` 兩端，平方後比較大的放在新陣列的最右方，依此類推。

```CPP
class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            int n = nums.size() - 1;
            vector<int> result(nums.size(), 0);

            for (int left = 0, right = n; left <= right;) {
                if (nums[right] * nums[right] > nums[left] * nums[left]) {
                    result[n--] = nums[right] * nums[right];
                    right--;
                } else {
                    result[n--] = nums[left] * nums[left];
                    left++;
                }
            }

            return result;
        }
};
```

- 時間複雜度：O(n)
- 空間複雜度：O(n)