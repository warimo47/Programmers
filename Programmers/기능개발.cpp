#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	int count = 0;
	int checkPosition = 0;

	for (int i = 0; i < progresses.size();)
	{
		if (progresses[i] > 99)
		{
			count++;
			i++;
		}
		else
		{
			if (count > 0)
			{
				answer.push_back(count);
				count = 0;
			}

			for (int j = i; j < progresses.size(); ++j)
			{
				progresses[j] += speeds[j];
			}
		}
	}

	if (count > 0)
	{
		answer.push_back(count);
		count = 0;
	}

	return answer;
}

int main()
{
	vector<int> progresses = { 93, 30, 55 };
	vector<int> speeds = { 1, 30, 5 };

	vector<int> answer;

	answer = solution(progresses, speeds);

	for (int count : answer)
	{
		std::cout << count << " ";
	}

	std::cout << "\n";

	getchar();
}