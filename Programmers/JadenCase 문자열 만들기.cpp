#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s)
{
	string answer = "";
	bool firstChar = true;

	for (char ss : s)
	{
		if (ss == ' ')
		{
			firstChar = true;
			answer.push_back(ss);
		}
		else if ('a' <= ss && ss <= 'z')
		{
			if (firstChar)
			{
				answer.push_back(ss - 32);
				firstChar = false;
			}
			else
			{
				answer.push_back(ss);
			}
		}
		else if ('A' <= ss && ss <= 'Z')
		{
			if (firstChar)
			{
				answer.push_back(ss);
				firstChar = false;
			}
			else
			{
				answer.push_back(ss + 32);
			}
		}
		else
		{
			firstChar = false;
			answer.push_back(ss);
		}
	}

	return answer;
}

int main()
{
	cout << solution("3people unFollowed me") << "\n\n";

	cout << solution("for the last week") << "\n\n";

	getchar();

	return 0;
}