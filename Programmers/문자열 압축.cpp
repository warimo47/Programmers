#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
	if (s.size() == 1) return 1;

	vector<int> stringLengths;

	int equalCount = 1;
	string equalString = "";
	string stepString = "";

	for (int i = 1; i < s.size() / 2 + 1; ++i)
	{
		equalCount = 1;
		equalString = s.substr(0, i);
		stepString = "";

		for (int j = i; j < (s.size() - (s.size() % i)); j += i)
		{
			if (equalString.compare(s.substr(j, i)) == 0)
			{
				equalCount++;
			}
			else
			{
				if (equalCount == 1)
					stepString += equalString;
				else
					stepString += to_string(equalCount) + equalString;

				equalCount = 1;
				equalString = s.substr(j, i);
			}
		}

		if (equalCount == 1)
			stepString += equalString;
		else
			stepString += to_string(equalCount) + equalString;

		if (s.size() % i)
		{
			stepString += s.substr(s.size() - (s.size() % i), s.size() % i);
		}

		stringLengths.push_back(stepString.size());
	}

	int min = stringLengths[0];

	for (int i = 1; i < stringLengths.size(); ++i)
	{
		if (min > stringLengths[i])
		{
			min = stringLengths[i];
		}
	}

	return min;
}

int main()
{
	cout << solution("aabbaccc") << "\n\n";

	cout << solution("ababcdcdababcdcd") << "\n\n";

	cout << solution("abcabcdede") << "\n\n";

	cout << solution("abcabcabcabcdededededede") << "\n\n";

	cout << solution("xababcdcdababcdcd") << "\n\n";

	getchar();

	return 0;
}