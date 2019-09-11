#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> office, int k)
{
	int answer = 0;
	int len = office.size();
	int count = 0;
	
	for (int j = 0; j < len - k + 1; ++j)
	{
		for (int i = 0; i < len - k + 1; ++i)
		{
			count = 0;

			for (int y = j; y < j + k; ++y)
			{
				for (int x = i; x < i + k; ++x)
				{
					count += office[y][x];
				}
			}

			if (answer < count) answer = count;
		}
	}

	return answer;
}

int main()
{
	vector<vector<int>> office;

	office = { {1, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 1, 1, 0} };

	cout << solution(office, 2) << "\n";

	office = { {1, 0, 0}, {0, 0, 1}, {1, 0, 0} };

	cout << solution(office, 2) << "\n";


	getchar();

	return 0;
}