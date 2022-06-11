#include <iostream>
#include <vector>

using namespace std;

// [left, right]
int binarySearch(vector<int> nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        // 防止溢出
        int mid = left + ((right - left) / 2);
        if (target == nums[mid]) return mid;
        else if (target > nums[mid]) left = ++mid;
        else if (target < nums[mid]) right = --mid;
    }

    return -1;
}

// [left, right)
int binarySearchWithRightOpen(vector<int> nums, int target) {
    int left = 0;
    int right = nums.size(); // <- 右開區間，不需要 -1

    while (left < right) {
        // 防止溢出
        int mid = left + ((right - left) / 2);
        if (target == nums[mid]) return mid;
        else if (target > nums[mid]) left = ++mid;
        else if (target < nums[mid]) right = --mid;
    }

    return -1;
}

int main()
{
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    int index = binarySearch(nums, target);

    cout << index << endl;

    return 0;
}