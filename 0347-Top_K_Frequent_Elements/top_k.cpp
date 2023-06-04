#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    class myComparison {
        public:
            bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
                return lhs.second > rhs.second;
            }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]++];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, myComparison> pri_que;

        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) {
                pri_que.pop();
            }

            vector<int> result(k);
            for (int i = k - 1; i >= 0; i--) {
                result[i] = pri_que.top().first;
                pri_que.pop();
            }
            return result;
        }
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    vector<int> result = sol.topKFrequent(nums, k);
    for (auto it = result.begin(); it != result.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}
