// ==============================

// ==============================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> riceCakes(N);
    for (int i = 0; i < N; i++) {
        cin >> riceCakes.at(i);
    }
    // 降順でソート
    sort(riceCakes.rbegin(), riceCakes.rend());

    vector<int> kagamiMochi(0);
    kagamiMochi.push_back(riceCakes.front());

    for (auto it = riceCakes.begin(); it != riceCakes.end(); ++it) {
        if (*it < kagamiMochi.back()) {
            kagamiMochi.push_back(*it);
        }
    }
    cout << kagamiMochi.size() << endl;
}