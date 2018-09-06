#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;

multiset<int>::iterator n_th_iter(multiset<int> *s, int n) {
    multiset<int>::iterator iter;
    iter = n < 0 ? s->end() : s->begin();
    if (n != 0) {
        advance(iter, n);
    }
    return iter;
}

int main() {
    ifstream in("input.txt");
    int test_case;

    for (in >> test_case; 0 < test_case; test_case--) {
        int n, card;
        bool zero_exist = false;
        int answers[7];
        int answers_i = 0;
        multiset<int> positive;
        multiset<int> negative;
        multiset<int> *s;

        for (in >> n; 0 < n; n--) {
            in >> card;
            if (card == 0) {
                zero_exist = true;
                continue;
            } else if (0 < card) {
                s = &positive;
            } else {
                s = &negative;
            }

            s->insert(card);
            if (6 < s->size()) {
                s->erase(n_th_iter(s, 3));
            }

        }
        while (true) {
            if (3 <= positive.size()) {
                auto iter = positive.rbegin();
                answers[answers_i++] = *iter++ * *iter++ * *iter;
            } else if (2 <= positive.size()) {
                auto iter = positive.rbegin();
                answers[answers_i++] = *iter++ * *iter;
            }

            if (!positive.empty() && 2 <= negative.size()) {
                auto iter = negative.begin();
                answers[answers_i++] = *iter++ * *iter * *positive.rbegin();
            } else if (2 <= negative.size()) {
                auto iter = negative.begin();
                answers[answers_i++] = *iter++ * *iter;
            }
            if (answers_i) break;

            if (zero_exist) {
                answers[answers_i++] = 0;
                break;
            }

            if (!positive.empty() && !negative.empty()) {
                answers[answers_i++] = *positive.begin() * *negative.rbegin();
            }

            break;
        }

        cout << *max_element(answers, answers + answers_i) << endl; // 가장 큰 수
    }
    exit(0);
    return 0;
}