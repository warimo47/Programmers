#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
	vector<int> answer;

	answer.push_back(0);
	answer.push_back(0);

	int oCount = 0;

	for (int i = 0; i < lottos.size(); ++i)
	{
		if (lottos[i] == 0) oCount++;
	}

	int minMatch = 0;

	for (int j = 0; j < lottos.size(); ++j)
	{
		for (int i = 0; i < win_nums.size(); ++i)
		{
			if (lottos[j] == win_nums[i])
			{
				minMatch++;
			}
		}
	}

	answer[1] = 7 - minMatch;
	answer[0] = answer[1] - oCount;
	if (answer[1] > 6) answer[1] = 6;
	if (answer[0] > 6) answer[0] = 6;

	return answer;
}

int main()
{
	vector<int> answer = solution({ 44, 1, 0, 0, 31, 25 }, { 31, 10, 45, 1, 6, 19 });

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << " ";
	}

	cout << "\n\n";

	answer = solution({ 0, 0, 0, 0, 0, 0 }, { 38, 19, 20, 40, 15, 25 });

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << " ";
	}

	cout << "\n\n";

	answer = solution({ 45, 4, 35, 20, 3, 9 }, { 20, 9, 3, 45, 4, 35 });

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << " ";
	}

	cout << "\n\n";

	getchar();

	return 0;
}