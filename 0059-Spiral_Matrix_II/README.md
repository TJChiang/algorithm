# 59. Spiral Matrix II

- [LeetCode](https://leetcode.com/problems/spiral-matrix-ii/)
- [參考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0059.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II.md)

有一個正整數 `n`，產生一個 `n x n` 的矩陣，1 到 n<sup>2</sup> 的值按照順時針螺旋排列填滿矩陣。
![螺旋矩陣](spiral_matrix_ii.jpeg)


## 思路
**此題不涉及艱難的算法，主要是模擬過程，以及考驗對程式碼的掌握程度。**

模擬數字順時針填格子過程：
1. 左到右
2. 上到下
3. 右到左
4. 下到上

以此可以發現邊界：
1. 左閉右開
2. 上閉下開
3. 左開右閉
4. 上開下閉

```cpp
class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            // 二維陣列
            vector<vector<int>> res(n, vector<int>(n, 0));

            // 每一圈的起始 x 座標與 y 座標
            int start_x = 0, start_y = 0;

            // 每一圈的有效長度
            int offset = 1;

            // 當前填入的正整數
            int count = 1;

            // 圈數，矩陣中間值單獨處理
            int loop = n / 2;

            // 矩陣中間值座標，n = 3，(1,1)；n = 5，(2,2)
            int mid = n / 2;

            // 當前 x 座標與 y 座標
            int sx, sy;

            while (loop > 0) {
                sx = start_x;
                sy = start_y;

                // 上行：左開右閉
                for (sx = start_x; sx < start_x + n - offset; sx++) {
                    res[sy][sx] = count;
                    count++;
                }

                // 右列：上開下閉
                for (sy = start_y; sy < start_y + n - offset; sy++) {
                    res[sy][sx] = count;
                    count++;
                }

                // 下行：右開左閉
                for (; sx > start_x; sx--) {
                    res[sy][sx] = count;
                    count++;
                }

                // 左列：下開上閉
                for (; sy > start_y; sy--) {
                    res[sy][sx] = count;
                    count++;
                }

                // 每多一圈，內圈長度為外圈長度 - 2
                offset += 2;

                // 內圈起始座標為外圈的右斜方 (0,0) -> (1,1) -> (2,2)
                start_x++;
                start_y++;

                loop--;
            }

            // 如果 n 為單數，矩陣最中間有單獨空格需要賦值
            if (n % 2 == 1) {
                res[mid][mid] = count;
            }

            return res;
        }
};
```
