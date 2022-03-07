#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int checkPoint(vector<vector<int>> grid)
{
	int point = 0;

	if (grid[0][0] == 1)
		point++;
	if (grid[0][1] == 1)
		point++;
	if (grid[0][2] == 2)
		point++;
	if (grid[0][3] == 2)
		point++;
	if (grid[1][0] == 1)
		point++;
	if (grid[1][1] == 1)
		point++;
	if (grid[1][2] == 2)
		point++;
	if (grid[1][3] == 2)
		point++;
	if (grid[2][0] == 2)
		point++;
	if (grid[2][1] == 2)
		point++;
	if (grid[2][2] == 1)
		point++;
	if (grid[2][3] == 1)
		point++;
	if (grid[3][0] == 2)
		point++;
	if (grid[3][1] == 2)
		point++;
	if (grid[3][2] == 1)
		point++;
	if (grid[3][3] == 1)
		point++;

	return point;
}

vector<vector<int>> tryRotate(vector<vector<int>> grid, int maxPoint)
{
	vector<vector<int>> newGrid;
	vector<vector<int>> saveGrid;
	int temp = 0;
	int newPoint = 0;

	for (int i = 1; i < 17; ++i)
	{
		newGrid = grid;

		switch (i)
		{
		case 1:
			temp = newGrid[0][3];
			newGrid[0][3] = newGrid[0][2];
			newGrid[0][2] = newGrid[0][1];
			newGrid[0][1] = newGrid[0][0];
			newGrid[0][0] = temp;
			break;
		case 2:
			temp = newGrid[1][3];
			newGrid[1][3] = newGrid[1][2];
			newGrid[1][2] = newGrid[1][1];
			newGrid[1][1] = newGrid[1][0];
			newGrid[1][0] = temp;
			break;
		case 3:
			temp = newGrid[2][3];
			newGrid[2][3] = newGrid[2][2];
			newGrid[2][2] = newGrid[2][1];
			newGrid[2][1] = newGrid[2][0];
			newGrid[2][0] = temp;
			break;
		case 4:
			temp = newGrid[3][3];
			newGrid[3][3] = newGrid[3][2];
			newGrid[3][2] = newGrid[3][1];
			newGrid[3][1] = newGrid[3][0];
			newGrid[3][0] = temp;
			break;
		case 5:
			temp = newGrid[3][0];
			newGrid[3][0] = newGrid[2][0];
			newGrid[2][0] = newGrid[1][0];
			newGrid[1][0] = newGrid[0][0];
			newGrid[0][0] = temp;
			break;
		case 6:
			temp = newGrid[3][1];
			newGrid[3][1] = newGrid[2][1];
			newGrid[2][1] = newGrid[1][1];
			newGrid[1][1] = newGrid[0][1];
			newGrid[0][1] = temp;
			break;
		case 7:
			temp = newGrid[3][2];
			newGrid[3][2] = newGrid[2][2];
			newGrid[2][2] = newGrid[1][2];
			newGrid[1][2] = newGrid[0][2];
			newGrid[0][2] = temp;
			break;
		case 8:
			temp = newGrid[3][3];
			newGrid[3][3] = newGrid[2][3];
			newGrid[2][3] = newGrid[1][3];
			newGrid[1][3] = newGrid[0][3];
			newGrid[0][3] = temp;
			break;
		case 9:
			temp = newGrid[0][0];
			newGrid[0][0] = newGrid[0][1];
			newGrid[0][1] = newGrid[0][2];
			newGrid[0][2] = newGrid[0][3];
			newGrid[0][3] = temp;
			break;
		case 10:
			temp = newGrid[1][0];
			newGrid[1][0] = newGrid[1][1];
			newGrid[1][1] = newGrid[1][2];
			newGrid[1][2] = newGrid[1][3];
			newGrid[1][3] = temp;
			break;
		case 11:
			temp = newGrid[2][0];
			newGrid[2][0] = newGrid[2][1];
			newGrid[2][1] = newGrid[2][2];
			newGrid[2][2] = newGrid[2][3];
			newGrid[2][3] = temp;
			break;
		case 12:
			temp = newGrid[3][0];
			newGrid[3][0] = newGrid[3][1];
			newGrid[3][1] = newGrid[3][2];
			newGrid[3][2] = newGrid[3][3];
			newGrid[3][3] = temp;
			break;
		case 13:
			temp = newGrid[0][0];
			newGrid[0][0] = newGrid[1][0];
			newGrid[1][0] = newGrid[2][0];
			newGrid[2][0] = newGrid[3][0];
			newGrid[3][0] = temp;
			break;
		case 14:
			temp = newGrid[0][1];
			newGrid[0][1] = newGrid[1][1];
			newGrid[1][1] = newGrid[2][1];
			newGrid[2][1] = newGrid[3][1];
			newGrid[3][1] = temp;
			break;
		case 15:
			temp = newGrid[0][2];
			newGrid[0][2] = newGrid[1][2];
			newGrid[1][2] = newGrid[2][2];
			newGrid[2][2] = newGrid[3][2];
			newGrid[3][2] = temp;
			break;
		case 16:
			temp = newGrid[0][3];
			newGrid[0][3] = newGrid[1][3];
			newGrid[1][3] = newGrid[2][3];
			newGrid[2][3] = newGrid[3][3];
			newGrid[3][3] = temp;
			break;
		}

		newPoint = checkPoint(newGrid);

		if (maxPoint <= newPoint)
		{
			maxPoint = newPoint;
			saveGrid = newGrid;
		}
	}

	return saveGrid;
}

int solution(vector<vector<int>> grid)
{
	int answer = 0;

	int nowPoint = 0;

	vector<vector<int>> newGrid = grid;

	while (true)
	{
		nowPoint = checkPoint(newGrid);

		if (nowPoint == 16) break;

		newGrid = tryRotate(newGrid, nowPoint);
		answer++;
	}

	return answer;
}

int main()
{
	cout << solution({ {1, 1, 1, 1}, {2, 1, 2, 2}, {2, 2, 2, 1}, {1, 1, 2, 2} }) << "\n\n";

	cout << solution({ {1, 1, 1, 2}, {1, 1, 1, 2}, {2, 2, 2, 1}, {1, 2, 2, 2} }) << "\n\n";

	getchar();

	return 0;
}