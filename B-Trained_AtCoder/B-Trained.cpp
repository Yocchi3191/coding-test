/*
# 制約
------------------
2 <= N <= 10^5
1 <= ai <= N

# 入力
------------------
N : ボタンの数
a1 : ボタン
a2
:
aN

# 出力
------------------
ボタン2を光らせることができない -> -1 を出力
ボタン2を光らせることができる   ｰ>  ボタンを押す最小の回数を出力

# 考え方
------------------
ボタン番号   :   そのボタンが光ってるときに押すと、次に光るボタン
i           :   ai

1 -> a1 -> ... -> 2 にいけるかを判定する

「循環」の定義と、その判定がカギ
たぶん、「すでに押したボタンに飛んだ」ら、「循環」
-> 「そのボタンもう押したよ」リストが必要？
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> buttons(N + 1, 0);

    // ジャンプ先の割当
    for (int i = 1; i <= N; i++)
    {
        int nextButton;
        cin >> nextButton;
        buttons.at(i) = nextButton;
    }

    // そのボタンもう押したよフラグ
    vector<bool> pushedList(N + 1, 0);

    int currentButton = 1;
    int pushCount = 1;
    while (currentButton != 2)
    {
        // もう押したボタンであれば、循環するのでエラーとして終了
        if (pushedList.at(currentButton) == 1)
        {
            cout << -1 << endl;
            return 0;
        }
        // 現在押しているボタンを押下済みに
        pushedList.at(currentButton) = 1;

        // 次のボタンを押す
        currentButton = buttons.at(currentButton);
        // もし次のボタンが2番目のボタンなら
        if (currentButton == 2)
        {
            // 現在のステップ数を出力して終了
            cout << pushCount << endl;
            return 0;
        }

        // ステップ数を増やす
        pushCount++;
    }

    return 0;
}