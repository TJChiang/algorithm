# 0002. Reverse Integer

[LeetCode](https://leetcode.com/problems/reverse-integer/)

>   Given a signed 32-bit integer `x`, return `x` with its digits reversed. If reversing `x` causes the value to go outside the signed 32-bit integer range <code>[-2<sup>31</sup>, 2<sup>31</sup> - 1]</code>, then return `0`.

>   **Assume the environment does not allow you to store 64-bit integers (signed or unsigned).**

### Example 1:
```
Input: x = 123
Output: 321
```

### Example 2:
```
Input: x = -123
Output: -321
```

### Example 3:
```
Input: x = 120
Output: 21
```

### Example 4:
```
Input: x = 0
Output: 0
```

### Constraints:
-   <code>2<sup>31</sup> <= x <= 2<sup>31</sup> - 1</code>

### Solution:
>   將 `res` 往左移後加上 `x` 的餘數，直到 `x` 等於 ０。

>   **Note: `res` 會先乘以10再加上餘數，因此為了避免乘以10後溢位，先將整數最大值（`INT_MAX`）和最小值（`INT_MIN`）除以10，再判斷 `res` 是否介於 `(INT_MAX / 10)` 與 `(INT_MIN / 10)` 之間**。

```cpp
int reverse(int x) {
    int res = 0;
    while(x != 0) {
        if (res > INT_MAX / 10 || res < INT_MIN / 10) return 0;
        res = res * 10 + (x % 10);
        x /= 10;
    }

    return res;
}
```