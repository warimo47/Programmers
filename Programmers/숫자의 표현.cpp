#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n)
{
	int answer = 0;

	for (int i = 1; i <= n; ++i)
	{
		int j = i;
		int countNum = i;

		while (j <= n)
		{
			if (j == n)
			{
				answer++;
				break;
			}

			++countNum;
			j += countNum;
		}
	}

	return answer;
}

int main()
{
	cout << solution(15) << "\n\n";

	cout << solution(15) << "\n\n";

	getchar();

	return 0;
}