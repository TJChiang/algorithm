#include <iostream>
#include <vector>

using namespace std;

class FrequencyCounting {
public:
    static vector<int> findThePrefixCommonArray(const vector<int>& A, const vector<int>& B) {
        const int n = A.size();
        vector<int> result(A.size(), 0);
        vector<int> frequency(A.size() + 1, 0); // 每個數字 (frequency 的 index) 出現次數
        int common = 0;

        for (int i = 0; i < n; i++) {
            frequency[A[i]]++;
            if (frequency[A[i]] == 2) common++; // 該次數有兩個，表示 A 和 B 有共同的元素， common+1
            frequency[B[i]]++;
            if (frequency[B[i]] == 2) common++; // 該次數有兩個，表示 A 和 B 有共同的元素， common+1
            result[i] = common; // 表示這個 index 的共通數量
        }

        return result;
    }
};

class Bitmasking {
public:
    static vector<int> findThePrefixCommonArray(const vector<int>& A, const vector<int>& B) {
        const int n = A.size();
        vector<int> result(A.size(), 0);
        vector<int> frequency(A.size() + 1, 0); // 每個數字 (frequency 的 index) 出現次數
        int common = 0;

        for (int i = 0; i < n; i++) {
            frequency[A[i]]++;
            if (frequency[A[i]] == 2) common++; // 該次數有兩個，表示 A 和 B 有共同的元素， common+1
            frequency[B[i]]++;
            if (frequency[B[i]] == 2) common++; // 該次數有兩個，表示 A 和 B 有共同的元素， common+1
            result[i] = common; // 表示這個 index 的共通數量
        }

        return result;
    }
};

int main(int argc, char* argv[])
{
    // [0, 2, 3, 4]
    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};
    const vector<int> result = FrequencyCounting::findThePrefixCommonArray(A, B);

    // [0, 1, 3]
    // vector<int> A = {2, 3, 1};
    // vector<int> B = {3, 1, 2};
    // const vector<int> result = Bitmasking::findThePrefixCommonArray(A, B);

    for(const int i : result) {
        cout << i << " ";
    }

    return 0;
}
