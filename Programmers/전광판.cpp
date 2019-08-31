#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(string phrases, int second)
{
	string answer = "______________";

	int mod = second / 14;
	int count = second % 14;

	if (mod % 2 == 0)
	{
		for (int i = 0; i < count; ++i)
		{
			answer[14 - count + i] = phrases[i];
		}
	}
	else
	{
		for (int i = 0; i < 14; ++i)
		{
			if (i + count > 13)
			{
				answer[i] = '_';
			}
			else
			{
				answer[i] = phrases[i + count];
			}
		}
	}

	return answer;
}

int main()
{
	string phrases = "happy-birthday";

	cout << solution(phrases, 3) << "\n";


	getchar();

	return 0;
}