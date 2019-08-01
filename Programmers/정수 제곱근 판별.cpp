#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(long long n)
{
	long long answer = 1;

	while (true)
	{
		if (answer * answer == n)
		{
			return (answer + 1) * (answer + 1);
		}

		if (answer * answer > n)
		{
			return -1;
		}

		++answer;
	}

	return answer;
}

int main()
{
	cout << solution(121) << "\n";
	cout << solution(3) << "\n";

	getchar();

	return 0;
}