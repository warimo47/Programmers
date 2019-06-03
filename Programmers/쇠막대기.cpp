#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string arrangement)
{
	int answer = 0;
	int nowCount = 0;
	bool nowOpen = false;

	for (char c : arrangement)
	{
		if (c == '(')
		{
			if (nowOpen) nowCount++;
			nowOpen = true;
		}
		else
		{
			if (nowOpen)
			{
				if (nowCount > 0)
				{
					answer += nowCount;
				}
			}
			else
			{
				answer += 1;
				nowCount--;
			}

			nowOpen = false;
		}
	}

	return answer;
}

int main()
{
	string case1 = "()(((()())(())()))(())";

	cout << solution(case1) << "\n";

	getchar();

	return 0;
}