#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;

	int firstNum = 0;

	for (int st : stations)
	{
		if (st - w - 1 - firstNum > 0)
		{
			if ((st - w - 1 - firstNum) % (w * 2 + 1) == 0)
			{
				answer += (st - w - 1 - firstNum) / (w * 2 + 1);
			}
			else
			{
				answer += (st - w - 1 - firstNum) / (w * 2 + 1) + 1;
			}
		}

		firstNum = st + w;
	}

	if (stations[stations.size() - 1] + w < n)
	{
		if ((n - stations[stations.size() - 1] - w) % (w * 2 + 1) == 0)
		{
			answer += (n - stations[stations.size() - 1] - w) / (w * 2 + 1);
		}
		else
		{
			answer += (n - stations[stations.size() - 1] - w) / (w * 2 + 1) + 1;
		}
	}

	return answer;
}

int main()
{
	vector<int> stations;

	stations = { 4, 11 };
	cout << solution(11, stations, 1) << "\n\n";

	stations = { 9 };
	cout << solution(16, stations, 2) << "\n\n";

	getchar();

	return 0;
}