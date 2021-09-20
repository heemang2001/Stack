#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<long long> vecAnswer;

struct cmp
{
	bool operator()(long long num1, long long num2)
	{
		if (abs(num1) == abs(num2))
		{
			return num1 > num2;
		}

		return abs(num1) > abs(num2);
	}
};

priority_queue<long long, vector<long long>, cmp> pq;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		long long nTemp;
		cin >> nTemp;

		if (nTemp != 0)
		{
			pq.push(nTemp);
		}

		else
		{
			if (!pq.empty())
			{
				vecAnswer.push_back(pq.top());
				pq.pop();
			}

			// pq ºö
			else
			{
				vecAnswer.push_back(0);
			}
		}
	}

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << '\n';
	}

	return 0;
}