#include <iostream>
#include <fstream>

using namespace std;

bool is_palindrome(string *str, unsigned long begin, unsigned long end) {
    if (str->at(begin) != str->at(end)) return false;
    if (end - begin <= 1) return true;
    return is_palindrome(str, begin + 1, end - 1);
}

int main() {

    ifstream in("input.txt");
    int test_case;
    for (in >> test_case; 0 < test_case; test_case--) {
        string str;
        in >> str;
        cout << is_palindrome(&str, 0, str.size() - 1) << endl;
    }

    return 0;
}