#include <bits/stdc++.h>
using namespace std;

int main()
{
	string squares;
	cin >> squares;

	int count = 0;

	for (auto it = squares.begin(); it != squares.end(); ++it)
	{
		if (*it == '1')
		{
			count++;
		}
	}
	cout << count << endl;
}