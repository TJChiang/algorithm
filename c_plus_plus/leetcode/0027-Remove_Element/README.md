# 27. Remove Element

###### tags: `Array`、`雙指針`、`快慢指針`
<br>

[LeetCode](https://leetcode.com/problems/remove-element/)

[參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.md)

有一個整數陣列 `nums` 和一個整數值 `val`，必須**原地**刪除所有 `nums` 中的 `val` 值，並返回移除後的陣列長度。

不使用額外的空間，必須使用 O(1) 的空間，**原地**修改輸入的陣列。

陣列值的順序可以改變，不需要考慮陣列中超出新長度後面的值。

**範例 1**
```
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**範例 2**
```
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**限制邊界**
- 0 <= nums.length <= 100
- 0 <= nums[i] <= 50
- 0 <= val <= 100

## 思路

### 暴力解法
遍歷每個數值，若與 `val` 相同，則再遍歷一次，將後面的值取代前面的值。

```CPP
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) {
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                i--;
                size--;
            }
        }

        return size;
    }
}
```

- 時間複雜度：O(n<sup>2</sup>)
- 空間複雜度：O(1)

### 快慢指針
快指針尋找符合新陣列的值，慢指針指向新陣列的更新位置，若不是 `val` ，則更新慢指針 index 的值。
- 快指針：找符合新陣列的值
- 慢指針：指向更新新陣列的 index

```CPP
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
        }

        return slow;
    }
}
```

- 時間複雜度：O(n)
- 空間複雜度：O(1)