#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
queue<int> qAnswer;

int main()
{
	cin >> N;

	int curSize = 0;

	while (1)
	{
		int nTemp;
		cin >> nTemp;

		if (nTemp == -1)
		{
			break;
		}

		else if(nTemp == 0)
		{
			qAnswer.pop();
			curSize--;
		}

		else if(curSize < N)
		{
			qAnswer.push(nTemp);
			curSize++;
		}		
	}

	if (qAnswer.empty())
	{
		cout << "empty" << '\n';
	}

	else
	{
		while (!qAnswer.empty())
		{
			cout << qAnswer.front() << " ";
			qAnswer.pop();
		}
	}

	return 0;
}