#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> temp;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
        if (sum == target) {
            result.push_back(temp);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            if (i > 0 && candidates[i - 1] == candidates[i] && used[i - 1] == false) continue;
            sum += candidates[i];
            temp.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, sum, i + 1, used);
            used[i] = false;
            sum -= candidates[i];
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//      used 標示各 index 元素是否被使用
//      若 candidates[i] == candidates[i - 1] 表示有重複元素 (需先排序)，此時 used 狀態不同：
//      used[i - 1] = false => 正常來說前一個應該被先用過，但這時狀態告訴我們前一個沒被用到，表示這是回溯而來，candidates[i] 重複了，其他組合用過了，應該略過
//      used[i - 1] = true  => 表示 candidates[i] 更深一層的遞迴，可以加上去作為新的組合
        vector<bool> used(candidates.size(), false);
        result.clear();
        temp.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);
        return result;
    }
};

class Solution2 {
private:
    vector<vector<int>> result;
    vector<int> temp;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) {
            result.push_back(temp);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
//          若不使用 used 紀錄使用狀態， 可以使用 i > startIndex 表示 candidates[i] 回溯而來的，即視為 candidates[i] 重複，不可使用
            if (i > startIndex && candidates[i] == candidates[i - 1]) continue;
            sum += candidates[i];
            temp.push_back(candidates[i]);
            backtracking(candidates, target, sum, i + 1);
            sum -= candidates[i];
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.clear();
        temp.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution2 sol;
    vector<int> ex1 = {10,1,2,7,6,1,5};
    int target1 = 8;
    vector<int> ex2 = {2,5,2,1,2};
    int target2 = 5;
    vector<vector<int>> result1 = sol.combinationSum2(ex1, target1);

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
