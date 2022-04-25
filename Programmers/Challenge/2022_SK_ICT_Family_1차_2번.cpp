#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<vector<int>> solution(int n, bool clockwise)
{
	vector<vector<int>> answer;

	vector<int> inside;
	for (int i = 0; i < n; ++i)
	{
		inside.push_back(0);
	}
	for (int i = 0; i < n; ++i)
	{
		answer.push_back(inside);
	}

	vector<int> way = { 1, 2, 3, 4 };
	vector<int> yy = { 0, 0, n - 1, n - 1 };
	vector<int> xx = { 0, n - 1, n -1 , 0 };

	int count = 1;
	bool whileSkeepLoop = true;

	
	if (clockwise == false)
		way = { 2, 3, 4, 1 };

	while (whileSkeepLoop)
	{
		for (int index = 0; index < 4; ++index)
		{
			if (way[index] == 1)
			{
				if (answer[yy[index]][xx[index]] == 0)
				{
					answer[yy[index]][xx[index]] = count;
				}
				else
				{
					whileSkeepLoop = false;
					continue;
				}

				if (answer[yy[index]][xx[index] + 1] == 0)
				{
					xx[index]++;
				}
				else
				{
					if (clockwise)
					{
						way[index] = 2;
						yy[index]++;
					}
					else
					{
						way[index] = 4;
						yy[index]--;
					}
				}
			}
			else if (way[index] == 2)
			{
				if (answer[yy[index]][xx[index]] == 0)
				{
					answer[yy[index]][xx[index]] = count;
				}
				else
				{
					whileSkeepLoop = false;
					continue;
				}

				if (answer[yy[index] + 1][xx[index]] == 0)
				{
					yy[index]++;
				}
				else
				{
					if (clockwise)
					{
						way[index] = 3;
						xx[index]--;
					}
					else
					{
						way[index] = 1;
						xx[index]++;
					}
				}
			}
			else if (way[index] == 3)
			{
				if (answer[yy[index]][xx[index]] == 0)
				{
					answer[yy[index]][xx[index]] = count;
				}
				else
				{
					whileSkeepLoop = false;
					continue;
				}

				if (answer[yy[index]][xx[index] - 1] == 0)
				{
					xx[index]--;
				}
				else
				{
					if (clockwise)
					{
						way[index] = 4;
						yy[index]--;
					}
					else
					{
						way[index] = 2;
						yy[index]++;
					}
				}
			}
			else if (way[index] == 4)
			{
				if (answer[yy[index]][xx[index]] == 0)
				{
					answer[yy[index]][xx[index]] = count;
				}
				else
				{
					whileSkeepLoop = false;
					continue;
				}

				if (answer[yy[index] - 1][xx[index]] == 0)
				{
					yy[index]--;
				}
				else
				{
					if (clockwise)
					{
						way[index] = 1;
						xx[index]++;
					}
					else
					{
						way[index] = 3;
						xx[index]--;
					}
				}
			}
		}
		count++;
	}
	
	return answer;
}

int main()
{
	vector<vector<int>> answer = solution(5, true);
	for (vector<int> as : answer)
	{
		for (int a : as)
		{
			cout << a << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";

	answer = solution(6, false);
	for (vector<int> as : answer)
	{
		for (int a : as)
		{
			cout << a << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";

	answer = solution(9, false);
	for (vector<int> as : answer)
	{
		for (int a : as)
		{
			cout << a << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";

	getchar();

	return 0;
}