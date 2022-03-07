#include <iostream>
#include <string>
#include <vector>

using namespace std;

int factorCounter(int a)
{
	int count = 0;

	for (int i = 1; i <= a; ++i)
	{
		if (a % i == 0) count++;
	}

	return count;
}

int solution(int left, int right)
{
	int answer = 0;

	for (int i = left; i < right + 1; ++i)
	{
		if (factorCounter(i) % 2 == 0)
		{
			answer += i;
		}
		else
		{
			answer -= i;
		}
	}

	return answer;
}

int main()
{
	cout << solution(13, 17) << "\n\n";

	cout << solution(24, 27) << "\n\n";

	getchar();

	return 0;
}