#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int findMax(int a, int b, int c)
{
	if (a < b)
	{
		if (b <= c) return c;
		else return b;
	}
	else
	{
		if (a <= c) return c;
		else return a;
	}
}

int solution(vector<vector<int> > land)
{
	int answer = 0;
	int max1, max2;

	for (int i = 1; i < land.size(); ++i)
	{
		land[i][0] = land[i][0] + findMax(land[i - 1][1], land[i - 1][2], land[i - 1][3]);
		land[i][1] = land[i][1] + findMax(land[i - 1][0], land[i - 1][2], land[i - 1][3]);
		land[i][2] = land[i][2] + findMax(land[i - 1][0], land[i - 1][1], land[i - 1][3]);
		land[i][3] = land[i][3] + findMax(land[i - 1][0], land[i - 1][1], land[i - 1][2]);
	}

	land[land.size() - 1][0] > land[land.size() - 1][1] ? max1 = land[land.size() - 1][0] : max1 = land[land.size() - 1][1];
	land[land.size() - 1][2] > land[land.size() - 1][3] ? max2 = land[land.size() - 1][2] : max2 = land[land.size() - 1][3];
	max1 > max2 ? answer = max1 : answer = max2;

	return answer;
}

int main()
{
	vector<vector<int>> board;

	board = { { 1, 2, 3, 5 }, { 5, 6, 7, 8 }, { 4, 3, 2, 1 } };
	cout << solution(board) << "\n\n";

	getchar();

	return 0;
}