#include <vector>
#include <iostream>

using namespace std;

long long solution(int n)
{
	if (n == 2) return 2;
	int answer = 2;
	bool check = true;
	int checkCount = 0;

	vector<int> numArr;

	for (int i = 3; i <= n; i = i + 2)
	{
		check = true;
		checkCount = 0;

		for (int na : numArr)
		{
			if (i % na == 0)
			{
				check = false;
				break;
			}

			if (checkCount > 13) break;
			++checkCount;
		}

		if (check == true)
		{
			if (i < 54) numArr.push_back(i);
			answer += i;
		}
	}

	return answer;
}

int main()
{
	cout << solution(7) << "\n\n";
	cout << solution(8) << "\n\n";
	cout << solution(2) << "\n\n";

	getchar();

	return 0;
}