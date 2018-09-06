#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ifstream in("input.txt");
    int test_case = 0;

    for (in >> test_case; 0 < test_case; test_case--) {
        int a, b, x = 0;
        in >> a >> b;
        while (a != 1) {
            if (b % a == 0) {
                b = b / a;
                break;
            } else {
                x = static_cast<int>(floor((a + b) / a));
            }

            a = a * x - b;
            b = b * x;
        }
        cout << b << endl;

    }

    return 0;
}