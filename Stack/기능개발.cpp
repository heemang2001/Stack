#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;
	int nTemp = 0;

	while (progresses.size() > 0)
	{
		for (int i = 0; i < progresses.size();)
		{
			if (progresses[0] >= 100)
			{
				nTemp++;
				progresses.erase(progresses.begin());
				speeds.erase(speeds.begin());
				i--;
				if (i < 0) i = 0;
				continue;
			}

			progresses[i] += speeds[i];	
			i++;
		}

		if (nTemp > 0)
		{
			answer.push_back(nTemp);
			nTemp = 0;
		}
	}	

	return answer;
}

int main()
{
	vector<int> vecAnswer1 = solution({ 93,30,55 }, { 1,30,5 });				 // 2, 1
	vector<int> vecAnswer2 = solution({ 95,90,99,99,80,99 }, { 1,1,1,1,1,1});	 // 1, 3, 2
	
	for (int i = 0; i < vecAnswer1.size(); i++)
	{
		cout << vecAnswer1[i] << " ";
	}

	cout << '\n';

	for (int i = 0; i < vecAnswer2.size(); i++)
	{
		cout << vecAnswer2[i] << " ";
	}

	return 0;
}