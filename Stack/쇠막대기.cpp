#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define MAX 100001

int answer;
stack<char> stk;

int main()
{
	string sTemp;
	cin >> sTemp;

	for (int i = 0; i < sTemp.size(); i++)
	{	
		if (sTemp[i] == '(')
		{
			stk.push(sTemp[i]);
		}

		else
		{
			stk.pop();

			if (sTemp[i - 1] == '(')
			{
				answer += stk.size();
			}

			else
			{
				answer++;
			}
		}
	}

	cout << answer << '\n';

	return 0;
}