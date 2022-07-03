#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> input;
    stack<int> output;

    MyQueue() {}

    /**
     * @brief 從佇列最後方加入 x
     *
     * @param x
     */
    void push(int x) {
        input.push(x);
    }

    /**
     * @brief 移除並取得佇列最前方元素
     *
     * @return int
     */
    int pop() {
        int result = this->peek();
        output.pop();
        return result;
    }

    /**
     * @brief 取得佇列最前方元素
     *
     * @return int
     */
    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    /**
     * @brief 佇列是否為空
     *
     * @return true
     * @return false
     */
    bool empty() {
        return input.empty() && output.empty();
    }
};

int main() {
    return 0;
}
