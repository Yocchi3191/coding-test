// ==============================
// 1. 「自分の得点を最大化するように最適な戦略を取る」 =
// 「現状のカードから最大のカードを取る」
// 2. 配列から最大値を取得してAlice, Bobに交互に加えていけばよい
// 3. とったカードを配列から削除したいので、削除機能を持った pop_backを使う
// 4. pop_backを使うのでカードの値が後ろから大きくなるようにする
// ==============================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> cards(N);
    for (int i = 0; i < N; i++) {
        cin >> cards.at(i);
    }

    // カードの中身を昇順にソート
    sort(cards.begin(), cards.end());

    int Alice = 0;
    int Bob = 0;
    // Aliceが先行でカードを取る
    // その時点での最大値を取るが、昇順にソートしたのでAlice -> Bob
    // が交互にpop_backすればよい

    while (cards.size()) {
        // Aliceのターン
        Alice += cards.back();
        cards.pop_back();

        if (cards.size()) {
            // Bobのターン
            Bob += cards.back();
            cards.pop_back();
        }
    }

    cout << Alice - Bob << endl;
}