#include <vector>
#include <string>
#include <iostream>

using namespace std;

int rotate(vector<int> q, vector<vector<int>> *map)
{
	int temp = (*map)[q[0]][q[1]];
	int min = temp;

	for (int i = q[0]; i < q[2]; ++i)
	{
		if (min > (*map)[i + 1][q[1]]) min = (*map)[i + 1][q[1]];
		(*map)[i][q[1]] = (*map)[i + 1][q[1]];
	}

	for (int i = q[1]; i < q[3]; ++i)
	{
		if (min > (*map)[q[2]][i + 1]) min = (*map)[q[2]][i + 1];
		(*map)[q[2]][i] = (*map)[q[2]][i + 1];
	}

	for (int i = q[2]; i > q[0]; --i)
	{
		if (min > (*map)[i - 1][q[3]]) min = (*map)[i - 1][q[3]];
		(*map)[i][q[3]] = (*map)[i - 1][q[3]];
	}

	for (int i = q[3]; i > q[1] + 1; --i)
	{
		if (min > (*map)[q[0]][i - 1]) min = (*map)[q[0]][i - 1];
		(*map)[q[0]][i] = (*map)[q[0]][i - 1];
	}

	(*map)[q[0]][q[1] + 1] = temp;

	return min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
	vector<int> answer;

	vector<int> singleRow;
	vector<vector<int>> map;

	int count = 1;
	for (int r = 0; r < rows + 1; ++r)
	{
		for (int c = 0; c < columns + 1; ++c)
		{
			if (r == 0 || c == 0)
			{
				singleRow.push_back(0);
			}
			else
			{
				singleRow.push_back(count);
				count++;
			}
		}
		map.push_back(singleRow);
		singleRow.clear();
	}

	for (vector<int> q : queries)
	{
		answer.push_back(rotate(q, &map));
	}

	return answer;
}

int main()
{
	vector<int> answer = solution(6, 6, { { 2, 2, 5, 4 }, { 3, 3, 6, 6 }, { 5, 1, 6, 3 } });
	for (int a : answer)
	{
		cout << a << " ";
	}
	cout << "\n\n";

	answer = solution(3, 3, { { 1, 1, 2, 2 }, { 1, 2, 2, 3 }, { 2, 1, 3, 2 }, { 2, 2, 3, 3 } });
	for (int a : answer)
	{
		cout << a << " ";
	}
	cout << "\n\n";

	answer = solution(100, 97, { { 1, 1, 100, 97 } });
	for (int a : answer)
	{
		cout << a << " ";
	}
	cout << "\n\n";

	getchar();

	return 0;
}