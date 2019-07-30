#include <string>
#include <iostream>
#include <vector>

using namespace std;

string solution(string s, int n)
{
	string answer = s;

	for (char c : s)
	{
		if (c == ' ')
		{

		}
		else if ('a' <= c && c <= 'z')
		{

		}
		else
		{

		}
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