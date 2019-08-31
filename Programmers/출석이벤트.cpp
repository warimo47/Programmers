#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> estimates, int k)
{
	int answer = 0;
	int count = 0;

	for (int i = 0; i < estimates.size() - k + 1; ++i)
	{
		count = 0;
		for (int j = i; j < i + k; ++j)
		{
			count += estimates[j];
		}

		if (answer < count) answer = count;
	}

	return answer;
}

int main()
{
	vector<int> estimates;

	estimates = { 1, 1, 9, 3, 7, 6, 5, 10 };

	cout << solution(estimates, 4) << "\n";

	estimates = { 1, 1, 5, 1, 1 };

	cout << solution(estimates, 1) << "\n";


	getchar();

	return 0;
}