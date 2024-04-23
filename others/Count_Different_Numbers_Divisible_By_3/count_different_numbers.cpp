#include <iostream>
#include <cstring>

// https://www.geeksforgeeks.org/count-of-different-numbers-divisible-by-3-that-can-be-obtained-by-changing-at-most-one-digit/

// 字串中的所有數字相加後，若可被 3 整除，即為 3 的倍數
int findCount(const std::string& nums) {
    int count = 0;
    int sum = 0;

    for (char const ch : nums) {
        sum += ch - '0';
    }

    if (sum % 3 == 0) count++;

    for (char const ch : nums) {
        const int target = ch - '0';
        const int remain = sum - target;

        for (int i = 0; i <= 9; ++i) {
            if (i != target && (remain + i) % 3 == 0) count++;
        }
    }

    return count;
}

int main() {
    const std::string input = "23";

    std::cout << "Count: " << findCount(input) << std::endl;
    return 0;
}
