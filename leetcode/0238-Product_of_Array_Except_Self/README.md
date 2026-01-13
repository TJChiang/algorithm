# 238. Product of Array Except Self

###### tags: `array`, `prefix`, `suffix`

[LeetCode](https://leetcode.com/problems/product-of-array-except-self/description/)

Problem Context

Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

The product of any prefix or suffix of `nums` is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in `O(n)` time and without using the division operation.

Follow up: Can you solve the problem in `O(1)` extra space complexity? (The output array does not count as extra space for space complexity analysis.)

**範例 1**
```
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
```

**範例 2**
```
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
```

**限制邊界**
- 2 <= nums.length <= 10<sup>5</sup>
- 30 <= nums[i] <= 30
- The input is generated such that `answer[i]` is guaranteed to fit in a 32-bit integer.

## 思路

### Solution

**Prefix and Suffix Products**

prefix[i] is the product of all the elements to the left of index i.
suffix[i] is the product of all the elements to the right of index i.
prefix[i] * suffix[i] will give the product of all elements except nums[i], which is the desired output.

```
Input: [1,2,3,4]
Prefix products: [1,1,2,6]
Suffix products: [24,12,4,1]
Output: prefix[i] * suffix[i] = output[i] => [24,12,8,6]
```

- Time Complexity： O(n) where n is the length of the input array.
- Space Complexity： O(1) since we are using the output array to store the results and not using any additional space proportional to the input size.
