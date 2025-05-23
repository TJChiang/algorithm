#include <iostream>

using namespace std;

class Normal {
public:
    int minimizeXor(int num1, int num2) {
        int result = num1;

        int targetSetBitsCount = __builtin_popcount(num2);
        int setBitsCount = __builtin_popcount(result);

        int currentBit = 0;

        while (setBitsCount < targetSetBitsCount) {
            if (!isSet(result, currentBit)) {
                setBit(result, currentBit);
                setBitsCount++;
            }

            currentBit++;
        }

        while (setBitsCount > targetSetBitsCount) {
            if (isSet(result, currentBit)) {
                unsetBit(result, currentBit);
                setBitsCount--;
            }

            currentBit++;
        }

        return result;
    }
private:
    // 要確認 x 的第 n 個 bit 是否為 1 ，只要對第 n 個 bit 跟 1 做 and 即可
    bool isSet(int x, int n) { return x & (1 << n); }

    // 要設定 x 的第 n 個 bit 為 1 ，只要對第 n 個 bit 跟 1 做 or 即可
    void setBit(int& x, int n) { x |= (1 << n); }

    // 要設定 x 的第 n 個 bit 為 0 ，只要對第 n 個 bit 跟 0 做 and 即可
    // 但為了讓其他 bit 為原來的值， x 其餘的值要跟 1 做 and
    // 因此， mask 的第 n 個 bit 先為 1 ，再做倒數 => 001000 -> 110111
    // 最後 mask 再跟 x 做 and
    void unsetBit(int& x, int n) { x &= ~(1 << n); }
};

class Advanced {
public:
    int minimizeXor(int num1, int num2) {
        // 計算設定 bits num2 的位元數
        int bits = countSetBits(num2);
        int result = 0;

        for (int i = 31; i >= 0 && bits > 0; i--) {
            if (num1 & (1 << i)) {
                result |= (1 << i);
                bits--;
            }
        }

        for (int i = 0; i < 32 && bits > 0; i++) {
            if (!(result & (1 << i))) {
                result |= (1 << i);
                bits--;
            }
        }

        return result;
    }
private:
    int countSetBits(int n) {
        int count = 0;

        while (n) {
            count += n & 1;
            n >>= 1;
        }

        return count;
    }
};

int main(int argc, char* argv[])
{
    constexpr int num1 = 3, num2 = 5; // 3
    // int num1 = 1, num2 = 12; // 3

    Normal sol;
    cout << sol.minimizeXor(num1, num2) << endl;

    return 0;
}
