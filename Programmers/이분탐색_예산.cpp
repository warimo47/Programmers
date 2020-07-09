#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int solution(vector<int> budgets, int M)
{
	sort(budgets.begin(), budgets.end());

	int answer = budgets[1];
	int sum = budgets[0];

	if (sum > (M / budgets.size()))
		return (M / budgets.size());

	for (int count = 1; count < budgets.size(); ++count)
	{
		int tempSum = sum + (budgets.size() - count) * budgets[count];
		
		if (tempSum == M)
		{
			return budgets[count];
		}
		else if (tempSum < M)
		{
			sum += budgets[count];
		}
		else
		{
			return (M - sum) / (budgets.size() - count);
		}
	}

	if (sum < M) return budgets[budgets.size() - 1];

	return M - (sum - budgets[budgets.size() - 1]);
}

int main()
{
	vector<int> budgets = { 120, 110, 140, 150 };

	std::cout << solution(budgets, 485) << std::endl;

	budgets = { 10, 10, 50 };

	std::cout << solution(budgets, 60) << std::endl;

	budgets = { 5, 5, 5, 5, 10, 10, 12, 12, 20, 24 };

	std::cout << solution(budgets, 100) << std::endl;

	getchar();

	return 0;
}