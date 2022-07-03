#include <iostream>
#include <queue>

using namespace std;

// 雙佇列解法
class MyStack {
public:
    queue<int> primary;
    queue<int> backup;

    MyStack() {}

    void push(int x) {
        primary.push(x);
    }

    int pop() {
        int size = primary.size() - 1;
        while (size--) {
            backup.push(primary.front());
            primary.pop();
        }

        int result = primary.front();
        primary.pop();
        primary = backup;
        while (!backup.empty()) {
            backup.pop();
        }
        return result;
    }

    int top() {
        return primary.back();
    }

    bool empty() {
        return primary.empty();
    }
};

// 單佇列解法
class MyStackSingle {
public:
    queue<int> que;

    MyStackSingle() {}

    void push(int x) {
        que.push(x);
        for (int i = 0; i < que.size() - 1; i++) {
            que.push(que.front());
            que.pop();
        }
    }

    int pop() {
        int result = que.front();
        que.pop();
        return result;
    }

    int top() {
        return que.front();
    }

    bool empty() {
        return que.empty();
    }
};

int main() {
    return 0;
}