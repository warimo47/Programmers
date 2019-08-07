#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
	int answer = 1;
	int widSize = board[0].size();
	int heightSize = board.size();

	

	return answer;
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