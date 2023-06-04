#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
        if (map.count(nums[i]) > 0)
            return {map[nums[i]], i};

        map[target - nums[i]] = i;
    }

    return {};
}

int main()
{
    vector<int> arr = {2,7,11,15};
    int target = 9;
    arr = twoSum(arr, 9);
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        cout << *it << ' ';
        cout << endl;
    }
    return 0;
}