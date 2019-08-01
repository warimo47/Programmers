#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> solution(int x, int n)
{
	vector<long long> answer;

	for (int i = 1; i <= n; ++i)
	{
		answer.push_back(i * x);
	}

	return answer;
}

int main()
{
	vector<long long> answer = solution(2, 5);

	for (long long ll : answer)
	{
		cout << ll << " ";
	}

	cout << "\n";

	answer = solution(4, 3);

	for (long long ll : answer)
	{
		cout << ll << " ";
	}

	cout << "\n";

	answer = solution(-4, 2);

	for (long long ll : answer)
	{
		cout << ll << " ";
	}

	cout << "\n";

	getchar();

	return 0;
}