#include <iostream>
#include <fstream>
#include <cmath>

#include "develop.h"

using namespace std;

int log_ab(int a, unsigned int b) {
    return static_cast<int>(ceil(log(b) / log(a)));
}

bool is_palindrom(unsigned int n, int digit) {
    int length = log_ab(digit, n);
    int *buff = new int[length];
    int buff_i = 0;

    while (n) {
        buff[buff_i++] = n % digit;
        n /= digit;
    }
    print_arr(buff, buff_i);
//    cout << length << endl;
    delete[] buff;
    return false;
}

int main() {
    unsigned int digits[14] = {0x11121314, 0x15161718, 0x191a1b1c, 0x1d1e1f20, 0x21222324, 0x25262728, 0x292a2b2c,
                               0x2d2e2f30, 0x31323334, 0x35363738, 0x393a3b3c, 0x3d3e3f40, 0x90a0b0c, 0xd0e0f10};
    ifstream in("input.txt");
    unsigned int test_case, n;
    for (in >> test_case; 0 < test_case; test_case--) {
        in >> n;
        is_palindrom(n, 10);
    }

//    for (auto h:digits) {
//        for (auto _k = 4; 0 < _k; _k--) {
//            auto n = 0xFF & h;
//            if (n == 0) break;
//            h = h >> 8;
//
//            cout << n << endl;
//        }
//    }
    return 0;
}