#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(int h, int w, int n, vector<string> board)
{
	int answer = 0;

	vector<vector<int>> myBoard;

	vector<int> line;

	for (int i = 0; i < w + 2; ++i)
	{
		line.push_back(0);
	}

	for (int i = 0; i < h + 2; ++i)
	{
		myBoard.push_back(line);
	}

	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			if (board[i][j] == '1')
			{
				myBoard[i + 1][j + 1] = 1;
			}
			else
			{
				myBoard[i + 1][j + 1] = 0;
			}
		}
	}

	// 가로 확인
	int count = 0;

	for (int j = 1; j < myBoard.size(); ++j)
	{
		for (int i = 1; i < myBoard[j].size(); ++i)
		{
			if (myBoard[j][i] == 1)
			{
				count++;
			}
			else
			{
				if (count == n)
				{
					answer++;
				}
				count = 0;
			}
		}
	}

	// 세로 확인
	count = 0;

	for (int i = 1; i < myBoard[0].size(); ++i)
	{
		for (int j = 1; j < myBoard.size(); ++j)
		{
			if (myBoard[j][i] == 1)
			{
				count++;
			}
			else
			{
				if (count == n)
				{
					answer++;
				}
				count = 0;
			}
		}
	}

	// / 대각 확인
	bool check = false;

	for (int j = n; j < myBoard.size(); ++j)
	{
		for (int i = 0; i < myBoard[j].size() - n; ++i)
		{
			check = true;

			for (int k = 0; k < n + 2; ++k)
			{
				if ((k == 0) || (k == (n + 1)))
				{
					if (myBoard[j - k][i + k] != 0)
					{
						check = false;
						break;
					}
				}
				else
				{
					if (myBoard[j - k][i + k] != 1)
					{
						check = false;
						break;
					}
				}
			}

			if (check == true) answer++;
		}
	}

	// \ 대각 확인
	check = false;

	for (int j = 0; j < myBoard.size() - n; ++j)
	{
		for (int i = 0; i < myBoard[j].size() - n; ++i)
		{
			check = true;

			for (int k = 0; k < n + 2; ++k)
			{
				if ((k == 0) || (k == (n + 1)))
				{
					if (myBoard[j + k][i + k] != 0)
					{
						check = false;
						break;
					}
				}
				else
				{
					if (myBoard[j + k][i + k] != 1)
					{
						check = false;
						break;
					}
				}
			}

			if (check == true) answer++;
		}
	}

	return answer;
}

int main()
{
	cout << solution(7, 9, 4, { "111100000", "000010011", "111100011", "111110011", "111100011", "111100010", "111100000" }) << "\n\n";

	cout << solution(5, 5, 5, { "11111", "11111", "11111", "11111", "11111" }) << "\n\n";

	getchar();

	return 0;
}