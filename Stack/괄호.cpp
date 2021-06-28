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
			// ������ ���� ����ִٸ�
			if (stkVPS.empty())
			{
				stkVPS.push(sTemp[j]);
				continue;
			}

			// ������ ������� �ʴٸ�
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