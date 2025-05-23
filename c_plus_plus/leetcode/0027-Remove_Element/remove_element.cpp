#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief 暴力解法
 *
 * @param nums
 * @param val
 * @return int
 */
int removeElementByOrigin(vector<int>& nums, int val)
{
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        if (nums[i] == val) {
            for (int j = i + 1; j < size; j++) {
                nums[j - 1] = nums[j];
            }
            i--;
            size--;
        }
    }

    return size;
}

/**
 * @brief 快慢指針
 *
 * @param nums
 * @param val
 * @return int
 */
int removeElementByFnSP(vector<int>& nums, int val)
{
    int slow = 0;
    for (int fast = 0; fast < nums.size(); fast++) {
        if (nums[fast] != val) {
            nums[slow] = nums[fast];
            slow++;
        }
    }

    return slow;
}

void printResult(vector<int> vec)
{
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << endl;
    }
    return;
}

int main()
{
    vector<int> nums = {0,1,2,2,3,0,4,2};
    vector<int> nums2 = {};
    int val = 2, val2 = 0;

    int res = removeElementByOrigin(nums, val);
    cout << res << endl;
    return 0;
}