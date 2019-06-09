#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K)
{
	int answer = 0;

	sort(scoville.begin(), scoville.end());

	while (true)
	{
		if (scoville.size() < 2) return -1;

		if (scoville[0] > K && scoville[1] > K) break;

		if (scoville[0] > scoville[2]) scoville[1] = scoville[1] + scoville[2] * 2;
		else scoville[1] = scoville[0] + scoville[1] * 2;
		
		if (scoville.size() > 3)
		{
			if (scoville[1] > scoville[3])
			{
				scoville[0] = scoville[3];
				scoville[3] = scoville[1];
				scoville[1] = scoville[0];
			}
		}

		scoville.erase(scoville.begin());

		answer++;
	}

	return answer;
}

int main()
{
	vector<int> scoville = { 1, 2, 3, 9, 10, 12 };

	cout << solution(scoville, 7) << "\n\n";

	getchar();

	return 0;
}