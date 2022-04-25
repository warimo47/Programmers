#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isRightStr(string s)
{
	int leftCount = 0;

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(') leftCount++;
		else leftCount--;

		if (leftCount < 0) return false;
	}

	return true;
}

string solution(string p)
{
	if (p.compare("") == 0) return "";

	int leftCount = 0;
	int rightCount = 0;

	string u = "";
	string v = "";
	string answer = "";
	string reU = "";

	for (int i = 0; i < p.size(); ++i)
	{
		if (p[i] == '(')
		{
			leftCount++;
		}
		else
		{
			rightCount++;
		}

		if (leftCount == rightCount)
		{
			u = p.substr(0, i + 1);
			v = p.substr(i + 1, p.size() - (i + 1));

			if (isRightStr(u))
			{
				return u + solution(v);
			}
			else
			{
				u.erase(u.begin());
				u.erase(u.begin() + u.size() - 1);

				for (char c : u)
				{
					if (c == '(') reU += ")";
					else reU += "(";
				}

				return "(" + solution(v) + ")" + reU;

			}
		}
	}
}

int main()
{
	cout << solution("(()())()") << "\n\n";

	cout << solution(")(") << "\n\n";

	cout << solution("()))((()") << "\n\n";

	getchar();

	return 0;
}