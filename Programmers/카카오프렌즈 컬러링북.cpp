#include <iostream>
#include <string>
#include <vector>

using namespace std;

void check(int y, int x, int m, int n, int color, vector<vector<bool>>* checkMap, vector<vector<int>>* pictureMap, int* size)
{
	if ((*checkMap)[y][x] == true) return;

	if ((*pictureMap)[y][x] != color) return;

	(*checkMap)[y][x] = true;
	(*size)++;

	if (-1 < y - 1)
	{
		check(y - 1, x, m, n, color, checkMap, pictureMap, size);
	}
	if (-1 < x - 1)
	{
		check(y, x - 1, m, n, color, checkMap, pictureMap, size);
	}
	if (y + 1 < m)
	{
		check(y + 1, x, m, n, color, checkMap, pictureMap, size);
	}
	if (x + 1 < n)
	{
		check(y, x + 1, m, n, color, checkMap, pictureMap, size);
	}
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	vector<bool> row;
	for (int i = 0; i < n; ++i) row.push_back(false);
	vector<vector<bool>> checkMap;
	for (int i = 0; i < m; ++i) checkMap.push_back(row);

	int size = 1;

	for (int j = 0; j < m; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			if (checkMap[j][i] == false && picture[j][i] != 0)
			{
				number_of_area++;
				size = 0;
				check(j, i, m, n, picture[j][i], &checkMap, &picture, &size);
				if (max_size_of_one_area < size) max_size_of_one_area = size;
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main()
{
	vector<int> answer = solution(6, 4, { {1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3} });

	cout << answer[0] << " " << answer[1] << " | 4 5\n\n";

	answer = solution(13, 14, { {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
								{0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
								{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
								{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}, 
								{1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1}, 
								{1, 1, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 1, 1},
								{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
								{1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1},
								{1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1},
								{0, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 0},
								{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}, 
								{0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0} });

	cout << answer[0] << " " << answer[1] << " | 12 120\n\n";

	answer = solution(2, 2, { { 1, 1 }, { 0, 1 } });

	cout << answer[0] << " " << answer[1] << " | 1 3\n\n";

	answer = solution(6, 4, { {1, 0, 0, 1}, {1, 0, 0, 1}, {1, 0, 0, 1}, {1, 0, 0, 1}, {1, 0, 0, 1}, {1, 1, 1, 1} });

	cout << answer[0] << " " << answer[1] << " | 1 14\n\n";

	answer = solution(1, 1, { { 0 } });

	cout << answer[0] << " " << answer[1] << " | 0 0\n\n";

	answer = solution(1, 1, { { 1 } });

	cout << answer[0] << " " << answer[1] << " | 1 1\n\n";

	answer = solution(4, 4, { {1, 1, 1, 1}, {1, 4, 1, 1}, {1, 3, 2, 1}, {1, 1, 1, 1} });

	cout << answer[0] << " " << answer[1] << " | 4 13\n\n";

	getchar();

	return 0;
}