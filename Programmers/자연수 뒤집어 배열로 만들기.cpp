#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(long long n)
{
	vector<int> answer;

	while (n)
	{
		answer.push_back(n % 10);
		n = n / 10;
	}

	return answer;
}

int main()
{
	vector<int> answer = solution(12345);

	for (int an : answer)
	{
		cout << an << " ";
	}

	cout << "\n";

	getchar();

	return 0;
}