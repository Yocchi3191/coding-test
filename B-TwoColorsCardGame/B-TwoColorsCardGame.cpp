#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// 方針
// ----------------------------------------

// 青のカード内にあるワードを被りなく列挙
// ワードとその数のペア配列を生成
// ワード一つ一つにつき、青のカード内に何個、赤のカード内に何個あるかを数える
// 最終的な個数 = 青のカード内の個数 - 赤のカード内の個数
// ワードと数のペア配列を探索して、最大の数を持つペアを取得
// 取得したワード:数のペアの、数を出力

// 自作関数
// ----------------------------------------

/// @brief 入力されるカードの情報をまとめて取得する
/// @param N : カードの枚数
/// @return カードの情報をまとめた配列
vector<string> getCards(int N)
{
    vector<string> cards;
    for (int i = 0; i < N; i++)
    {
        string card;
        cin >> card;
        cards.push_back(card);
    }
    return cards;
}

/// @brief 青のカード配列、赤のカード配列とそれぞれの枚数情報をもとに、ワードとその数のペア配列を返す
/// @param blueCards : 青のカード配列
/// @param redCards : 赤のカード配列
/// @param N : 青のカードの枚数
/// @param M : 赤のカードの枚数
/// @param stringCountPair : ワードとその数のペア配列
/// @return 青、赤それぞれのカードで現れたワードとその数のペア配列
void countWordsInCards(vector<string> blueCards, vector<string> redCards, int N, int M, vector<tuple<string, int>> &stringCountPair)
{
    for (int i = 0; i < N; i++)
    {
        string word = blueCards[i];
        int count = 0;
        for (int j = 0; j < N; j++)
        {
            if (word == blueCards[j])
            {
                count++;
            }
        }
        for (int j = 0; j < M; j++)
        {
            if (word == redCards[j])
            {
                count--;
            }
        }
        stringCountPair.push_back(make_tuple(word, count));
    }
}

/// @brief ワード : 数 のペア配列から最大の数を取得する
/// @param stringCountPair : ワードとその数のペア配列
/// @param N : ワードの数
/// @return
int getMaxCount(vector<tuple<string, int>> stringCountPair, int N)
{
    int maxCount = 0;
    for (int i = 0; i < N; i++)
    {
        if (maxCount < get<1>(stringCountPair[i]))
        {
            maxCount = get<1>(stringCountPair[i]);
        }
    }
    return maxCount;
}

// 実処理
// ----------------------------------------

int main()
{
    // 青のカードを取得
    int N;
    cin >> N;
    vector<string> blueCards = getCards(N);

    // 赤のカードを取得
    int M;
    cin >> M;
    vector<string> redCards = getCards(M);

    // ワードとその数のペア配列を生成
    vector<tuple<string, int>> stringCountPair;
    countWordsInCards(blueCards, redCards, N, M, stringCountPair);

    // 最大の数を持つペアを取得
    int maxCount = getMaxCount(stringCountPair, N);

    // 出力
    cout << maxCount << endl;
}
