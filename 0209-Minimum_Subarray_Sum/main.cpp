#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int result = INT32_MAX;
            int sum = 0;
            int length = 0;
            for (int i = 0; i < nums.size(); i++) {
                sum = 0;
                for (int j = i; j < nums.size(); j++) {
                    sum += nums[j];
                    if (sum >= target) {
                        length = j - i + 1;
                        result = result < length ? result : length;
                        break;
                    }
                }
            }

            return result == INT32_MAX ? 0 : result;
        }
};

int main()
{
    Solution sol;

    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};
    int result = sol.minSubArrayLen(target, nums);
    cout << result << endl;
    return 0;
}