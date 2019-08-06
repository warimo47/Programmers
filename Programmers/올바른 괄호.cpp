#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(string s)
{
	bool answer = true;

	int count = 0;

	for (char ss : s)
	{
		if (ss == '(')
		{
			count += 1;
		}
		else
		{
			count -= 1;
		}

		if (count < 0) return false;
	}

	return count == 0 ? true : false;
}

int main()
{
	cout << solution("()()") << "\n\n";

	cout << solution("(())()") << "\n\n";

	cout << solution(")()(") << "\n\n";
	
	cout << solution("(()(") << "\n\n";

	getchar();

	return 0;
}