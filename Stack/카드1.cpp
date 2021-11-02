#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;

int main()
{
	cin >> N;

	queue<int> q;
	vector<int> vecAbandonCard;

	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	if (q.size() == 1)
	{
		cout << 1 << '\n';
		return 0;
	}

	while (q.size() > 1)
	{
		int TopCardNum = q.front();
		q.pop();

		vecAbandonCard.push_back(TopCardNum);
		int SecondCardNum = q.front();
		q.pop();
		q.push(SecondCardNum);
	}

	for (int i = 0; i < vecAbandonCard.size(); i++)
	{
		cout << vecAbandonCard[i] << " ";
	}

	cout << q.front() << '\n';

	return 0;
}