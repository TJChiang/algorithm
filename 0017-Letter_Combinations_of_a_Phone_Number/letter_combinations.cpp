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

        for (int i = 0; i < letters.size(); i ++) {
            s.push_back(letters[i]);
            bfs(digits, index + 1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return result;
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

    for (auto it : result) {
        cout << it << " ";
    }

    return 0;
}