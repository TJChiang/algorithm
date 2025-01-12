#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class StackSolution {
public:
    static bool canBeValid(const string &s, const string &locked) {
        if (s.size() % 2 == 1) return false;

        // 用 stack 紀錄括號與 locked
        stack<int> brackets, unlocked;

        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0') unlocked.push(i); // locked 為 0 表示可以自由變換括號，因此不用管 s[i]
            else if (s[i] == '(') brackets.push(i); // 紀錄做括號
            else if (s[i] == ')') {
                if (!brackets.empty()) brackets.pop(); // 先找左括號 '(' 做匹配
                else if (!unlocked.empty()) unlocked.pop(); // 再找可變換括號匹配
                else return false; // 都沒有表示沒有 '(' 可以匹配，return false
            }
        }

        // 處理尚未匹配的左括號 和 可變動括號
        while (
            !brackets.empty() // 未完成匹配的括號
            && !unlocked.empty() // 可變動的括號
            && brackets.top() < unlocked.top() // 這樣左括號才能找到匹配的右括號
            ) {
            brackets.pop();
            unlocked.pop();
        }

        // 左括號為空則表示完全匹配；反之，還有左括號未完成匹配
        return brackets.empty();
    }
};

class ConstSpaceSolution {
public:
    static bool canBeValid(const string &s, const string &locked) {
        if (s.size() % 2 == 1) return false;
        int brackets = 0;
        int unlocked = 0;

        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0') unlocked++;
            else if (s[i] == '(') brackets++;
            else if (s[i] == ')') {
                if (brackets > 0) brackets--;
                else if (unlocked > 0) unlocked--;
                else return false;
            }
        }

        // 處理左括號和可變動括號
        int balance = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (locked[i] == '0') {
                balance--;
                unlocked--;
            } else if (s[i] == '(') {
                balance++;
                brackets--; // 減除
            } else if (s[i] == ')') {
                balance--; // 右括號已經處理過了，unlocked & brackets 不變動
            }

            if (balance > 0) return false;

            if (unlocked == 0 && brackets == 0) break;
        }

        return brackets <= 0;
    }
};

int main(int argc, char* argv[])
{
    vector<vector<string>> testCases = {
        {"))()))", "010100"}, // true
        {"()()", "0000"}, // true
        {")", "0"} // false
    };

    // for (auto& t : testCases) {
    //     cout << "result: " << StackSolution::canBeValid(t[0], t[1]) << endl;
    // }

    for (auto& t : testCases) {
        cout << "result: " << ConstSpaceSolution::canBeValid(t[0], t[1]) << endl;
    }

    return 0;
}
