#include <iostream>
#include <vector>

using namespace std;

// 題目要求為：若 words2 所有字串皆為 words1 中其中一個字串的子集，則輸出該 word1
// 表示 word1 內的字母可以滿足所有 words2 的字母
// 因此可以設定一個字母表，計算 words2 每個字母的最大數量
class Solution {
public:
    vector<string> wordSubsets(const vector<string>& words1, const vector<string>& words2) {
        // words2 所有字串的字母最大數量表
        int maxCount[26] = {0};
        for (const string& word : words2) {
            // 單個字串的字母數量表
            int count[26] = {0};
            // 計算單個字串的字母數
            for (const char c : word) {
                count[c - 'a']++;
            }
            // 取最大值同步至 maxCount
            for (int i = 0; i < 26; i++) {
                maxCount[i] = max(maxCount[i], count[i]);
            }
        }

        vector<string> result;
        for (const string& word : words1) {
            // words1 單個字串的字母數量表
            int count[26] = {0};
            // 計算單個字串的字母數
            for (const char c : word) {
                count[c - 'a']++;
            }

            bool isUniversal = true;
            for (int i = 0; i < 26; i++) {
                // word1 不能滿足所有 words2 字母，表示 words2 不是子集
                if (count[i] < maxCount[i]) {
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal) {
                result.push_back(word);
            }
        }

        return result;
    }
};

int main(int argc, char* argv[])
{
    // ["facebook","google","leetcode"]
    // const vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
    // const vector<string> words2 = {"e","o"};

    // ["google","leetcode"]
    vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
    vector<string> words2 = {"lo","eo"};
    Solution sol;
    const vector<string> result = sol.wordSubsets(words1, words2);
    for (const string& s : result) {
      cout << s << " ";
    }

    return 0;
}
