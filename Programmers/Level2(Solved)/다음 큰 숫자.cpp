#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n)
{
	int answer = 0;
	int tempN = n;

	vector<int> arr;

	while (tempN)
	{
		arr.push_back(tempN % 2);
		tempN = tempN / 2;
	}
	arr.push_back(0);

	bool canUp = false;
	int count = 0;

	for (int i = 0; i < arr.size(); ++i)
	{
		if (canUp)
		{
			if (arr[i] == 0)
			{
				arr[i] = 1;
				arr[i - 1] = 0;
				break;
			}
			else
			{
				arr[i] = 0;
				++count;
			}
		}
		else
		{
			if (arr[i])
			{
				canUp = true;
				++count;
				arr[i] = 0;
			}
		}
	}

	for (int i = 0; i < count - 1; ++i)
	{
		arr[i] = 1;
	}

	int mul = 1;

	for (int i = 0; i < arr.size(); ++i)
	{
		mul = 1;

		for (int j = 0; j < i; ++j)
		{
			mul *= 2;
		}

		if (arr[i])
			answer += mul;
	}

	return answer;
}

int main()
{
	cout << solution(78) << "\n\n";

	cout << solution(15) << "\n\n";

	getchar();

	return 0;
}