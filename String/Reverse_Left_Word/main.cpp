#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
    public:
        string reverseLeftWords(string s, int k) {
            if (k < 1 || k > s.size() || s.size() > 10000) return "";

            // 反轉前 k 個字串 => ba|cdefg
            reverse(s.begin(), s.begin() + k);

            // 反轉 k 之後的字串 => ba|gfedc
            reverse(s.begin() + k, s.end());

            // 反轉全部字串 => cdefg|ab
            reverse(s.begin(), s.end());

            return s;
        }
};

int main() {
    Solution sol;

    string s = "abcdefg";
    int k = 2;

    string res = sol.reverseLeftWords(s, k);

    cout << res << endl;

    return 0;
}