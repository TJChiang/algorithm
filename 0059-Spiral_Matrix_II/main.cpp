#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
    public:
        vector<vector<int> > generateMatrix(int n) {
            // 二維陣列
            vector<vector<int> > res(n, vector<int>(n, 0));

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

            while (loop --) {
                sx = start_x;
                sy = start_y;

                // 上行：左開右閉
                for (sx = start_x; sx < start_x + n - offset; sx++)
                    res[sy][sx] = count++;

                // 右列：上開下閉
                for (sy = start_y; sy < start_y + n - offset; sy++)
                    res[sy][sx] = count++;

                // 下行：右開左閉
                for (; sx > start_x; sx--)
                    res[sy][sx] = count++;

                // 左列：下開上閉
                for (; sy > start_y; sy--)
                    res[sy][sx] = count++;

                // 每多一圈，內圈長度為外圈長度 - 2
                offset += 2;

                // 內圈起始座標為外圈的右斜方 (0,0) -> (1,1) -> (2,2)
                start_x++;
                start_y++;
            }

            // 如果 n 為單數，矩陣最中間有單獨空格需要賦值
            if (n % 2 == 1) {
                res[mid][mid] = count;
            }

            return res;
        }
};

int main(int argc, char* argv[])
{
    Solution sol;

    int n = atoi(argv[1]);
    auto result = sol.generateMatrix(n);

    for (auto it = result.begin(); it != result.end(); it++)
    {
        vector<int> im = *it;
        for (auto i = im.begin(); i != im.end(); i++) {
            cout << *i << "\t";
        }

        cout << endl;
    }

    return 0;
}