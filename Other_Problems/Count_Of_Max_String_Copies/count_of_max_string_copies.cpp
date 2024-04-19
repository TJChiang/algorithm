// Given the string S and the list L consisting of K strings,
// returns the maximum number of copies a string from L that can be built only using letters from S.
#include <iostream>
#include <vector>
#include <unordered_map>

int maxStringCopies(const std::string& S, const std::vector<std::string>& L) {
    std::unordered_map<char, int> countS, countL;
    int max = 0;

    // map 存入 S 每個字母與其出現次數
    for (const char ch : S) {
        countS[ch]++;
    }

    for (const std::string& word : L) {
        // 單字比 S 還長，一定不符合
        if (word.length() > S.length()) continue;
        countL.clear();

        // map 存入 L單字 每個字母與其出現次數
        for (const char ch : word) {
            countL[ch]++;
        }

        int min = INT32_MAX;
        for (auto& it : countL) {
            char ch = it.first;
            const int count = it.second;
            // S 找不到字母，一定不符合，換下個單字
            if (countS.find(ch) == countS.end()) {
                min = 0;
                break;
            }

            min = std::min(min, countS[ch] / count);
        }
        max = std::max(max, min);
    }
    return max;
}

int main() {
    const std::string S1 = "CAT";
    std::vector<std::string> L1 = {"CATS", "MANYCATS"};
    std::cout << "Result1: " << maxStringCopies(S1, L1) << std::endl;

    const std::string S2 = "abbbcdef";
    const std::vector<std::string> L2 = {"abc", "bcd", "e", "ef", "f", "aaabbbccc"};
    std::cout << "Result2: " << maxStringCopies(S2, L2) << std::endl;
    return 0;
}
