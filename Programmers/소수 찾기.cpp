#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n)
{
	if (n == 2) return 1;
	int answer = 1;
	bool check = true;

	vector<int> numArr;

	for (int i = 3; i <= n; i = i + 2)
	{
		check = true;

		for (int na : numArr)
		{
			if (i % na == 0)
			{
				check = false;
				break;
			}
		}

		if (check == true)
		{
			if (i < 1000) numArr.push_back(i);
			++answer;
		}
	}

	return answer;
}

int main()
{
	for (int i = 2; i < 1000000; ++i)
	{
		cout << solution(i) << ", ";
	}

	getchar();

	return 0;
}