#include <iostream>
#include <vector>

using namespace std;

/**
 * derived[0] = origin[0] XOR origin[1]
 * derived[1] = origin[1] XOR origin[2]
 * ...
 * derived[n - 1] = origin[n - 1] XOR origin[0]
 *
 * 表示 derived 所有元素做 XOR 會等於 0 => derived[0] ^ derived[1] ^ ... ^ derived[n - 1]
 * 因為 origin 的每個元素都會跟自己做一次 XOR ，而自己與自己做 XOR 會等於 0
 * 最後變成 0 ^ 0 ^ ... ^ 0 = 0
 *
 * 如果 derived 的元素是合法的，那麼全部做 XOR 應該會等於 0
 */
class Solution {
public:
    static bool doesValidArrayExist(vector<int>& derived) {
        int x = 0;
        for (const auto i : derived) {
            x ^= i;
        }

        return x == 0;
    }
};

int main(int argc, char* argv[])
{
    vector<int> derived = {1,1,0}; // true
//    vector<int> derived = {1,1}; // true
//    vector<int> derived = {1,0}; // false

    cout << Solution::doesValidArrayExist(derived) << endl;

    return 0;
}
