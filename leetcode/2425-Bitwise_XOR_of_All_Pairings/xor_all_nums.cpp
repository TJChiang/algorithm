#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class HashMap {
public:
    static int xorAllNums(const vector<int>& nums1, const vector<int>& nums2) {
        const int len1 = nums1.size();
        const int len2 = nums2.size();

        // 紀錄數字出現的次數
        unordered_map<int, long> freq;
        for (const int& num : nums1) {
            // nums1 的數字會跟 nums2 的每一個做 xor ，所以是加上 num2 的長度
            freq[num] += len2;
        }
        for (const int& num : nums2) {
            // nums2 的數字會跟 nums1 的每一個做 xor ，所以是加上 num1 的長度
            freq[num] += len1;
        }

        int result = 0;
        for (auto& [num, count] : freq) {
            // 最後等於每個的元素做 xor ，所以只要找出現次數為奇數的數字做 xor 即可
            // 出現偶數次的元素做 xor 會等於 0 (x xor x = 0)
            if (count % 2 == 1) result ^= num;
        }

        return result;
    }
};

class BitManipulation {
public:
    static int xorAllNums(const vector<int>& nums1, const vector<int>& nums2) {
        const int len1 = nums1.size();
        const int len2 = nums2.size();

        int xor1 = 0;
        int xor2 = 0;

        // 若 len2 長度為奇數，表示最後所有 nums1 出現的次數為奇數
        // 這樣就不會出現 x xor x = 0 的情況
        if (len2 % 2 == 1) {
            for (const int& num : nums1) {
                xor1 ^= num;
            }
        }

        // 若 len1 長度為奇數，表示最後所有 nums2 出現的次數為奇數
        // 這樣就不會出現 x xor x = 0 的情況
        if (len1 % 2 == 1) {
            for (const int& num : nums2) {
                xor2 ^= num;
            }
        }

        return xor1 ^ xor2;
    }
};

/**
 * key point:
 * - x xor 0 會等於自己 x
 * - x xor x 會等於 0
 */
int main(int argc, char* argv[])
{
    // 13
    const vector<int> nums1 = {2,1,3};
    const vector<int> nums2 = {10,2,5,0};

    // 0
    // const vector<int> nums1 = {1,2};
    // const vector<int> nums2 = {3,4};

    cout << HashMap::xorAllNums(nums1, nums2) << endl;

    return 0;
}
