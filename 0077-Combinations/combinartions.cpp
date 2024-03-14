#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

    void bfs(int const& n, int const& k, int const& startIndex) {
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

    for (auto & it : result) {
        for (int const& sub : it) {
            cout << sub << " ";
        }
        cout << endl;
    }

    return 0;
}
