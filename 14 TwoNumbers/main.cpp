#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>

using namespace std;

int my_rand(int begin, int end) {
    return begin + rand() % (end - begin - 1) + 1;
}

int abs(int n) {
    return 0 <= n ? n : -n;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    ifstream in("input.txt");
    int test_case;
    for (in >> test_case; 0 < test_case; --test_case) {
        int n, k, buff;
        in >> n >> k;
        int *arr = new int[n];
        for (int i = n - 1; 0 <= i; --i) {
            in >> buff;
            arr[i] = buff;
        }
        qsort(arr, n, sizeof(int),
              [](const void *a, const void *b) -> int { return (*(int *) a - *(int *) b); });

        int min_delta = INT32_MAX;
        int before_pivot = n - 1;
        int min_delta_cnt = 0;
        bool bisect = true;

        for (int i = 0; i < n - 1; ++i) {
            int begin = i;
            int end = before_pivot + 1;
            if (end - begin < 2) continue;
            if (bisect) {
                int pivot = n;
                while (begin < end) {
                    if (30000 < end - begin) {
                        pivot = (begin + end) / 2;
                    } else {
                        pivot = my_rand(begin, end);
                    }
                    auto delta = abs(arr[i] + arr[pivot] - k);
                    if (delta < min_delta) {
                        min_delta = delta;
                        min_delta_cnt = 1;
                    } else if (delta == min_delta) ++min_delta_cnt;
                    int left_delta = INT32_MAX, right_delta = INT32_MAX;
                    if (pivot - begin > 1) {
                        left_delta = abs(arr[i] + arr[pivot - 1] - k);
                    }
                    if (end - pivot > 1) {
                        right_delta = abs(arr[i] + arr[pivot + 1] - k);
                    }
                    auto _min = min(delta, min(left_delta, right_delta));

                    if (_min == delta) {
                        if (min_delta == left_delta) ++min_delta_cnt;
                        if (min_delta == right_delta) ++min_delta_cnt;
                        break;
                    } else if (_min == left_delta) {
                        end = pivot;
                    } else {
                        begin = pivot;
                    }
                }
                bisect = false;
                before_pivot = pivot;

            } else {
                int before_delta = abs(arr[i] + arr[--end] - k);
                int delta;
                int cnt = 1;
                while (end - begin > 1) {
                    delta = abs(arr[i] + arr[--end] - k);
                    if (delta > before_delta) {
                        break;
                    } else if (delta == before_delta) {
                        ++cnt;
                        --end;
                        break;
                    }
                    before_delta = delta;
                }
                delta = before_delta;
                before_pivot = end + 1;
                if (delta < min_delta) {
                    min_delta = delta;
                    min_delta_cnt = cnt;
                } else if (delta == min_delta) {
                    min_delta_cnt += cnt;
                }
            }
        }
        cout << min_delta_cnt << endl;

        delete[] arr;
    }
    return 0;
}