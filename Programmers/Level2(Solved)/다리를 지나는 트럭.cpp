#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	int answer = 0;
	int bridge_weight = 0;

	vector<int> bridge;

	for (int i = 0; i < bridge_length; ++i)
	{
		bridge.push_back(0);
	}

	while (bridge_weight != 0 || !truck_weights.empty())
	{
		for (int i = 1; i < bridge_length; ++i)
		{
			bridge[i - 1] = bridge[i];
		}

		bridge[bridge_length - 1] = 0;

		bridge_weight = 0;
		for (int count : bridge)
		{
			bridge_weight += count;
		}

		if (!truck_weights.empty())
		{
			if (weight >= bridge_weight + truck_weights.front())
			{
				bridge[bridge_length - 1] = truck_weights.front();
				bridge_weight += truck_weights.front();
				truck_weights.erase(truck_weights.begin());
			}
		}

		answer++;
	}

	return answer;
}

int main()
{
	int answer;

	vector<int> truckCase = { 7, 4, 5, 6 };
	answer = solution(2, 10, truckCase);

	std::cout << answer << "\n";

	truckCase.clear();
	truckCase.push_back(10);

	answer = solution(100, 100, truckCase);

	std::cout << answer << "\n";

	truckCase.clear();
	for (int i = 0; i < 10; ++i)
	{
		truckCase.push_back(10);
	}

	answer = solution(100, 100, truckCase);

	std::cout << answer << "\n";

	getchar();

	return 0;
}