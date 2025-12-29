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

    string reverseWords2(string s) {
        int start = 0;
        int end = 0;
        int size = s.length();

        while (end < size) {
            while (end < size && s[end] != ' ') {
                end++;
            }

            reverse(s.begin() + start, s.begin() + end);

            while (end < size && s[end] == ' ') {
                end++;
            }

            start = end;
        }

        return s;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    string s1 = "Let's take LeetCode contest";
    string s2 = "God Ding";
    string result = sol.reverseWords(s1);
    string result2 = sol.reverseWords2(s2);

    cout << result << endl;
    cout << result2 << endl;

    return 0;
}