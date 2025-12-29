#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        // 雙指標，大的先放新陣列右邊
        vector<int> sortedSquares(vector<int>& nums) {
            int n = nums.size() - 1;
            vector<int> result(nums.size(), 0);

            for (int left = 0, right = n; left <= right;) {
                if (nums[right] * nums[right] > nums[left] * nums[left]) {
                    result[n--] = nums[right] * nums[right];
                    right--;
                } else {
                    result[n--] = nums[left] * nums[left];
                    left++;
                }
            }

            return result;
        }

        // 暴力破解 => 迴圈平方再排序
        vector<int> sortedSquaresLegacy(vector<int>& nums) {
            for (int i = 0; i < nums.size(); i++) {
                nums[i] *= nums[i];
            }

            // 快速排序
            sort(nums.begin(), nums.end());

            return nums;
        }
};

int main()
{
    Solution sol;

    vector<int> nums {-4, -1, 0, 3, 10};

    vector<int> result = sol.sortedSquares(nums);

    for (auto it = result.begin(); it != result.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}