#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> temp_set;
    void backtracking(int k, int n, int sum, int startIndex)
    {
        if (temp_set.size() == k)
        {
            if (sum == n) result.push_back(temp_set);
            return;
        }
        for (int i = startIndex; i <= 9; i++)
        {
            sum += i;
            temp_set.push_back(i);
            backtracking(k, n, sum, i + 1);
            sum -= i;
            temp_set.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        temp_set.clear();
        backtracking(k, n, 0, 1);
        return result;
    }
};

void show_result(vector<vector<int>> result)
{
    cout << "[";
    for (const vector<int>& res : result)
    {
        cout << "[";
        for (const int i : res)
        {
            cout << i << " ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
}

int main(int argc, char* argv[])
{
    Solution sol;
    show_result(sol.combinationSum3(3, 7));
    show_result(sol.combinationSum3(3, 9));
    show_result(sol.combinationSum3(4, 1));

    return 0;
}
