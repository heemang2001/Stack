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
				{ //stack에 있는 현재 높이보다 큰 높이에 대해서 넓이 계산
					tmp = st.top().second * (i - st.top().first);
					tmp_i = st.top().first;
					st.pop();

					if (tmp > ans)
					{
						ans = tmp; //최댓값 갱신
					}
				}

				st.push(make_pair(tmp_i, a)); //모두 조사 후에 더 작았던 높이로 히스토그램 다시 만들기
			}
		}
	}

	while (!st.empty())
	{ //stack에 남아있는 높이에 대해서 계산하는 과정
		tmp = st.top().second * (n - st.top().first);
		st.pop();

		if (tmp > ans)
		{
			ans = tmp;
		}
	}

	cout << ans << "\n";
}

// 시간 초과
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