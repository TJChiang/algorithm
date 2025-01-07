#include <iostream>
#include <vector>

using namespace std;

class KMP {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> answer;

        for (int curr = 0; curr < words.size(); curr++) {
            vector<int> lps = computeLPSArray(words[curr]);

            for (int other = 0; other < words.size(); other++) {
                if (curr == other) continue;

                if (isString(words[curr], words[other], lps)) {
                    answer.push_back(words[curr]);
                    break;
                }
            }
        }

        return answer;
    }
private:
    vector<int> computeLPSArray(string& sub) {
        vector<int> lps(sub.size(), 0);
        int currentIndex = 1; // 當前 array 的 index ，從 1 開始，因為會取前一個 index 的值作為回退的起始點
        int length = 0; // 從 0 到 n 的 lps 長度

        while (currentIndex < sub.size()) {
            if (sub[currentIndex] == sub[length]) {
                length++;
                lps[currentIndex] = length;
                currentIndex++;
            } else {
                if (length > 0) length = lps[length - 1]; // 回退到前一個 index 的值，再做判斷
                else currentIndex++; // 如果回退至 length == 0 無法再退，表示都不符合，則 current 往前以計算後續 lps
            }
        }

        return lps;
    }
    bool isString(string& sub, string& main, vector<int>& lps) {
        int mainIndex = 0;
        int subIndex = 0;

        while (mainIndex < main.size()) {
            if (main[mainIndex] == sub[subIndex]) {
                // 字符一樣，則往下一筆的字元確認
                mainIndex++;
                subIndex++;
                if (subIndex == sub.size()) return true; // 表示子字串所有字符比對一致
            } else {
                if (subIndex > 0) subIndex = lps[subIndex - 1]; // 回退至前一筆 index 的值，繼續比對
                else mainIndex++; // 無法再回退，繼續往後比對
            }
        }

        return false;
    }
};

int main(int argc, char* argv[])
{
    // ["as", "hero"]
    vector<string> words = {"mass","as","hero","superhero"};
    KMP sol;
    vector<string> result = sol.stringMatching(words);
    for (string word : result) {
      cout << word << " ";
    }

    return 0;
}
