#include <iostream>
#include <fstream>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, deque<int>> Pair;

int main() {
    ifstream in("input.txt");
    int test_case;
    for (in >> test_case; 0 < test_case; --test_case) {
        int n, m;
        int _x, _y;
        in >> n;
        map<int, deque<int>> map_;

        for (int i = n; 0 < i; --i) {
            in >> _x >> _y;
            auto already = map_.find(_x);
            if (already == map_.end()) { // if not exist
                Pair p = make_pair(_x, deque<int>());
                p.second.push_back(_y);
                map_.insert(p);
            } else {
                (*already).second.push_back(_y);
            }
        }
        in >> m;
        int *need = new int[m];
        for (int i = m - 1; 0 <= i; --i) {
            in >> need[i];
        }
        auto need_max = *max_element(need, need + m);
        int arr_x[need_max], arr_y[need_max];
        int arr_i = 0;

        auto iter = map_.begin();
        auto before_y = 0;
        while (arr_i < need_max) {
            auto p = *iter;
            sort(p.second.begin(), p.second.end());
            if (p.second[0] == before_y) {
                for (auto y:p.second) {
                    arr_x[arr_i] = p.first;
                    arr_y[arr_i] = y;
                    if (need_max == ++arr_i) break;
                }
            } else {
                for (auto _iter = p.second.rbegin(); _iter < p.second.rend(); ++_iter) {
                    arr_x[arr_i] = p.first;
                    arr_y[arr_i] = *_iter;
                    if (need_max == ++arr_i) break;
                }
            }
            before_y = arr_y[arr_i - 1];
            ++iter;
        }

        for (int i = m - 1; 0 <= i; --i) {
            auto _i = need[i] - 1;
            printf("%d %d\n", arr_x[_i], arr_y[_i]);
        }
        delete[] need;
    }

    return 0;
}