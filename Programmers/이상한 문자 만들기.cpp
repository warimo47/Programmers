#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s)
{
	string answer = "";
	bool yy = true;

	for (char cc : s)
	{
		if (cc == ' ')
		{
			yy = true;
			answer.push_back(' ');
			continue;
		}

		if (yy)
		{
			if ('a' <= cc && cc <= 'z')
				answer.push_back(cc - 32);
			else
				answer.push_back(cc);
		}
		else
		{
			if ('A' <= cc && cc <= 'Z')
				answer.push_back(cc + 32);
			else
				answer.push_back(cc);
		}
		yy = !yy;
	}

	return answer;
}

int main()
{
	cout << solution("try hello world") << "\n";

	getchar();

	return 0;
}