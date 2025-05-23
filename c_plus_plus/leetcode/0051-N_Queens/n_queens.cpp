#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    void backtracking(int n, int row, vector<string>& chessboard) {
        if (n == row) {
            result.push_back(chessboard);
            return;
        }

        for (int column = 0; column < n; column++) {
            if (isValid(row, column, chessboard, n)) {
                chessboard[row][column] = 'Q';
                backtracking(n, row + 1, chessboard);
                chessboard[row][column] = '.'; // backtracking
            }
        }
    }
    bool isValid(int row, int column, vector<string>& chessboard, int n) {
        // checking row
        for (int i = 0; i < row; i++) {
            if (chessboard[i][column] == 'Q') {
                return false;
            }
        }

        // checking \ row
        for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }

        // checking / row
        for (int i = row -  1, j = column + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
        return result;
    }
};

int main(int argc, char* argv[])
{
    int caseInput = 4;
    Solution sol;
    auto result = sol.solveNQueens(caseInput);

    for (auto res : result) {
        for (auto v : res) {
            cout << v << endl;
        }
        cout << endl;
    }

    return 0;
}
