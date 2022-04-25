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
	int count = 0;

	for (int i = 0; i < loopCount; ++i)
	{
		checkNum = 0;
		count = 0;

		for (int j = 1; j < loopCount; j *= 2)
		{
			if (i & j)
			{
				checkNum += -1 * numbers[count];
			}
			else
			{
				checkNum += numbers[count];
			}
			++count;
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