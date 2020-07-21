#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles)
{
	vector<vector<int>> map;
	vector<int> subMap;
	subMap.resize(m, 0);
	map.resize(n, subMap);

	for (int i = 0; i < puddles.size(); ++i)
	{
		map[puddles[i][1] - 1][puddles[i][0] - 1] = -1;
	}

	for (int j = 0; j < n; ++j)
	{
		if (map[j][0] == -1) break;
		map[j][0] = 1;
	}

	for (int i = 0; i < m; ++i)
	{
		if (map[0][i] == -1) break;
		map[0][i] = 1;
	}

	for (int j = 1; j < n; ++j)
	{
		for (int i = 1; i < m; ++i)
		{
			if (map[j][i] == -1) continue;
			if ((map[j - 1][i] == -1) && (map[j][i - 1] == -1)) continue;
			else if (map[j - 1][i] == -1) map[j][i] = map[j][i - 1];
			else if (map[j][i - 1] == -1) map[j][i] = map[j - 1][i];
			else map[j][i] = map[j - 1][i] + map[j][i - 1];
		}
	}

	return map[n - 1][m - 1] % 1000000007;
}

int main()
{
	vector<vector<int>> puddles = { {2, 2} };

	std::cout << solution(4, 3, puddles) << " | 4" << std::endl;

	getchar();

	return 0;
}