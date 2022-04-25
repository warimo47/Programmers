#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name)
{
	vector<int> count;
	for (int i = 0; i < name.size(); ++i)
	{
		if (name[i] < 'O')
		{
			count.push_back(name[i] - 'A');
		}
		else
		{
			count.push_back('Z' - name[i] + 1);
		}
	}

	int nomalCount = -1;
	int maxA = 0;
	int startA = 0;
	int ACount = 0;

	for (int i = 0; i < count.size(); ++i)
	{
		if (count[i] == 0)
		{
			if (ACount == 0) startA = i;
			ACount++;

			if (ACount - startA - 1 > maxA) maxA = ACount - startA - 1;
		}
		else
		{
			nomalCount += count[i] + 1 + ACount;
			ACount = 0;
		}
	}

	return nomalCount - maxA;
}

int main()
{
	cout << solution("JEROEN") << "\n\n";

	cout << solution("JAN") << "\n\n";

	getchar();

	return 0;
}