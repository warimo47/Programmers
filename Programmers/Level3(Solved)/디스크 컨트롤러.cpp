#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs)
{
	int count = jobs.size();
	int totalWorkingTime = 0;
	int nowWorkingTime = 0;
	int sumWorkingTime = 0;

	int eraseCount = 0;

	vector<int> waitTime;

	waitTime.push_back(jobs[0][1]);
	jobs.erase(jobs.begin());

	while (waitTime.size() != 0)
	{
		nowWorkingTime = waitTime[0];
		sumWorkingTime += nowWorkingTime;

		totalWorkingTime += (nowWorkingTime * waitTime.size());

		for (vector<int> work : jobs)
		{
			if (sumWorkingTime >= work[0])
			{
				waitTime.push_back(work[1]);

				totalWorkingTime += (sumWorkingTime - work[0]);

				eraseCount++;
			}
		}

		for (int i = 0; i < eraseCount; ++i)
		{
			jobs.erase(jobs.begin());
		}
		eraseCount = 0;

		sort(waitTime.begin(), waitTime.end());

		waitTime.erase(waitTime.begin());
	}

	return totalWorkingTime / count;
}

int main()
{
	vector<vector<int>> jobs1 = { { 0, 3 }, { 1, 9 }, { 2, 6 } };

	cout << solution(jobs1) << "\n";

	vector<vector<int>> jobs2 = { { 0, 3 }, { 1, 9 }, { 2, 6 }, { 3, 1 } };

	cout << solution(jobs2) << "\n";

	getchar();

	return 0;
}