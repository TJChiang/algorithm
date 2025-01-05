#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // 設定陣列，紀錄 n 位址的正負值，只要將 0 到 n 位址的值相加，即為 n 值的正負值
        vector<int> diff(s.size(), 0);

        for (auto shift : shifts) {
            int start = shift[0];
            int end = shift[1];

            if (shift[2] == 1) {
                // 只需要 start 位址 +1 即可，後面位址的值都會隨之 +1
                diff[start]++;

                // 如果 end 位址之後仍在陣列內，則將 end + 1 的值 -1
                // 避免受到前面的值 +1 的影響，應該 -1 以恢復該位址的正負值
                if (end + 1 < s.size()) {
                    diff[end + 1]--;
                }
            } else {
                // 只需要 start 位址 -1 即可，後面位址的值都會隨之 -1
                diff[start]--;

                // 如果 end 位址之後仍在陣列內，則將 end + 1 的值 +1
                // 避免受到前面的值 -1 的影響，應該 +1 以恢復該位址的正負值
                if (end + 1 < s.size()) {
                    diff[end + 1]++;
                }
            }
        }

        string result(s.size(), ' ');
        int numberOfShifts = 0;

        for (int i = 0; i < s.size(); i++) {
            numberOfShifts = (numberOfShifts + diff[i]) % 26;

            if (numberOfShifts < 0) numberOfShifts += 26;

            result[i] = 'a' + (s[i] - 'a' + numberOfShifts) % 26;
        }

        return result;
    }
};

int main(int argc, char* argv[])
{
    vector<vector<int>> shifts;
    shifts = {
        {2, 3, 1},
        {0, 2, 0},
        {1, 4, 0}
    };

    Solution sol;
    cout << sol.shiftingLetters("abxka", shifts) << endl;
    cout << "zzwkz" << endl;

    return 0;
}
