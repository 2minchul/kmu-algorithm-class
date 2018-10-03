#include <iostream>
#include <fstream>
#include <algorithm>
#include <deque>
#include <tuple>
#include <unordered_set>

using namespace std;

typedef tuple<int, int, int> Tuple;

void add_room(deque<Tuple> &rooms, deque<int> &area, int begin, int end, int _area, int m) {
    unordered_set<int> area_idx_set;
    for (auto &t : rooms) {
        if (get<0>(t) == -1) continue;
        auto before_begin = get<0>(t) + m;
        if ((before_begin <= begin and begin <= get<1>(t) + m) or (begin <= before_begin and before_begin <= end)) {
            area_idx_set.insert(get<2>(t));
        }
    }
    int area_idx = -1;
    if (area_idx_set.empty()) {
        area_idx = static_cast<int>(area.size());
        area.push_back(_area);
    } else {
        for (auto idx:area_idx_set) {
            if (area_idx == -1) {
                area_idx = idx;
                area[idx] += _area;
            } else {
                for (auto &t : rooms) {
                    if (get<2>(t) == idx) {
                        get<2>(t) = area_idx;
                    }
                }
                area[area_idx] += area[idx];
                area[idx] = 0;
            }
        }
    }
    rooms.emplace_back(begin, end, area_idx);
}

void close_room(deque<Tuple> &rooms, int i) {
    for (auto &t : rooms) {
        int begin = get<0>(t);
        if (begin == -1) continue;
        if (begin < i) {
            get<0>(t) = -1;
        }
    }
}

int main() {
    ifstream in("input.txt");
    int test_case;
    for (in >> test_case; 0 < test_case; --test_case) {
        int m, n;
        in >> m >> n;
        int arr_size = m * n;
        char *arr = new char[arr_size];
        for (int i = 0; i < arr_size; ++i) {
            in >> arr[i];
        }

        int arr_i = 0;
        int begin_idx = 0;
        deque<Tuple> rooms; // (begin, end, area_idx)
        deque<int> area;

        while (arr_i < arr_size) {

            bool before = false;
            int _area = 0;
            for (int _ = m; 0 < _; --_) { // read line
                if (arr[arr_i] == '+') {
                    if (before) {
                        add_room(rooms, area, begin_idx, arr_i - 1, _area, m);
                        _area = 0;
                        before = false;
                    }
                } else {
                    if (!before) {
                        begin_idx = arr_i;
                        before = true;
                    }
                    ++_area;
                }
                ++arr_i;
            }
            close_room(rooms, arr_i - m);
        }

        sort(area.begin(), area.end());
        int zero = 0;
        for (auto value: area) {
            if (value == 0) ++zero;
            else break;
        }
        cout << area.size() - zero << endl;

        for (auto iter = area.rbegin(); iter != area.rend(); ++iter) {
            auto value = *iter;
            if (value == 0) break;
            cout << value << ' ';
        }
        cout << endl;

    }
    return 0;
}