#include <iostream>

using namespace std;

class Solution {
    public:
        // 反轉字串
        void reverseString(string& s, int begin, int end) {
            for (int i = begin, j = end; i < j; i++, j--) {
                swap(s[i], s[j]);
            }
        }

        void removeExtraSpaces(string& s) {
            int slow = 0, fast = 0;

            // 移除字串前端的空格
            while (s.size() > 0 && fast < s.size() && s[fast] == ' ') {
                fast++;
            }

            // 移除單字中的空格
            for (; fast < s.size(); fast++) {
                // 移除單字中額外的空格
                if (
                    fast - 1 > 0
                    && s[fast - 1] == ' '
                    && s[fast] == ' '
                ) {
                    continue;
                }

                // 複製資料
                s[slow++] = s[fast];
            }

            // 移除字串尾端的空格
            if (slow - 1 > 0 && s[slow - 1] == ' ')
                s.resize(slow - 1);
            else
                s.resize(slow);
        }

        string reverseWords(string s) {
            // 移除多餘空格
            removeExtraSpaces(s);

            // 字串全部反轉
            reverseString(s, 0, s.size() - 1);

            // 單字起始位址
            int start = 0;

            // 反轉單字
            for (int i = 0; i <= s.size(); i++) {
                // 當有空格或到達字串尾端時，反轉單字
                if (s[i] == ' ' || i == s.size()) {
                    reverseString(s, start, i - 1);

                    // 當前為空格，表示下一個 index 為單字開頭
                    start = i + 1;
                }
            }

            return s;
        }
};

int main() {
    Solution sol;

    string s = "  Hello World  ";

    string res = sol.reverseWords(s);

    cout << res << endl;

    return 0;
}