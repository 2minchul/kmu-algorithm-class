#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int log_ab(int a, unsigned int b) {
    return static_cast<int>(ceil(log(b) / log(a)));
}

bool is_palindrom(unsigned int n, int digit) {
    auto length = log_ab(digit, n);
    auto mid = length / 2;
    int *buff = new int[mid];
    auto buff_i = 0;
    bool result = true;

    for (auto _ = mid; 0 < _; _--) {
        buff[buff_i++] = n % digit;
        n /= digit;
    }

    if (length & 1) n /= digit;
    buff_i--;

    while (0 <= buff_i) {
        if (buff[buff_i--] != n % digit) {
            result = false;
            break;
        }
        n /= digit;
    }

    delete[] buff;
    return result;
}

int main() {
    ifstream in("input.txt");
    unsigned int test_case, n;
    for (in >> test_case; 0 < test_case; test_case--) {
        bool result = false;
        in >> n;

        for (auto digit = 64; 1 < digit; digit--) {
            result = is_palindrom(n, digit);
            if (result) break;
        }

        cout << result << endl;
    }
    return 0;
}