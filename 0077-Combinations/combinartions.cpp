#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

    void bfs(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i <= n; i++) {
            // 優化
            if (i > n - (k - path.size()) + 1) break;

            path.push_back(i);
            bfs(n, k, i + 1);
            path.pop_back();
        }

        return;
    }

    vector<vector<int>> combine(int n, int k) {
        bfs(n, k, 1);
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;

    vector<vector<int>> result = sol.combine(4, 2);

    for (auto it = result.begin(); it != result.end(); it++) {
        for (auto sub = (*it).begin(); sub != (*it).end(); sub++) {
            cout << *sub << " ";
        }
        cout << endl;
    }

    return 0;
}
