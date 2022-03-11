#include <vector>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

int solution(string s)
{
	stack<char> cs;

	cs.push('A');

	for (int i = 0; i < s.size(); ++i)
	{
		if (cs.top() == s[i])
		{
			cs.pop();
		}
		else
		{
			cs.push(s[i]);
		}
	}

	if (cs.size() == 1) return 1;
	else return 0;
}

int main()
{
	cout << solution("baabaa") << "\n\n";

	cout << solution("cdcd") << "\n\n";

	getchar();

	return 0;
}