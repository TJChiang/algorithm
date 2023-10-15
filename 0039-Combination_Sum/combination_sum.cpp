#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> temp;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) {
            result.push_back(temp);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            sum += candidates[i];
            temp.push_back(candidates[i]);
            backtracking(candidates, target, sum, i); // i 不用 +1 ，因為可以重複讀取
            sum -= candidates[i];
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        temp.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    vector<int> ex1 = {2,3,6,7};
    int target1 = 7;
    vector<int> ex2 = {5,2,3};
    int target2 = 8;
    vector<vector<int>> result1 = sol.combinationSum(ex2, target2);

    cout << "[" << endl;
    for (auto v : result1) {
        cout << "\t";
        for (auto r : v) {
            cout << r << " ";
        }
        cout << endl;
    }
    cout << "]" << endl;

    return 0;
}