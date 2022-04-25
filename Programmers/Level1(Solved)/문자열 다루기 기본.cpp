#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
	bool answer = true;

	if (s.size() == 4 || s.size() == 6)
	{
		for (char c : s)
		{
			if ('0' > c || c > '9') return false;
		}
	}
	else
	{
		return false;
	}

	return answer;
}

int main()
{
	cout << solution("a234") << "\n";
	cout << solution("1234") << "\n";

	getchar();

	return 0;
}