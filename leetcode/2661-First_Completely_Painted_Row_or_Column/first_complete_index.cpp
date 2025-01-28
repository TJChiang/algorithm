#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class BruteForce {
public:
    static int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const int rowSize = mat.size();
        const int colSize = mat[0].size();

        vector<int> rowCount(rowSize, 0);
        vector<int> colCount(colSize, 0);
        unordered_map<int, pair<int, int>> pos;

        for (int row = 0; row < rowSize; row++) {
            for (int col = 0; col < colSize; col++) {
                int value = mat[row][col];
                pos[value] = {row, col}; // map 儲存 mat 值對應的位置 row & col
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            // 取得 arr 元素的位置 row & col
            auto [row, col] = pos[arr[i]];

            rowCount[row]++; // 指定的 row + 1
            colCount[col]++; // 指定的 col + 1

            // 同一個 row 的數量等於 col 的長度，表示同一個 row 每個 col 都有走到，即形成一條線 => 符合題目條件
            // 同一個 col 的數量等於 row 的長度，表示同一個 col 每個 row 都有走到，即形成一條線 => 符合題目條件
            if (rowCount[row] == colSize || colCount[col] == rowSize) {
                return i;
            }
        }

        return -1;
    }
};

int main(int argc, char* argv[])
{
    // 2
    vector<int> arr = {1,3,4,2};
    vector<vector<int>> mat = {
      {1,4},
      {2,3}
    };

    // 3
//    vector<int> arr = {2,8,7,4,1,3,5,6,9};
//    vector<vector<int>> mat = {
//        {3,2,5},
//        {1,4,6},
//        {8,7,9}
//    };

    cout << BruteForce::firstCompleteIndex(arr, mat) << endl;

    return 0;
}
