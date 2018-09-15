#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> eureka_num;

int generate_eureka_num(int n) {
    bool flag = false;
    if (eureka_num.empty()) flag = true;
    else if (*eureka_num.rbegin() < n) flag = true;
    int i = 0;
    if (flag) {
        i = static_cast<int>(eureka_num.size());
        int k = 0;
        while (k < n) {
            ++i;
            k = i * (i + 1) / 2;
            eureka_num.push_back(k);
        }
        if (k == n) return i - 1;
        else return i - 2;
    } else {
        for (auto k:eureka_num) {
            if (k == n) break;
            if (n < k) {
                return i;
            }
            ++i;
        }
        return i;
    }
}

bool is_eureka_sum(int n, int range) {
    int mid = n / 2 + 1;
    int i = 0;
    while (true) {
        auto a = eureka_num.at(i++);
        if (mid < a) break;

        int b = n - a;
        for (auto _i = range; 0 <= _i; _i--) {
            if (b == eureka_num.at(_i)) return true;
        }
    }
    return false;
}

int main() {
    ifstream in("input.txt");
    eureka_num.reserve(100);
    int test_case;
    for (in >> test_case; 0 < test_case; test_case--) {
        bool result = false;
        int n;
        in >> n;
        auto range = generate_eureka_num(n);
        for (int i = range; 0 <= i; --i) {
            if (is_eureka_sum(n - eureka_num.at(i), range)) {
                result = true;
                break;
            }
        }
        cout << result << endl;
    }
    return 0;
}