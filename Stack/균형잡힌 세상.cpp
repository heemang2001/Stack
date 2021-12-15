#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	vector<string> vecAnswer;

	while (1)
	{
		string sInput;
		getline(cin, sInput);

		if (sInput == ".")
		{
			break;
		}

		string Answer = "yes";
		stack<char> stkTemp;
		bool bClear = true;

		for (int i = 0; i < sInput.size(); i++)
		{
			if (sInput[i] == '(' || sInput[i] == '[')
			{			
				stkTemp.push(sInput[i]);
			}

			else if (sInput[i] == ')')
			{
				if (stkTemp.empty() || stkTemp.top() == '[')
				{
					bClear = false;
					break;
				}

				stkTemp.pop();
			}

			else if (sInput[i] == ']')
			{
				if (stkTemp.empty() || stkTemp.top() == '(')
				{
					bClear = false;
					break;
				}

				stkTemp.pop();
			}
		}

		if (bClear == false || !stkTemp.empty())
		{
			Answer = "no";
		}

		vecAnswer.push_back(Answer);
	}

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << '\n';
	}

	return 0;
}