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
		// ���� ��ȣ�� ���ÿ� �߰�
		if (sTemp[i] == '(')
		{
			stk.push(sTemp[i]);
		}

		else
		{
			// �ݴ� ��ȣ�� ���ÿ��� �ϳ�����
			stk.pop();

			// �� ��ȣ�� ���±�ȣ������ �����������Ƿ� ������ȣ��ŭ �����߰�
			if (sTemp[i - 1] == '(')
			{
				answer += stk.size();
			}

			// �� ��ȣ�� �ݴ� ��ȣ�� �踷����� �������̹Ƿ� 1���߰�
			else
			{
				answer++;
			}
		}
	}

	cout << answer << '\n';

	return 0;
}