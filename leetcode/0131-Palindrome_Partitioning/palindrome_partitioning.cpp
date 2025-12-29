#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    vector<string> temp;
    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
    void backtracking(const string& s, int startIndex) {
        if (startIndex >= s.size()) {
            result.push_back(temp);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (!isPalindrome(s, startIndex, i)) continue;

            string str = s.substr(startIndex, i - startIndex + 1);
            temp.push_back(str);
            backtracking(s, i + 1);
            temp.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        result.clear();
        temp.clear();
        backtracking(s, 0);
        return result;
    }
};

class Solution2 {
private:
    vector<vector<string>> result;
    vector<string> temp;
    vector<vector<bool>> isPalindrome;
    void backtracking(const string& s, int startIndex) {
        if (startIndex >= s.size()) {
            result.push_back(temp);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (!isPalindrome[startIndex][i]) continue;

            string str = s.substr(startIndex, i - startIndex + 1);
            temp.push_back(str);
            backtracking(s, i + 1);
            temp.pop_back();
        }
    }
    void computePalindrome(const string& s) {
        isPalindrome.resize(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (j == i) isPalindrome[i][j] = true;
                else if (j - i == 1) isPalindrome[i][j] = (s[i] == s[j]);
                else isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i+1][j-1]);
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        result.clear();
        temp.clear();
        computePalindrome(s);
        backtracking(s, 0);
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    string s1 = "aab";
    string s2 = "a";

    vector<vector<string>> result = sol.partition(s1);

    cout << "[" << endl;
    for (auto v : result) {
        cout << "\t";
        for (auto r : v) {
            cout << r << " ";
        }
        cout << endl;
    }
    cout << "]" << endl;

    return 0;
}
