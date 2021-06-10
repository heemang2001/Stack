#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices)
{
	vector<int> answer(prices.size());	

	for (int i = 0; i < prices.size(); i++)
	{
		for (int j = i+1; j < prices.size(); j++)
		{
			if (prices[i] <= prices[j])
			{
				answer[i]++;
			}

			else
			{
				answer[i] = j - i;
				break;
			}
		}
	}

	return answer;
}

int main()
{
	vector<int> vecTemp = solution({ 1,2,3,2,3 });	// 4 3 1 1 0

	for (int i = 0; i < vecTemp.size(); i++)
	{
		cout << vecTemp[i] << " ";
	}

	cout << "\n";

	vecTemp = solution({ 1,2,3,2,3,1 });	// 5 4 1 2 1 0

	for (int i = 0; i < vecTemp.size(); i++)
	{
		cout << vecTemp[i] << " ";
	}

	return 0;
}