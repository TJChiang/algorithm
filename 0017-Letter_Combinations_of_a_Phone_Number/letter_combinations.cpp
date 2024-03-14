#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    const string letterMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };
public:
    vector<string> result;
    string s;
    void bfs(const string& digits, int index) {
        if (index == digits.size()) {
            result.push_back(s);
            return;
        }

        int digit = digits[index] - '0';
        string letters = letterMap[digit];

        for (char letter : letters) {
            s.push_back(letter);
            bfs(digits, index + 1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(const string& digits) {
        if (digits.empty()) return result;
        s.clear();
        result.clear();

        bfs(digits, 0);
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    vector<string> result = sol.letterCombinations("23");

    for (const auto& it : result) {
        cout << it << " ";
    }

    return 0;
}