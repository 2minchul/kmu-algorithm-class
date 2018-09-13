#include <iostream>
#include <fstream>

using namespace std;

int fibonacci(unsigned int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    return fibonacci(n - 2) + fibonacci(n - 1);
}

int main() {
    ifstream in("input.txt");
    int test_case;
    for (in >> test_case; 0 < test_case; test_case--) {
        unsigned int n;
        in >> n;
        cout << fibonacci(n) << endl;
    }

    return 0;
}