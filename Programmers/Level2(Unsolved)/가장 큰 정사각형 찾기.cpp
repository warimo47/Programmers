#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b, int c)
{
	if (a > b)
	{
		if (b > c)
		{
			return c;
		}
		else
		{
			return b;
		}
	}
	else
	{
		if (a > c)
		{
			return c;
		}
		else
		{
			return a;
		}
	}
}

int solution(vector<vector<int>> board)
{
	int answer = 0;
	int widthSize = board[0].size();
	int heightSize = board.size();

	for (int j = 1; j < heightSize; ++j)
	{
		for (int i = 1; i < widthSize; ++i)
		{
			if (board[j][i] == 1)
			{
				board[j][i] = min(board[j - 1][i], board[j][i - 1], board[j - 1][i - 1]) + 1;
			}

			if (answer < board[j][i]) answer = board[j][i];
		}
	}

	return answer * answer;
}

int main()
{
	vector<vector<int>> board;

	board = { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 0, 0, 1, 0 } };
	cout << solution(board) << "\n\n";

	board = { { 0, 0, 1, 1 }, { 1, 1, 1, 1 } };
	cout << solution(board) << "\n\n";

	getchar();

	return 0;
}