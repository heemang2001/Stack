#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
	int answer = 0;

	queue<int> quePriority;
	queue<pair<int, int>> queTemp;

	for (int i = 0; i < priorities.size(); i++)
	{
		queTemp.push({ i,priorities[i] });	// (위치,우선순위)	
	}

	sort(priorities.begin(), priorities.end(), greater<int>());

	for (int i = 0; i < priorities.size(); i++)
	{
		quePriority.push(priorities[i]);
	}

	while (1)
	{
		pair<int, int> front = queTemp.front();
		int priortyfront = quePriority.front();

		if (front.second < priortyfront)
		{
			queTemp.pop();
			queTemp.push(front);
		}

		else
		{
			answer++;
			queTemp.pop();
			quePriority.pop();

			if (location == front.first)
			{
				return answer;
			}
		}
	}
}

int main()
{
	cout << solution({ 2,1,3,2 }, 2) << '\n';	  // 1
	cout << solution({ 1,1,9,1,1,1 }, 0) << '\n'; // 5

	return 0;
}