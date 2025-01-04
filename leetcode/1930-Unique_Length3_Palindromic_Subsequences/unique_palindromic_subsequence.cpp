#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        // 取得 s 中，所有不重複的字元
        for (char c : s) {
            letters.insert(c);
        }

        int result = 0;
        for (char letter : letters) {
            int left = -1; // 左邊初始邊界 index -> 'a' x  a
            int right = 0; // 右邊結束邊界 index ->  a  x 'a'

            for (int i = 0; i < s.size(); i++) {
                if (s[i] == letter) {
                    // 設定左邊 index
                    if (left == -1) {
                        left = i;
                    }

                    // 設定右邊 index
                    right = i;
                }
            }

            unordered_set<char> between;
            for (int i = left + 1; i < right; i++) {
                between.insert(s[i]);
            }

            result += between.size();
        }

        return result;
    }
};

class Solution2 {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first = vector(26, -1); // 紀錄每個字母初始 index，未出現為 -1
        vector<int> last = vector(26, -1); // 紀錄每個字母最後 index，未出現為 -1

        for (int i = 0; i < s.size(); i++) {
            int cur = s[i] - 'a';
            // 紀錄 s 內字母的起始 index
            if (first[cur] == -1) {
                first[cur] = i;
            }
            last[cur] = i;
        }

        int result = 0;
        for (int i = 0; i < 26; i++) {
            // 未出現的字母則跳過
            if (first[i] == -1) {
                continue;
            }

            // 紀錄位於初始 index 與 最後 index 之間，所有不重複的字母
            unordered_set<char> between;
            for (int j = first[i] + 1; j < last[i]; j++) {
                between.insert(s[j]);
            }

            // 中間不重複字母的數量，即為回文子集數量
            result += between.size();
        }

        return result;
    }
};

int main(int argc, char* argv[])
{
    vector<string> tests = {"aabca", "abc", "bbcbaba"};

    Solution sol;

    for (auto t : tests) {
        cout << "Input: " << t << endl;
        cout << "Output: " << sol.countPalindromicSubsequence(t) << endl;
        cout << "################" << endl;
    }

    return 0;
}
