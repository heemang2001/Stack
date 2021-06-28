#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int T;

int main()
{
	cin >> T;

	vector<string> vecAnswer;	

	for (int i = 0; i < T; i++)
	{
		stack<char> stkVPS;
		string sTemp;
		cin >> sTemp;

		for (int j = 0; j < sTemp.size(); j++)
		{
			// 스택이 현재 비어있다면
			if (stkVPS.empty())
			{
				stkVPS.push(sTemp[j]);
				continue;
			}

			// 스택이 비어있지 않다면
			else
			{
				if ((stkVPS.top() == '(') && (sTemp[j] == ')'))
				{
					stkVPS.pop();
				}

				else
				{
					stkVPS.push(sTemp[j]);
				}
			}
		}

		if (stkVPS.empty())
		{
			vecAnswer.push_back("YES");
		}

		else
		{
			vecAnswer.push_back("NO");
		}
	}

	for (auto A : vecAnswer)
	{
		cout << A << '\n';
	}

	return 0;
}