#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<int> vecNum;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecNum.push_back(nTemp);
	}

	priority_queue<int> Max_pq;
	priority_queue<int> Min_pq;

	for (int i = 0; i < N; i++)
	{
		if (Max_pq.size() > Min_pq.size())
		{
			Min_pq.push(-vecNum[i]);
		}

		else
		{
			Max_pq.push(vecNum[i]);
		}

		if (!Max_pq.empty() && !Min_pq.empty())
		{
			if (Max_pq.top() > -Min_pq.top())
			{
				int Max_Value = Max_pq.top();
				int Min_Value = -Min_pq.top();

				Max_pq.pop();
				Min_pq.pop();

				Max_pq.push(Min_Value);
				Min_pq.push(-Max_Value);
			}
		}

		cout << Max_pq.top() << '\n';
	}

	return 0;
}

// 시간 초과
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N;	
//
//	vector<int> vecAnswer;
//	vector<int> vecTemp;
//
//	for (int i = 0; i < N; i++)
//	{
//		int nTemp;
//		cin >> nTemp;
//		vecTemp.push_back(nTemp);
//
//		sort(vecTemp.begin(), vecTemp.end());
//
//		// 짝수개면
//		if (vecTemp.size() % 2 == 0)
//		{
//			vecAnswer.push_back(vecTemp[vecTemp.size() / 2 - 1]);
//		}
//
//		// 홀수개면
//		else
//		{
//			vecAnswer.push_back(vecTemp[vecTemp.size() / 2]);
//		}
//	}
//
//	for (int i = 0; i < vecAnswer.size(); i++)
//	{
//		cout << vecAnswer[i] << '\n';
//	}
//
//	return 0;
//}