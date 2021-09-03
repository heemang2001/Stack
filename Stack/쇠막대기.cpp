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
		// 여는 괄호면 스택에 추가
		if (sTemp[i] == '(')
		{
			stk.push(sTemp[i]);
		}

		else
		{
			// 닫는 괄호면 스택에서 하나제거
			stk.pop();

			// 전 기호가 여는기호였으면 레이저였으므로 열린괄호만큼 개수추가
			if (sTemp[i - 1] == '(')
			{
				answer += stk.size();
			}

			// 전 기호가 닫는 기호면 쇠막대기의 마지막이므로 1개추가
			else
			{
				answer++;
			}
		}
	}

	cout << answer << '\n';

	return 0;
}