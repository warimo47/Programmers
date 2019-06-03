#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights)
{
	vector<int> answer;

	bool check;
	answer.push_back(0);

	for (int i = 1; i < heights.size(); ++i)
	{
		check = true;

		for (int j = i - 1; j > -1; --j)
		{
			if (heights[i] < heights[j])
			{
				answer.push_back(j + 1);
				check = false;
				break;
			}
		}

		if (check) answer.push_back(0);
	}

	return answer;
}

int main()
{
	vector<int> heights = { 6,9,5,7,4 };
	vector<int> answer;

	answer = solution(heights);

	for (int h : answer)
	{
		cout << h << " ";
	}

	cout << "\n\n";

	heights = { 3, 9, 9, 3, 5, 7, 2 };
	answer = solution(heights);

	for (int h : answer)
	{
		cout << h << " ";
	}

	cout << "\n\n";

	heights = { 1, 5, 3, 6, 7, 6, 5 };
	answer = solution(heights);

	for (int h : answer)
	{
		cout << h << " ";
	}

	cout << "\n\n";

	heights = { 9, 5, 1, 4, 10, 6, 5 };
	answer = solution(heights);

	for (int h : answer)
	{
		cout << h << " ";
	}

	cout << "\n\n";

	getchar();

	return 0;
}