#include <iostream>
#include <cstring>

using namespace std;

class Solution {
    public:
        string replaceSpace(string s) {
            // 計算空格數
            int count = 0;

            // 原本字串長度
            int originSize = s.size();

            for (int i = 0; i < s.size(); i++) {
                if (s[i] == ' ') {
                    count++;
                }
            }

            // 擴展 s 字串長度
            s.resize(s.size() + count * 2);

            // 新字串長度
            int newSize = s.size();

            for (int slow = newSize - 1, fast = originSize - 1; fast < slow; slow--, fast--) {
                // 原字串遇到空格則進行轉換
                if (s[fast] == ' ') {
                    s[slow--] = '0';
                    s[slow--] = '2';
                    s[slow] = '%';
                    continue;
                }

                // 非空格，則複製原字串的字
                s[slow] = s[fast];
            }

            return s;
        }
};

int main()
{
    Solution sol;

    string s = "We are happy.";

    string res = sol.replaceSpace(s);

    cout << res << endl;

    return 0;
}