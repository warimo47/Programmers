#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

unsigned long long solution(int n, vector<int> times)
{
	sort(times.begin(), times.end());

	unsigned long long left = n;
	unsigned long long right = n * times.back();

	unsigned long long answer = (left + right) / 2;

	while (true)
	{
		unsigned long long temp = 0;

		for (auto t : times)
		{
			temp += t / answer;
		}

		if (n > temp) break;
	}

	return answer;
}

int main()
{
	vector<int> timesArray = { 7, 10 };

	std::cout << solution(6, timesArray) << " | 28" << std::endl;

	timesArray = { 2, 5, 11 };

	std::cout << solution(9, timesArray) << " | 12" << std::endl;

	getchar();

	return 0;
}