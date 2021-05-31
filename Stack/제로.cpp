#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int K;

int main()
{
	stack<int> stackNum;

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int nTemp;
		cin >> nTemp;

		if (nTemp == 0)
		{
			stackNum.pop();
			continue;
		}

		stackNum.push(nTemp);
	}

	int answer = 0;

	if (!stackNum.empty())
	{
		int tempsize = stackNum.size();

		for (int i = 0; i < tempsize; i++)
		{
			int nTemp = stackNum.top();
			stackNum.pop();
			answer += nTemp;
		}
	}

	cout << answer << '\n';

	return 0;
}