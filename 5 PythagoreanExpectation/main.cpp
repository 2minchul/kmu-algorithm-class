#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ifstream in("input.txt");
    int test_case;
    for (in >> test_case; 0 < test_case; test_case--) {
        int team_cnt, game_cnt, a, b, p, q;
        in >> team_cnt >> game_cnt;

        auto *results = new int[team_cnt];
        auto *scores = new pair<int, int>[team_cnt];
        pair<int, int> *score;

        for (auto i = team_cnt - 1; 0 <= i; i--) {
            scores[i] = make_pair(0, 0);
        }

        for (; 0 < game_cnt; game_cnt--) {
            in >> a >> b >> p >> q;
            score = &scores[a - 1];
            score->first = score->first + p;
            score->second = score->second + q;
            score = &scores[b - 1];
            score->first = score->first + q;
            score->second = score->second + p;
        }

        for (auto i = team_cnt - 1; 0 <= i; i--) {
            score = &scores[i];
            if (score->first == 0 && score->second == 0) {
                results[i] = 0;
                continue;
            }
            a = score->first * score->first;
            b = score->second * score->second;
            results[i] = (1000 * a) / (a + b);
        }

        cout << *max_element(results, results + team_cnt) << endl;
        cout << *min_element(results, results + team_cnt) << endl;

        delete[] results;
        delete[] scores;
    }
    return 0;
}