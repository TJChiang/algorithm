#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int minimumLength(const string& s) {
        vector<int> charFrequency(26, 0);
        int total = 0;
        for (const char c : s) charFrequency[c - 'a']++;

        for (const int frequency : charFrequency) {
            if (frequency == 0) continue;

            if (frequency % 2 == 0) total += 2;
            else total += 1;
        }

        return total;
    }
};

int main(int argc, char* argv[])
{
    vector<string> testCases = {
        "abaacbcbb", // 5 - "acbcb"
        "aa" // 2
    };

    for (const string& s : testCases) {
        cout << "result: " << Solution::minimumLength(s) << endl;
    }

    return 0;
}
