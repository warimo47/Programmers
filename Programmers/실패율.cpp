#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> _stages)
{
	vector<int> answer;

	for (int i = 1; i < N + 1; ++i)
	{

	}

	return answer;
}

int main()
{
	vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };

	vector<int> answer = solution(5, stages);

	for (auto ans : answer)
	{
		cout << ans << " ";
	}

	cout << "\n";

	stages = { 4, 4, 4, 4, 4 };

	answer = solution(4, stages);

	for (auto ans : answer)
	{
		cout << ans << " ";
	}

	cout << "\n";

	getchar();

	return 0;
}