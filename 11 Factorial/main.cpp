#include <iostream>
#include <fstream>

using namespace std;

int factorial(unsigned int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    ifstream in("input.txt");
    int test_case;
    for (in >> test_case; 0 < test_case; test_case--) {
        unsigned int n;
        in >> n;
        cout << factorial(n) << endl;
    }

    return 0;
}