#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void reverseString(vector<char>& s) {
            for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
                swap(s[i], s[j]);
            }
        }
};

int main()
{
    vector<char> input = {'h', 'e', 'l', 'l', 'o'};
    Solution* sol = new Solution();
    sol->reverseString(input);
    for (auto i : input) {
        cout << i << " ";
    }
    return 0;
}