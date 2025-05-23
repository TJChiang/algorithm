#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        string reverseStr(string s, int k) {
            for (int i = 0; i < s.size(); i += 2 * k) {
                // 剩餘字數大於等於 2k ，前 k 個字反轉
                if (i + k <= s.size()) {
                    reverse(s.begin() + i, s.begin() + i + k);
                    continue;
                }

                // 剩餘次數小於 k ，剩餘字數全數反轉
                reverse(s.begin() + i, s.begin() + s.size());
            }

            return s;
        }
};

int main() {
    Solution sol;

    string s = "abcdefg";
    int k = 2;

    string res = sol.reverseStr(s, k);

    cout << res << endl;

    return 0;
}