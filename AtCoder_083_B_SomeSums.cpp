// ==============================
// 1. 10進数を10で割ると一桁減り、剰余に割られる前の一番小さい桁の数が来る
// 2. これを利用して、与えられた整数を10で割って桁を減らしつつ、最小桁の数を足すことで、各桁の総和が求められる。
// ==============================

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	int A, B;
	cin >> N >> A >> B;

	int sums = 0;

	for (int i = 1; i <= N; i++)
	{
		int n = i;
		int sum = 0;
		while (n)
		{
			sum += n % 10;
			n /= 10;
		}
		if (A <= sum && sum <= B)
		{
			sums += i;
		}
	}

	cout << sums << endl;
}