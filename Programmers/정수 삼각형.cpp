#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int solution(vector<vector<int>> triangle)
{
	int answer = triangle[0][0];

	for (int level = 1; level < triangle.size(); ++level)
	{
		for (int step = 0; step < triangle[level].size(); ++step)
		{
			if (step == 0) triangle[level][step] += triangle[level - 1][step];
			else if (step == triangle[level].size() - 1) triangle[level][step] += triangle[level - 1][step - 1];
			else
			{
				if (triangle[level - 1][step - 1] < triangle[level - 1][step])
					triangle[level][step] += triangle[level - 1][step];
				else
					triangle[level][step] += triangle[level - 1][step - 1];
			}

			if (answer < triangle[level][step])
				answer = triangle[level][step];
		}
	}

	return answer;
}

int main()
{
	vector<vector<int>> triangle = { { 7 }, { 3, 8 }, { 8, 1, 0 }, { 2, 7, 4, 4 }, { 4, 5, 2, 6, 5 } };

	std::cout << solution(triangle) << " | 30" << std::endl;

	getchar();

	return 0;
}