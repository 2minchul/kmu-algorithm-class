#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    ifstream in("input.txt");
    int test_case;
    for (in >> test_case; 0 < test_case; --test_case) {
        int m, n;
        in >> m >> n;
        auto vec_size = m * n;
        vector<char> vec((unsigned long) vec_size);
        deque<int> answers;
        for (int i = 0; i < vec_size; ++i) { // insert char into vector
            in >> vec[i];
        }

        auto up = [&m](int &i) -> int { return i - m; };
        auto down = [&m](int &i) -> int { return i + m; };
        auto right = [&m](int &i) -> int {
            auto _i = i + 1;
            if (_i % m == 0) return 0;
            return _i;
        };
        auto left = [&m](int &i) -> int {
            if (i % m == 0) return 0;
            return i - 1;
        };
        auto value_of_ = [&vec, &vec_size](int i) -> char {
            if (0 < i and i < vec_size) {
                return vec[i];
            }
            return 'x';
        };


        for (int i = 0; i < vec_size; ++i) {
            if (vec[i] == '.') {
                queue<int> q;
                q.push(i);
                // start bfs
                int cnt = 0;
                while (!q.empty()) {
                    int _i = q.front();
                    auto &value = vec[_i];
                    if (value != '.') {
                        q.pop();
                        continue;
                    }
                    value = 'x';// checked mark
                    auto idx = up(_i);
                    if (value_of_(idx) == '.') q.push(idx);
                    idx = down(_i);
                    if (value_of_(idx) == '.') q.push(idx);
                    idx = left(_i);
                    if (value_of_(idx) == '.') q.push(idx);
                    idx = right(_i);
                    if (value_of_(idx) == '.') q.push(idx);
                    q.pop();
//                    echo(vec, m);
                    ++cnt;
                }
                answers.push_back(cnt);
            }
        }
        sort(answers.begin(), answers.end());
        cout << answers.size() << endl;
        for (auto iter = answers.rbegin(); iter != answers.rend(); ++iter) {
            cout << *iter << ' ';
        }
        cout << endl;
    }
    return 0;
}