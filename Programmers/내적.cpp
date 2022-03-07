#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b)
{
	int answer = 0;

	for (int i = 0; i < a.size(); ++i)
	{
		answer += a[i] * b[i];
	}

	return answer;
}

int main()
{
	cout << solution({ 1, 2, 3, 4 }, { -3, -1, 0, 2 }) << "\n\n";

	cout << solution({ -1, 0, 1 }, { 1, 0, -1 }) << "\n\n";

	getchar();

	return 0;
}