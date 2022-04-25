#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

long long solution(int N)
{
	long long answer = 4;

	long long rightNum = 1;
	long long backNum1 = 1;
	long long backNum2 = 0;
	long long temp = 0;

	for (int i = 1; i < N; ++i)
	{
		backNum2 = backNum1;
		backNum1 = rightNum;
		rightNum = rightNum + backNum2;
	}

	answer = backNum1 * 4 + backNum2 * 2;

	return answer;
}

int main()
{
	std::cout << solution(5) << " | 26" << std::endl;

	std::cout << solution(6) << " | 42" << std::endl;

	getchar();

	return 0;
}