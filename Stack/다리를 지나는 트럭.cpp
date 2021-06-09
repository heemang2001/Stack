#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	int answer = 0;
	int sum = 0;
	int index = 0;

	queue<int> queTruck;

	while (1)
	{
		answer++;

		if (bridge_length == queTruck.size())
		{
			sum -= queTruck.front();
			queTruck.pop();
		}

		if (sum + truck_weights[index] <= weight)
		{

			if (index == truck_weights.size() - 1)
			{
				answer += bridge_length;
				break;
			}

			queTruck.push(truck_weights[index]);
			sum += truck_weights[index];
			index++;
		}

		else
		{
			queTruck.push(0);
		}
	}

	return answer;
}

int main()
{
	cout << solution(2, 10, { 7,4,5,6 }) << '\n';							 // 8
	cout << solution(100, 100, { 10 }) << '\n';								 // 101
	cout << solution(100, 100, { 10,10,10,10,10,10,10,10,10,10 }) << '\n';	 // 110

	return 0;
}