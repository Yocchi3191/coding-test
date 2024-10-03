/*
# 入力
-----------------------
N 個の都市
M 個の道路

道路 i は、都市 ai, bi を結ぶ
ai - i - bi

以下の形式で入力される
-----------------------
N M
a1 b1
:
aM bM

N   :   int
M   :   int
ai  :   int
bi  :   int

# 条件
-----------------------
都市間を結ぶ道路は1つとは限らない

# 求める出力
-----------------------
各都市から他方の都市に向けて伸びている道路の本数
(「都市」を「頂点」としたときの、都市ごとの頂点次数)

以下の形式で出力する
-----------------------
都市1の頂点次数
都市2の頂点次数
:
都市Nの頂点次数

データ構造
-----------------------
都市ごとの頂点次数を格納するvector degs
大きさN

ロジック
-----------------------
M回ループ
入力 : ai bi
degs[ai]++, degs[bi]++
*/

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    // 都市、道路の数を取得
    int N, M;
    cin >> N >> M;

    // 都市ごとの頂点次数を格納
    vector<int> degs(N, 0);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        degs.at(a)++;
        degs.at(b)++;
    }

    for (auto it = degs.begin(); it != degs.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
