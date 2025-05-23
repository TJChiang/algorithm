#include <iostream>
#include <climits>

using namespace std;

int reverse(int x) {
    int res = 0;
    while(x != 0) {
        if (res > INT_MAX / 10 || res < INT_MIN / 10) return 0;
        res = res * 10 + (x % 10);
        x /= 10;
    }

    return res;
}

int main()
{
    int const& x = 123;
    int const& res = reverse(x);

    cout << res << endl;
    return 0;
}