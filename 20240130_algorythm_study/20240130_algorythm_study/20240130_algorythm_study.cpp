#include <iostream>
#include <vector>
#include <ranges>
#include <iterator>


int CalcSumPatterns(int n, int k, std::vector<int> cards);

int main()
{
	std::vector<int> cards = {
		1,1,1,1,1,1,1,1,1,1
	};

	int n = cards.size();
	int k = 3;
	std::cout << n << std::endl;
	std::cout << CalcSumPatterns(n, k, cards);
}

/// <summary>
///  n枚のカードが入った配列cardsについて、3枚選んで和がkになる組み合わせの個数を求める
/// </summary>
/// <param name="n">カードの枚数</param>
/// <param name="k">マッチさせる数</param>
/// <param name="cards">カードの配列</param>
/// <returns></returns>
int CalcSumPatterns(int n, int k, std::vector<int> cards)
{
	int count = 0; // 和がkになった組み合わせの個数

	for (auto itA = cards.begin(); itA != cards.end(); ++itA)
	{
		for (auto itB = itA + 1; itB != cards.end(); ++itB)
		{
			for (auto itC = itB + 1; itC != cards.end(); ++itC)
			{
				if (*itA + *itB + *itC == k)
				{
					count++;
				}
			}
		}
	}
	return count;
}