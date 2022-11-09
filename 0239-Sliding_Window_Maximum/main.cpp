#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <deque>

using namespace std;

class Solution {
private:
    class MyQueue {
        public:
            deque<int> que;
            void pop(int value) {
                if (!que.empty() && value == que.front()) {
                    que.pop_front();
                }
            }
            void push(int value) {
                while (!que.empty() && value > que.front()) {
                    que.pop_back();
                }
                que.push_back(value);
            }
            int front() {
                return que.front();
            }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }

        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> result;

    result = sol.maxSlidingWindow(nums, k);

    for (auto it = result.begin(); it != result.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}
