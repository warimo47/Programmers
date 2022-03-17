#include <vector>
#include <string>
#include <iostream>

using namespace std;

long long getCount(int maxY, int maxX)
{
	vector<long long> temp;
	vector<vector<long long>> map;

	for (int i = 0; i < maxX + 1; ++i)
	{
		temp.push_back(0);
	}
	for (int i = 0; i < maxY + 1; ++i)
	{
		map.push_back(temp);
	}
	
	for (int i = 0; i < maxX + 1; ++i)
	{
		map[0][i] = 1;
	}
	for (int i = 1; i < maxY + 1; ++i)
	{
		map[i][0] = 1;
	}

	for (int y = 1; y < maxY + 1; ++y)
	{
		for (int x = 1; x < maxX + 1; ++x)
		{
			map[y][x] = map[y - 1][x] + map[y][x - 1];
		}
	}
	
	return map[maxY][maxX];
}

int solution(int width, int height, vector<vector<int>> diagonals)
{
	long long answer = 0;
	long long middle = 0;

	vector<vector<int>> map;

	for (vector<int> ds : diagonals)
	{
		middle = getCount(ds[0], ds[1] - 1) * getCount(height - ds[0], width - (ds[1] - 1));
		middle += getCount(ds[0] - 1, ds[1]) * getCount(height - (ds[0] - 1), width - ds[1]);
		answer = (answer + middle) % 10000019;
	}

	return answer;
}

int main()
{
	cout << solution(2, 2, { { 1, 1 }, { 2, 2 } }) << "\n\n";

	cout << solution(51, 37, { { 17, 19 } }) << "\n\n";

	getchar();

	return 0;
}