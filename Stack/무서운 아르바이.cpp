#include<iostream>
#include<stack>
#include<utility>
#include<vector>

using namespace std;

int n, a, tmp_i;
long long ans = 0, tmp;
stack<pair<int, int> > st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;

		if (st.empty())
		{
			st.push(make_pair(i, a));
		}

		else
		{
			if (st.top().second < a) 
			{
				st.push(make_pair(i, a));
			}

			else if (st.top().second > a)
			{
				while (!st.empty() && st.top().second > a)
				{ //stack�� �ִ� ���� ���̺��� ū ���̿� ���ؼ� ���� ���
					tmp = st.top().second * (i - st.top().first);
					tmp_i = st.top().first;
					st.pop();

					if (tmp > ans)
					{
						ans = tmp; //�ִ� ����
					}
				}

				st.push(make_pair(tmp_i, a)); //��� ���� �Ŀ� �� �۾Ҵ� ���̷� ������׷� �ٽ� �����
			}
		}
	}

	while (!st.empty())
	{ //stack�� �����ִ� ���̿� ���ؼ� ����ϴ� ����
		tmp = st.top().second * (n - st.top().first);
		st.pop();

		if (tmp > ans)
		{
			ans = tmp;
		}
	}

	cout << ans << "\n";
}

// �ð� �ʰ�
//int N;
//int Answer;
//vector<int> vecPay;
//
//int main()
//{
//	cin >> N;
//
//	for (int i = 0; i < N; i++)
//	{
//		int nTemp;
//		cin >> nTemp;
//		vecPay.push_back(nTemp);
//	}
//
//	int WorkingDay = 1;
//
//	while (1)
//	{
//		if (WorkingDay > N)
//		{
//			break;
//		}
//
//		stack<int> stkTemp;
//
//		for (int i = 0; i < vecPay.size(); i++)
//		{
//			stkTemp.push(vecPay[i]);
//
//			int next_index = i + 1;
//
//			while (1)
//			{
//				if (stkTemp.size() >= WorkingDay || next_index >= vecPay.size())
//				{
//					break;
//				}
//
//				stkTemp.push(vecPay[next_index]);
//				next_index++;
//			}
//
//			int min_Pay = MAX_VALUE;
//			int sum = 0;
//
//			while (!stkTemp.empty())
//			{
//				min_Pay = min(min_Pay, stkTemp.top());
//				stkTemp.pop();
//			}
//
//			sum = min_Pay * WorkingDay;
//			Answer = max(Answer, sum);
//		}
//
//		WorkingDay++;
//	}
//
//	cout << Answer << '\n';
//
//	return 0;
//}