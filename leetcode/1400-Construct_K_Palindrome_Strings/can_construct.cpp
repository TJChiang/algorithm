#include <iostream>
#include <vector>

using namespace std;

class CountOdd {
public:
    static bool canConstruct(const string& s, const int k) {
        // 處理邊界值
        if (s.size() < k) return false;
        if (s.size() == k) return true;

        vector<int> freq(26, 0);
        int oddCount = 0;

        for (const char c : s) freq[c - 'a']++;

        // 可以形成回文表示一定是 AA 或是 ABA
        // 我們可以取得所有字母出現奇數次的數量
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) oddCount++;
        }

        // 只要小於或等於 k 就表示 s 可以形成 k 個回文
        return oddCount <= k;
    }
    static bool canConstructByBit(const string& s, const int k) {
        // 處理邊界值
        if (s.size() < k) return false;
        if (s.size() == k) return true;

        int oddCount = 0;

        for (const char c : s) oddCount ^= 1 << (c - 'a');

        int setBits = __builtin_popcount(oddCount);

        // 只要小於或等於 k 就表示 s 可以形成 k 個回文
        return setBits <= k;
    }
};

int main(int argc, char* argv[])
{
    // true
    const string s = "annabelle";
    const int k = 2;

    // false
    // const string s = "leetcode";
    // const int k = 3;
    //
    // // true
    // const string s = "true";
    // const int k = 4;

    cout << "result: " << CountOdd::canConstruct(s, k) << endl;

    return 0;
}
