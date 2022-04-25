#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k)
{
	int answer = 0;

	int supplyDate = 0;

	while (true)
	{
		if (stock > k) break;
		else if (stock < dates[supplyDate + 1])
		{
			answer++;
			stock += supplies[supplyDate];
			supplyDate++;
		}
		else
		{
			supplyDate++;
		}

		if (supplyDate == dates.size() - 1)
		{
			if (stock < k)
			{
				answer++;
				break;
			}
		}
	}

	return answer;
}

int main()
{
	int stock = 4;
	vector<int> dates = { 4, 10, 15 };
	vector<int> supplies = { 20, 5, 10 };
	int k = 30;

	std::cout << solution(stock, dates, supplies, k) << std::endl;

	stock = 4;
	dates = { 4, 10, 15 };
	supplies = { 20, 5, 10 };
	k = 30;

	std::cout << solution(stock, dates, supplies, k) << std::endl;

	getchar();

	return 0;
}