#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int N;
int Answer;
int MaxValue;
int Rod[1001][3];

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int nTemp1;
		int nTemp2;

		cin >> nTemp1 >> nTemp2;

		Rod[nTemp1][0] = nTemp2;
	}

	// ¿ÞÂÊ¿¡¼­ ºû
	for (int i = 0; i <= 1000; i++)
	{
		MaxValue = max(Rod[i][0], MaxValue);
		Rod[i][1] = MaxValue;
	}

	MaxValue = 0;

	// ¿À¸¥ÂÊ¿¡¼­ ºû
	for (int i = 1000; i >= 0; i--)
	{
		MaxValue = max(Rod[i][0], MaxValue);
		Rod[i][2] = MaxValue;
	}

	for (int i = 0; i <= 1000; i++)
	{
		Answer += min(Rod[i][1], Rod[i][2]);
	}

	cout << Answer << '\n';

	return 0;
}