#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers, int target)
{
	int answer = 0;

	int loopCount = 1;

	for (int num : numbers)
	{
		loopCount *= 2;
	}

	int checkNum = 0;

	for (int i = 0; i < loopCount; ++i)
	{
		checkNum = 0;

		for (int j = 1; j < numbers.size() + 1; ++j)
		{
			if (i & j)
			{
				checkNum += -1 * numbers[j - 1];
			}
			else
			{
				checkNum += numbers[j - 1];
			}
		}

		if (checkNum == target) answer++;
	}

	return answer;
}

int main()
{
	vector<int> arr;

	arr = { 1, 1, 1, 1, 1 };

	cout << solution(arr, 3) << "\n";

	getchar();

	return 0;
}