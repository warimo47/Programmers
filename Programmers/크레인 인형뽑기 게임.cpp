#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> _board, vector<int> _moves)
{
	int answer = 0;

	vector<int> bucket = { 0 };

	for (auto m : _moves)
	{
		for (int i = 0; i < _board.size(); ++i)
		{
			if (_board[i][m - 1] == 0) continue;

			if (bucket[bucket.size() - 1] == _board[i][m - 1])
			{
				bucket.pop_back();
				answer += 2;
			}
			else
			{
				bucket.push_back(_board[i][m - 1]);
			}

			_board[i][m - 1] = 0;
			break;
		}
	}

	return answer;
}

int main()
{
	vector<vector<int>> board = { { 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 3 }, { 0, 2, 5, 0, 1 }, { 4, 2, 4, 4, 2 }, { 3, 5, 1, 3, 1 } };
	vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };

	cout << solution(board, moves) << "\n";
	

	getchar();

	return 0;
}