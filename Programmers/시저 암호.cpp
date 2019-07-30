#include <string>
#include <iostream>
#include <vector>

using namespace std;

string solution(string s, int n)
{
	string answer = "";

	for (char c : s)
	{
		if (c == ' ')
		{
			
		}
		else if ('a' <= c && c <= 'z')
		{
			c = (c - 'a' + n) % 26 + 'a';
		}
		else
		{
			c = (c - 'A' + n) % 26 + 'A';
		}
		answer.push_back(c);
	}

	return answer;
}

int main()
{
	string str = solution("AB", 1);
	cout << str << "\n";

	str = solution("z", 1);
	cout << str << "\n";

	str = solution("a B z", 4);
	cout << str << "\n";

	getchar();

	return 0;
}