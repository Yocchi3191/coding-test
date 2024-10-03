// ==============================
// 1. 総当たりしてパターン表を作成
// 2. パターン表を探索して、金額が支払金額と等しければパターンカウント++
// ==============================

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int count500coins, count100coins, count50coins, payment;
	cin >> count500coins >> count100coins >> count50coins >> payment;

	int patterns = (count500coins + 1) * (count100coins + 1) * (count50coins + 1);
	vector<int> patternList(patterns);

	int i = 0;
	for (int coins500 = 0; coins500 <= count500coins; coins500++)
	{
		for (int coins100 = 0; coins100 <= count100coins; coins100++)
		{
			for (int coins50 = 0; coins50 <= count50coins; coins50++)
			{
				int summary = coins500 * 500 + coins100 * 100 + coins50 * 50;
				patternList.at(i) = summary;
				i++;
			}
		}
	}
	int patternCount = 0;
	for (auto it = patternList.begin(); it != patternList.end(); ++it)
	{
		if (*it == payment)
		{
			patternCount++;
		}
	}
	cout << patternCount << endl;
}