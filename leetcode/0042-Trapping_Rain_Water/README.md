# 42. Trapping Rain Water

###### tags: `two pointers`, `dynamic programming`

[LeetCode](https://leetcode.com/problems/trapping-rain-water/description/)

[reference](https://www.youtube.com/watch?v=ZI2z5pq0TqA)

Problem Context

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

**範例 1**

![image.png](image.png)

```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.![alt text](image.png)
```

**範例 2**

```
Input: height = [4,2,0,3,2,5]
Output: 9
```

**限制邊界**

- n == height.length
- 1 <= n <= 2 * 10<sup>4</sup>
- 0 <= height[i] <= 10<sup>5</sup>

## 思路

### Prefix and Suffix Arrays

Prefix and suffix arrays can be used to store the maximum height of the bars to the left and right of each bar, respectively. The amount of water that can be trapped on top of each bar is determined by the minimum of these two maximum heights minus the height of the current bar.

prefix[i] means the maximum height of the bars to the left of index i (including i). [left, i]
suffix[i] means the maximum height of the bars to the right of index i (including i). [i, right]

| height | 0 | 1 | 0 | 2 | 1 | 0 | 1 | 3 | 2 | 1 | 2 | 1 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| prefix | 0 | 1 | 1 | 2 | 2 | 2 | 2 | 3 | 3 | 3 | 3 | 3 |
| suffix | 3 | 3 | 3 | 3 | 3 | 3 | 3 | 3 | 2 | 2 | 2 | 1 |
| result | 0 | 0 | 1 | 0 | 1 | 2 | 1 | 0 | 0 | 1 | 0 | 0 |

height = [0,1,0,2,1,0,1,3,2,1,2,1]
prefix = [0,1,1,2,2,2,2,3,3,3,3,3]
suffix = [3,3,3,3,3,3,3,3,2,2,2,1]

result[i] = min(prefix[i], suffix[i]) - height[i]

- Time Complexity： O(n)
- Space Complexity： O(n)

### Two Pointers

Two pointers can be used to traverse the height array from both ends towards the center.

The amount of water that can be trapped on top of each bar is determined by the minimum of the maximum heights seen so far from both ends minus the height of the current bar.

- Time Complexity： O(n)
- Space Complexity： O(1)
