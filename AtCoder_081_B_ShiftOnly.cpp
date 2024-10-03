// ==============================
// 1. N を取得
// 2. 要素数 N の配列 A を作成
// 3. Aの要素に対し、「2で割れるか」の判定を実行(CanBeHlaf)
// 4. 2で割れる (CanBeHalf()=true) なら、A の要素をすべて1/2して再度判定
// 5. これを CanBeHalf() が false を返すまで繰り返す
// ==============================

#include <bits/stdc++.h>
using namespace std;

bool CanBeHalf(vector<int> vec);

int main()
{
	int N;
	cin >> N;

	vector<int> A(N);

	int count = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> A.at(i);
	}

	while (CanBeHalf(A))
	{
		count++;
		for (int i = 0; i < N; i++)
		{
			A.at(i) /= 2;
		}
	}

	cout << count << endl;
}

bool CanBeHalf(vector<int> vec)
{
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		if (*it % 2 != 0)
		{
			return false;
		}
	}
	return true;
}