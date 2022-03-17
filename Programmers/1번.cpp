#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(int money, vector<int> costs)
{
	int answer = 0;

	vector<double> coins = { 1.0, 5.0, 10.0, 50.0, 100.0, 500.0 };
	vector<double> ccc;
	for (int c = 0; c < costs.size(); ++c)
	{
		ccc.push_back(static_cast<double>(costs[c]) / coins[c]);
	}

	int fineCCCIndex = 5;

	for (int i = 4; i > -1; --i)
	{
		if (ccc[i] < ccc[fineCCCIndex])
		{
			fineCCCIndex = i;
		}
		else
		{
			answer += (money / static_cast<int>(coins[fineCCCIndex])) * costs[fineCCCIndex];
			money = money % static_cast<int>(coins[fineCCCIndex]);
			fineCCCIndex--;
		}

		if (money == 0) return answer;
	}

	if (money != 0)
	{
		answer += costs[0] * money;
	}

	return answer;
}

int main()
{ 
	cout << solution(4578, { 1, 4, 99, 35, 50, 1000 })  << "\n\n";

	cout << solution(1999, { 2, 11, 20, 100, 200, 600 }) << "\n\n";

	getchar();

	return 0;
}