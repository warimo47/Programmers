#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> _stages)
{
	vector<int> answer;
	vector<pair<double, int>> failRate;

	double baseNum = static_cast<double>(_stages.size());
	double currentStageFailNum = 0.0;

	for (int i = 1; i < N + 1; ++i)
	{
		for (auto st : _stages)
		{
			if (st == i)
			{
				currentStageFailNum += 1.0;
			}
		}

		if (baseNum == 0.0) failRate.push_back(make_pair(0.0, i));
		else
		{
			failRate.push_back(make_pair(currentStageFailNum / baseNum, i));
			baseNum -= currentStageFailNum;
			currentStageFailNum = 0.0;
		}
	}

	sort(failRate.begin(), failRate.end(), [](pair<double, int> a, pair<double, int> b)
	{ if (a.first == b.first) return a.second < b.second;
	else return a.first > b.first; });

	for (auto fr : failRate)
	{
		answer.push_back(fr.second);
	}

	return answer;
}

int main()
{
	vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };

	vector<int> answer = solution(5, stages);

	for (auto ans : answer)
	{
		cout << ans << " ";
	}

	cout << "\n";

	stages = { 4, 4, 4, 4, 4 };

	answer = solution(4, stages);

	for (auto ans : answer)
	{
		cout << ans << " ";
	}

	cout << "\n";

	stages = { 2, 2, 2, 3, 4, 5, 6, 7 };

	answer = solution(8, stages);

	for (auto ans : answer)
	{
		cout << ans << " ";
	}

	cout << "\n";

	stages = { 1, 1, 2, 3, 4, 5, 6, 7 };

	answer = solution(20, stages);

	for (auto ans : answer)
	{
		cout << ans << " ";
	}

	cout << "\n";

	getchar();

	return 0;
}