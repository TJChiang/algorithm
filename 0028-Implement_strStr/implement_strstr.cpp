#include <iostream>

using namespace std;

class Solution {
    private:
        void getNext(int* next, const string& s) {
            int j = -1;
            next[0] = j;

            for (int i = 1; i < s.size(); i++) {
                while (j >= 0 && s[i] != s[j + 1]) {
                    j = next[j];
                }

                if (s[i] == s[j + 1]) {
                    j++;
                }

                next[i] = j;
            }
        }

    public:
        int strStrKMP(string haystack, string needle) {
            if (needle.size() == 0) {
                return 0;
            }

            int next[needle.size()];
            getNext(next, needle);
            int j = -1;
            for (int i = 0; i < haystack.size(); i++) {
                while(j >= 0 && haystack[i] != needle[j + 1]) {
                    j = next[j];
                }

                if (haystack[i] == needle[j + 1]) {
                    j++;
                }

                if (j == (needle.size() - 1)) {
                    return i - needle.size() + 1;
                }
            }

            return -1;
        }

        int strStr(string haystack, string needle) {
            int n = haystack.size();
            int m = needle.size();

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i + j > n)
                        break;
                    if (haystack[j + i] != needle[j])
                        break;

                    if (j == m - 1) return i;
                }
            }

            return -1;
        }
};

int main() {
    Solution sol;
    string haystack = "hello";
    string needle = "ll";

    int res = sol.strStr(haystack, needle);

    cout << res << endl;

    return 0;
}