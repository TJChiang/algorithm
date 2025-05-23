#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class BruteForce {
public:
    vector<int> minOperations(string boxes) {
        vector<int> answer(boxes.size());
        for (int i = 0; i < boxes.size(); i++) {
            if (boxes[i] == '1') {
                // 如果值是 1 ，則遍歷所有欄位，紀錄 j 位址與 i 的距離，並累加
                for (int j = 0; j < boxes.size(); j++) {
                    answer[j] += abs(j - i);
                }
            }
        }

        return answer;
    }
};

class Advanced {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size(), 0);

        int ballsToLeft = 0, movesToLeft = 0;
        int ballsToRight = 0, movesToRight = 0;

        for (int i = 0; i < boxes.size(); i++) {
            // left pass
            ans[i] += movesToLeft;
            ballsToLeft += boxes[i] - '0';
            movesToLeft += ballsToLeft;

            // right pass
            int j = boxes.size() - 1 - i;
            ans[j] += movesToRight;
            ballsToRight += boxes[j] - '0';
            movesToRight += ballsToRight;
        }

        return ans;
    }
};

int main(int argc, char* argv[])
{
    // [11,8,5,4,3,4]
    string boxes = "001011";
    Advanced sol;
    vector<int> result = sol.minOperations(boxes);

    for (int v : result) {
        cout << v << " ";
    }

    return 0;
}
