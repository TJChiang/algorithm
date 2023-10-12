#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int slow = 0, fast = 0;
        string result = "";
        while (fast < s.length()) {
            if (s[fast] == ' ') {
                for (int i = fast - 1; i >= slow; i--) {
                    result += s[i];
                }
                result += ' ';
                slow = ++fast;
                continue;
            }

            if (fast == s.length() - 1) {
                for (int i = fast; i >= slow; i--) {
                    result += s[i];
                }
                slow = ++fast;
                continue;
            }
            fast++;
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    string s1 = "Let's take LeetCode contest";
    string s2 = "God Ding";
    string result = sol.reverseWords(s1);

    cout << result << endl;

    return 0;
}