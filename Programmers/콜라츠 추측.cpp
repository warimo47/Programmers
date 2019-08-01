#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num)
{
	int answer = 0;

	while (true)
	{
		if (num == 1) break;
		if (answer > 500) return -1;

		if (num % 2 == 1)
		{
			num = num * 3 + 1;
		}
		else
		{
			num = num / 2;
		}
		++answer;
	}

	return answer;
}

int main()
{
	cout << solution(6) << "\n";
	cout << solution(16) << "\n";
	cout << solution(626331) << "\n";

	getchar();

	return 0;
}